#include <algorithm>
#include <array>
#include <bitset>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N;
    cin >> N;
    int64_t start = INF64, end = -INF64;
    int64_t cheapest_start = INF64, cheapest_end = INF64, cheapest_both = INF64;

    for (int i = 0; i < N; i++) {
        int64_t L, R, c;
        cin >> L >> R >> c;

        if (L < start) {
            start = L;
            cheapest_start = c;
            cheapest_both = INF64;
        } else if (L == start) {
            cheapest_start = min(cheapest_start, c);
        }

        if (R > end) {
            end = R;
            cheapest_end = c;
            cheapest_both = INF64;
        } else if (R == end) {
            cheapest_end = min(cheapest_end, c);
        }

        if (L == start && R == end)
            cheapest_both = min(cheapest_both, c);

        cout << min(cheapest_start + cheapest_end, cheapest_both) << '\n';
    }
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