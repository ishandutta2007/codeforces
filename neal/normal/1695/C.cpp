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


const int INF = int(1e9) + 5;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    for (auto &row : A)
        for (auto &a : row)
            cin >> a;

    vector<vector<int>> min_dp(N, vector<int>(M, INF)), max_dp(N, vector<int>(M, -INF));
    min_dp[0][0] = max_dp[0][0] = A[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (i > 0) {
                min_dp[i][j] = min(min_dp[i][j], min_dp[i - 1][j] + A[i][j]);
                max_dp[i][j] = max(max_dp[i][j], max_dp[i - 1][j] + A[i][j]);
            }

            if (j > 0) {
                min_dp[i][j] = min(min_dp[i][j], min_dp[i][j - 1] + A[i][j]);
                max_dp[i][j] = max(max_dp[i][j], max_dp[i][j - 1] + A[i][j]);
            }
        }

    cout << ((N + M) % 2 != 0 && min_dp[N - 1][M - 1] <= 0 && 0 <= max_dp[N - 1][M - 1] ? "YES" : "NO") << '\n';
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