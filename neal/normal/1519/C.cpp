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


void run_case() {
    int N;
    cin >> N;
    vector<int> U(N);
    vector<int64_t> S(N);

    for (auto &u : U) {
        cin >> u;
        u--;
    }

    for (auto &s : S)
        cin >> s;

    vector<vector<int64_t>> choices(N + 1);

    for (int i = 0; i < N; i++)
        choices[U[i]].push_back(S[i]);

    vector<int64_t> skill(N + 1, 0);

    for (int u = 0; u < N; u++) {
        sort(choices[u].begin(), choices[u].end());
        int len = int(choices[u].size());
        vector<int64_t> prefix_sum(len + 1, 0);

        for (int i = 0; i < len; i++)
            prefix_sum[i + 1] = prefix_sum[i] + choices[u][i];

        for (int k = 1; k <= len; k++)
            skill[k] += prefix_sum[len] - prefix_sum[len % k];
    }

    for (int k = 1; k <= N; k++)
        cout << skill[k] << (k < N ? ' ' : '\n');
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