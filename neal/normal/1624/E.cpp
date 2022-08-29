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
    vector<string> knows(N);

    for (auto &str : knows)
        cin >> str;

    array<vector<pair<int, int>>, 4> where;
    where[2].assign(100, {-1, -1});
    where[3].assign(1000, {-1, -1});

    for (int i = 0; i < N; i++)
        for (int x = 0; x + 2 <= M; x++) {
            where[2][stoi(knows[i].substr(x, 2))] = {i, x};

            if (x + 3 <= M)
                where[3][stoi(knows[i].substr(x, 3))] = {i, x};
        }

    string goal;
    cin >> goal;
    vector<bool> dp(M + 1, false);
    vector<int> take_len(M + 1, -1);
    vector<pair<int, int>> take(M + 1, {-1, -1});
    dp[M] = true;

    for (int x = M - 2; x >= 0; x--)
        for (int len = 2; len <= 3; len++) {
            if (x + len > M)
                continue;

            int need = stoi(goal.substr(x, len));

            if (dp[x + len] && where[len][need].first >= 0) {
                dp[x] = true;
                take_len[x] = len;
                take[x] = where[len][need];
            }
        }

    if (!dp[0]) {
        cout << -1 << '\n';
        return;
    }

    vector<array<int, 3>> solution;
    int x = 0;

    while (x < M) {
        int len = take_len[x];
        solution.push_back({take[x].second, take[x].second + len, take[x].first});
        x += len;
    }

    cout << solution.size() << '\n';

    for (auto &section : solution)
        cout << section[0] + 1 << ' ' << section[1] << ' ' << section[2] + 1 << '\n';
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