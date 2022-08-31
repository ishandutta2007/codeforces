#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


const int A_MAX = int(1e6) + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> my_primes(N);
    map<vector<int>, int> freq;

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++) {
        int x = A[i];

        while (x > 1) {
            int p = smallest_factor[x];
            int e = 0;

            do {
                x /= p;
                e++;
            } while (x % p == 0);

            if (e % 2 != 0)
                my_primes[i].push_back(p);
        }

        freq[my_primes[i]]++;
    }

    int zero = 0, one = 0;
    int collapse = freq[{}];

    for (auto &pr : freq) {
        zero = max(zero, pr.second);

        if (pr.second % 2 != 0)
            one = max(one, pr.second);
        else if (!pr.first.empty())
            collapse += pr.second;
    }

    one = max(one, collapse);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int64_t w;
        cin >> w;
        cout << (w == 0 ? zero : one) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    sieve(A_MAX);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}