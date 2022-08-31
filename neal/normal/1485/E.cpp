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


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);

    for (int i = 1; i < N; i++) {
        int v;
        cin >> v;
        v--;
        adj[v].push_back(i);
        adj[i].push_back(v);
    }

    vector<int> depth(N);
    vector<vector<int>> level(N);

    y_combinator([&](auto dfs, int node, int parent) -> void {
        depth[node] = parent < 0 ? 0 : depth[parent] + 1;
        level[depth[node]].push_back(node);

        for (int neigh : adj[node])
            if (neigh != parent)
                dfs(neigh, node);
    })(0, -1);

    vector<int64_t> A(N, 0);

    for (int i = 1; i < N; i++)
        cin >> A[i];

    vector<int64_t> dp(N, 0);
    int64_t best = 0;

    for (int d = 0; d < N; d++) {
        // Transition between nodes at d
        vector<pair<int64_t, int64_t>> choices;

        for (int node : level[d])
            choices.emplace_back(A[node], dp[node]);

        sort(choices.begin(), choices.end());
        int C = int(choices.size());
        vector<int64_t> prefix_max(C + 1, -INF64);
        vector<int64_t> suffix_max(C + 1, -INF64);

        for (int i = 0; i < C; i++)
            prefix_max[i + 1] = max(prefix_max[i], choices[i].second - choices[i].first);

        for (int i = C - 1; i >= 0; i--)
            suffix_max[i] = max(suffix_max[i + 1], choices[i].second + choices[i].first);

        int64_t minimum = INF64, maximum = -INF64;

        for (int node : level[d]) {
            minimum = min(minimum, A[node]);
            maximum = max(maximum, A[node]);
        }

        for (int node : level[d]) {
            int index = int(lower_bound(choices.begin(), choices.end(), make_pair(A[node], INT64_C(0))) - choices.begin());
            dp[node] = max({dp[node] + maximum - A[node], dp[node] + A[node] - minimum, prefix_max[index] + A[node], suffix_max[index] - A[node]});
            best = max(best, dp[node]);
        }

        // Transition from d to d + 1
        for (int node : level[d])
            for (int neigh : adj[node])
                if (depth[neigh] > depth[node])
                    dp[neigh] = max(dp[neigh], dp[node]);
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