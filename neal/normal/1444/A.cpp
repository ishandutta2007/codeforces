#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Prime factorizes n in worst case O(sqrt n).
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    assert(n >= 1);
    vector<pair<int64_t, int>> result;

    for (int64_t p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}


int get_multiplicity(int64_t n, int64_t p) {
    int m = 0;

    while (n % p == 0) {
        m++;
        n /= p;
    }

    return m;
}

void run_case() {
    int64_t P, Q;
    cin >> P >> Q;
    auto prime_factors = prime_factorize(Q);
    int64_t best = 1;

    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
        int mult = get_multiplicity(P, p);
        int64_t candidate = P;

        while (mult >= pf.second) {
            candidate /= p;
            mult--;
        }

        best = max(best, candidate);
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}