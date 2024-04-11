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


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int64_t N, K;
    cin >> N >> K;
    int64_t L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    int64_t intersect = max(min(R1, R2) - max(L1, L2), INT64_C(0));
    int64_t already = N * intersect;

    if (already >= K) {
        cout << 0 << '\n';
        return;
    }

    K -= already;

    int64_t gap = max(max(L1, L2) - min(R1, R2), INT64_C(0));
    int64_t one = gap + (R1 - L1) + (R2 - L2) - 2 * intersect;
    int64_t best = INF64;

    for (int64_t take = 1; take <= N; take++) {
        int64_t get = one * take;
        int64_t time = (gap + one) * take;

        if (get > K) {
            time -= min(get - K, one);
            best = min(best, time);
            continue;
        }

        time += 2 * (K - get);
        best = min(best, time);
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