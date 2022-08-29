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

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (T1(b) < a) {
        a = T1(b);
        return true;
    }

    return false;
}


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int64_t> X(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> X[i];

    vector<set<int>> relevant(N + 1);
    relevant[1].insert(1);
    relevant[N].insert(M);
    vector<vector<array<int, 4>>> ladders(N + 1);

    for (int i = 0; i < K; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        ladders[a].push_back({b, c, d, h});
        relevant[a].insert(b);
        relevant[c].insert(d);
    }

    vector<map<int, int64_t>> dist(N + 1);

    for (int floor = 1; floor <= N; floor++)
        for (int col : relevant[floor])
            dist[floor][col] = INF64;

    dist[1][1] = 0;

    for (int floor = 1; floor <= N; floor++) {
        vector<int> columns(relevant[floor].begin(), relevant[floor].end());
        int C = int(columns.size());
        int64_t minimum = INF64;

        for (int i = 0; i < C; i++) {
            int col = columns[i];
            minimize(dist[floor][col], minimum);
            minimize(minimum, dist[floor][col]);

            if (i < C - 1)
                minimum += X[floor] * (columns[i + 1] - col);
        }

        minimum = INF64;

        for (int i = C - 1; i >= 0; i--) {
            int col = columns[i];
            minimize(dist[floor][col], minimum);
            minimize(minimum, dist[floor][col]);

            if (i > 0)
                minimum += X[floor] * (col - columns[i - 1]);
        }

        for (auto &ladder : ladders[floor]) {
            int col = ladder[0];
            int nfloor = ladder[1];
            int ncol = ladder[2];
            int health = ladder[3];
            minimize(dist[nfloor][ncol], dist[floor][col] - health);
        }
    }

    if (dist[N][M] >= INF64 / 2) {
        cout << "NO ESCAPE" << '\n';
        return;
    }

    cout << dist[N][M] << '\n';
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