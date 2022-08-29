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

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    vector<pair<int64_t, int>> maxes;

    for (int i = 0; i <= N; i++)
        if (maxes.empty() || prefix_sum[i] > maxes.back().first)
            maxes.emplace_back(prefix_sum[i], i);

    for (int q = 0; q < M; q++) {
        int64_t x;
        cin >> x;
        int64_t ans = 0;

        if (maxes.back().first >= x) {
            ans = lower_bound(maxes.begin(), maxes.end(), make_pair(x, 0))->second;
        } else if (prefix_sum[N] > 0) {
            int64_t full = ceil_div(x - maxes.back().first, prefix_sum[N]);
            x -= full * prefix_sum[N];
            assert(x <= maxes.back().first);
            ans = lower_bound(maxes.begin(), maxes.end(), make_pair(x, 0))->second;
            ans += full * N;
        }

        cout << ans - 1 << (q < M - 1 ? ' ' : '\n');
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