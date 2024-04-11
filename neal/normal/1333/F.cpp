#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int64_t p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


int N;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    sieve(N);
    vector<int> largest(N + 1, 0);
    vector<bool> included(N + 1, false);

    for (int i = 1; i <= N; i++)
        if (i == 1 || prime[i]) {
            included[i] = true;
            largest[1]++;
        }

    for (int i = 2; i <= N; i++) {
        largest[i] = largest[i - 1];

        for (int x = 1; x <= smallest_factor[i] && x * i <= N; x++)
            if (x == 1 || prime[x]) {
                int candidate = x * i;

                if (!included[candidate]) {
                    included[candidate] = true;
                    largest[i]++;
                }
            }
    }

    int answer = 0;

    for (int i = 2; i <= N; i++) {
        while (largest[answer] < i)
            answer++;

        cout << answer << (i < N ? ' ' : '\n');
    }
}