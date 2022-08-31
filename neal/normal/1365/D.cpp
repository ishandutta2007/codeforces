#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = 1e9 + 5;

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
    vector<vector<state>> parent;

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

    void bfs_check(queue<state> &q, queue<state> &next_q, const state &s, const state &from_s, int new_dist, int add) {
        assert(add == 0 || add == 1);

        if (new_dist < dist[s.row][s.col]) {
            dist[s.row][s.col] = new_dist;
            parent[s.row][s.col] = from_s;
            (add == 0 ? q : next_q).push(s);
        }
    }

    void bfs(const vector<state> &source) {
        if (R == 0 || C == 0) return;

        // Two queues are needed for 0-1 BFS.
        queue<state> q, next_q;
        dist.assign(R, vector<int>(C, INF));
        parent.assign(R, vector<state>(C, state()));

        for (const state &src : source)
            bfs_check(q, next_q, src, state(), 0, 0);

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

                    if (valid(nr, nc) && grid[nr][nc] != '#') {
                        int add = 1;
                        bfs_check(q, next_q, state(nr, nc), top, dist[r][c] + add, add);
                    }
                }
            }

            swap(q, next_q);
            level++;
        }
    }
};


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (string &row : grid)
        cin >> row;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == 'B')
                for (int dir = 0; dir < DIRS; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];

                    if (0 <= nr && nr < N && 0 <= nc && nc < M && grid[nr][nc] == '.')
                        grid[nr][nc] = '#';
                }

    grid_bfs bfs(grid);

    if (grid[N - 1][M - 1] != '#')
        bfs.bfs({{N - 1, M - 1}});
    else
        bfs.bfs({});

    bool answer = true;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == 'B' && bfs.dist[r][c] < INF)
                answer = false;

            if (grid[r][c] == 'G' && bfs.dist[r][c] >= INF)
                answer = false;
        }

    cout << (answer ? "Yes" : "No") << '\n';
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