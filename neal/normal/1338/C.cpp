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


int64_t get(int64_t n) {
    int mod = n % 3;
    n /= 3;
    int64_t p = 1;

    while (n >= p) {
        n -= p;
        p *= 4;
    }

    if (mod == 0) {
        return p + n;
    } else if (mod == 1) {
        for (int bit = 0; 1LL << (2 * bit) < p; bit++) {
            int digit4 = n >> (2 * bit) & 3;

            if (digit4 == 3)
                n -= 2LL << (2 * bit);
            else if (digit4 == 1 || digit4 == 2)
                n += 1LL << (2 * bit);
        }

        return 2 * p + n;
    } else if (mod == 2) {
        for (int bit = 0; 1LL << (2 * bit) < p; bit++) {
            int digit4 = n >> (2 * bit) & 3;

            if (digit4 == 1)
                n += 2LL << (2 * bit);
            else if (digit4 == 2 || digit4 == 3)
                n -= 1LL << (2 * bit);
        }

        return 3 * p + n;
    } else {
        assert(false);
    }
}

void run_case() {
    int64_t n;
    cin >> n;
    cout << get(n - 1) << '\n';
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