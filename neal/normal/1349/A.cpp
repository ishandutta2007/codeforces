#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}


const int A_MAX = 5e5 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    sieve(A_MAX);

    int N;
    cin >> N;
    vector<int> A(N);
    map<int64_t, vector<int>> exponents;

    for (int &a : A) {
        cin >> a;
        vector<pair<int64_t, int>> prime_factors = prime_factorize(a);

        for (auto &pf : prime_factors)
            exponents[pf.first].push_back(pf.second);
    }

    int64_t answer = 1;

    for (int p = 2; p < A_MAX; p++)
        if (prime[p] && int(exponents[p].size()) >= N - 1) {
            sort(exponents[p].begin(), exponents[p].end());
            int exponent;

            if (int(exponents[p].size()) == N)
                exponent = exponents[p][1];
            else
                exponent = exponents[p][0];

            for (int e = 0; e < exponent; e++)
                answer *= p;
        }

    cout << answer << '\n';
}