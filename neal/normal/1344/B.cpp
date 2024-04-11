#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


const int INF = 1e9 + 5;

int N, M;
vector<string> grid;

bool bad(const string &row) {
    int len = row.size();
    int earliest = INF, latest = -INF;

    for (int i = 0; i < len; i++)
        if (row[i] == '#') {
            earliest = min(earliest, i);
            latest = max(latest, i);
        }

    for (int i = earliest; i <= latest; i++)
        if (row[i] == '.')
            return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    int empty_rows = 0, empty_cols = 0;

    for (int r = 0; r < N; r++) {
        bool empty = true;

        for (int c = 0; c < M; c++)
            empty = empty && grid[r][c] == '.';

        empty_rows += empty;
    }

    for (int c = 0; c < M; c++) {
        bool empty = true;

        for (int r = 0; r < N; r++)
            empty = empty && grid[r][c] == '.';

        empty_cols += empty;
    }

    if ((empty_rows == 0) ^ (empty_cols == 0)) {
        cout << -1 << '\n';
        return 0;
    }

    for (int r = 0; r < N; r++)
        if (bad(grid[r])) {
            cout << -1 << '\n';
            return 0;
        }

    for (int c = 0; c < M; c++) {
        string column;

        for (int r = 0; r < N; r++)
            column += grid[r][c];

        if (bad(column)) {
            cout << -1 << '\n';
            return 0;
        }
    }

    union_find UF(N * M);
    int empty_cells = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            empty_cells += grid[r][c] == '.';

            if (r + 1 < N && grid[r][c] == '#' && grid[r + 1][c] == '#')
                UF.unite(r * M + c, (r + 1) * M + c);

            if (c + 1 < M && grid[r][c] == '#' && grid[r][c + 1] == '#')
                UF.unite(r * M + c, r * M + (c + 1));
        }

    dbg(UF.components, empty_cells);
    cout << UF.components - empty_cells << '\n';
}