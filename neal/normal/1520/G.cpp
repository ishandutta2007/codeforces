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

const int INF = int(1e9) + 5;

const int DIRS = 4;
const int DR[DIRS] = {-1,  0, +1,  0};
const int DC[DIRS] = { 0, +1,  0, -1};

// const int DIRS = 8;
// const int DR[DIRS] = {-1, -1, -1,  0, +1, +1, +1,  0};
// const int DC[DIRS] = {-1,  0, +1, +1, +1,  0, -1, -1};

struct state {
    int row = -1, col = -1;

    state() {}

    state(int _row, int _col) : row(_row), col(_col) {}
};

template<typename T_row>
struct grid_bfs {
    int R, C;
    vector<T_row> grid;
    vector<vector<int>> dist;

    grid_bfs(const vector<T_row> &_grid = {}) {
        init(_grid);
    }

    void init(const vector<T_row> &_grid = {}) {
        grid = _grid;
        R = int(grid.size());
        C = grid.empty() ? 0 : int(grid[0].size());
    }

    bool valid(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }

    void bfs_check(queue<state> &q, queue<state> &next_q, const state &s, int new_dist, int add) {
        assert(add == 0 || add == 1);

        if (new_dist < dist[s.row][s.col]) {
            dist[s.row][s.col] = new_dist;
            (add == 0 ? q : next_q).push(s);
        }
    }

    void bfs(const vector<state> &source) {
        if (R == 0 || C == 0) return;

        // Two queues are needed for 0-1 BFS.
        queue<state> q, next_q;
        dist.assign(R, vector<int>(C, INF));

        for (const state &src : source)
            bfs_check(q, next_q, src, 0, 0);

        int level = 0;

        while (!q.empty() || !next_q.empty()) {
            while (!q.empty()) {
                state top = q.front(); q.pop();
                int r = top.row, c = top.col;

                if (level > dist[r][c])
                    continue;

                for (int dir = 0; dir < DIRS; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];

                    if (valid(nr, nc) && grid[nr][nc] >= 0) {
                        int add = 1;
                        bfs_check(q, next_q, state(nr, nc), dist[r][c] + add, add);
                    }
                }
            }

            swap(q, next_q);
            level++;
        }
    }
};


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    int64_t W;
    cin >> N >> M >> W;
    vector<vector<int>> grid(N, vector<int>(M));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> grid[r][c];

    grid_bfs bfs(grid);
    grid.clear();
    bfs.bfs(vector<state>(1, {0, 0}));
    int64_t answer = bfs.dist[N - 1][M - 1] < INF ? bfs.dist[N - 1][M - 1] * W : INF64;
    int64_t source_best = INF64, target_best = INF64;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (bfs.grid[r][c] > 0 && bfs.dist[r][c] < INF)
                source_best = min(source_best, bfs.grid[r][c] + W * bfs.dist[r][c]);

    bfs.bfs(vector<state>(1, {N - 1, M - 1}));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (bfs.grid[r][c] > 0 && bfs.dist[r][c] < INF)
                target_best = min(target_best, bfs.grid[r][c] + W * bfs.dist[r][c]);

    answer = min(answer, source_best + target_best);
    cout << (answer < INF64 / 2 ? answer : -1) << '\n';
}