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


int64_t lcm(int64_t a, int64_t b) {
    return a / __gcd(a, b) * b;
}

void run_case() {
    int64_t n;
    cin >> n;
    vector<int64_t> factors;

    for (int64_t x = 1; x * x <= n; x++)
        if (n % x == 0) {
            factors.push_back(x);
            factors.push_back(n / x);
        }

    int64_t best = 1e18;
    int64_t best_x = -1;

    for (int64_t x : factors) {
        if (x == n)
            continue;

        int64_t option = lcm(x, n - x);

        if (option < best) {
            best = option;
            best_x = x;
        }
    }

    cout << best_x << ' ' << n - best_x << '\n';
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