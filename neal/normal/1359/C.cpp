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


void run_case() {
    int64_t H, C, T;
    cin >> H >> C >> T;
    int64_t n = T - C, d = H - C;

    if (2 * n <= d) {
        cout << 2 << '\n';
        return;
    }

    // n / d - 1 / 2 = (2n - d) / (2d)
    n = 2 * n - d;
    assert(n > 0 && n <= d);

    // We want to approximate n / (2d) with 1 / (2k) where k is odd.
    int64_t k = d / n;
    int64_t k2 = (d + n - 1) / n;

    if (k % 2 == 0)
        k--;

    if (k2 % 2 == 0)
        k2++;

    if (k != k2) {
        assert(k2 == k + 2);

        // Average of 1 / k and 1 / k2 is (k + k2) / (2 * k * k2)
        if (n * (2 * k * k2) < (k + k2) * d)
            k = k2;
    }

    cout << k << '\n';
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