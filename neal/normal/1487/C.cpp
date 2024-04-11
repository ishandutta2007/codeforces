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
    vector<vector<int>> adj(N, vector<int>(N, 0));

    auto set_edge = [&](int a, int b, int win) {
        adj[a][b] = win;
        adj[b][a] = -win;
    };

    auto get_sum = [&](int a) {
        return accumulate(adj[a].begin(), adj[a].end(), 0);
    };

    if (N % 2 == 0) {
        for (int i = 0; i < N; i += 2)
            set_edge(i, (i + 1) % N, 0);

        if (N % 4 != 0) {
            for (int i = 1; i < N; i += 2)
                set_edge(i, (i + 1) % N, 1);

            for (int i = 0; i < N; i += 2)
                set_edge(i, (i + N / 2) % N, 1);
        } else {
            for (int i = 1; i < N; i += 2)
                set_edge(i, (i + 1) % N, i < N / 2 ? 1 : -1);

            for (int i = 0; i < N / 2; i++) {
                int sum = get_sum(i);
                assert(sum != 0 && get_sum(i + N / 2) == -sum);
                set_edge(i, i + N / 2, sum < 0 ? 1 : -1);
            }
        }
    } else {
        for (int i = 0; i < N; i++)
            set_edge(i, (i + 1) % N, 1);
    }

    if (N == 2)
        set_edge(0, 1, 0);

    for (int len = 2; len <= (N - 1) / 2; len++) {
        for (int i = 0; i < N; i++)
            set_edge(i, (i + len) % N, 1);
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            cout << adj[i][j] << ' ';

    cout << '\n';

    for (int i = 0; i < N; i++)
        assert(get_sum(i) == 0);
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