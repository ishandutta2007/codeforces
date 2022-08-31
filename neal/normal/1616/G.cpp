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


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 2);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        adj[0].push_back(i);
        adj[i].push_back(N + 1);
    }

    vector<bool> has_edge(N + 2, false);

    for (int i = 0; i <= N + 1; i++)
        for (int j : adj[i])
            has_edge[i] = has_edge[i] || j == i + 1;

    vector<int> reaches(N + 2);

    for (int i = N + 1; i >= 0; i--)
        reaches[i] = has_edge[i] ? reaches[i + 1] : i;

    if (reaches[1] >= N) {
        cout << N * (N - 1LL) / 2 << '\n';
        return;
    }

    int cutoff = N + 1;

    for (int i = N; i >= 0; i--)
        if (reaches[i] >= N)
            cutoff = i;

    vector<array<int, 2>> dp(N + 2, {0, 0});
    dp[cutoff] = {1, 2};

    for (int i = cutoff; i <= N + 1; i++)
        for (int j : adj[i - 1])
            if (j > i && reaches[i] >= j - 1)
                for (int p = 0; p <= 1; p++)
                    dp[j][!p] |= dp[i][p];

    array<int, 4> counts = {0, 0, 0, 0};

    for (int i = cutoff; i <= N + 1; i++)
        if (reaches[i] >= N) {
            bool has0 = dp[i][0] & 1;
            bool has1 = dp[i][0] & 2;
            counts[1] += has0;
            counts[2] += has1;
            counts[3] += has0 || has1;
        }

    for (int i = cutoff - 1; i > 0; i--)
        for (int j : adj[i - 1])
            if (j > i && reaches[i] >= j - 1)
                for (int p = 0; p <= 1; p++)
                    dp[i][p] |= dp[j][!p];

    int64_t total = 0;

    for (int i = 1; i <= cutoff; i++)
        if (reaches[1] >= i - 1)
            total += counts[dp[i][0]] - (i == cutoff);

    cout << total << '\n';
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