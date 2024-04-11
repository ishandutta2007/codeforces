#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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

const int DIRS = 4;
const int DR[DIRS] = {-1,  0, +1,  0};
const int DC[DIRS] = { 0, +1,  0, -1};

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    vector<int> row_max(N, 0);
    vector<int> col_max(M, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            row_max[i] = max(row_max[i], A[i][j]);
            col_max[j] = max(col_max[j], A[i][j]);
        }

    sort(row_max.begin(), row_max.end());
    sort(col_max.begin(), col_max.end());

    vector<vector<int>> neighbors(N, vector<int>(M, 0));
    vector<set<pair<int, int>>> neighbor_sets(DIRS + 1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            neighbor_sets[0].insert({i, j});

    vector<vector<int>> solution(N, vector<int>(M, -1));
    vector<bool> done(N * M + 1, false);

    auto &&place = [&](int r, int c, int number) {
        dbg(r, c, number);
        assert(solution[r][c] < 0);
        neighbor_sets[neighbors[r][c]].erase({r, c});
        solution[r][c] = number;
        done[number] = true;

        for (int dir = 0; dir < DIRS; dir++) {
            int nr = r + DR[dir];
            int nc = c + DC[dir];

            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                neighbor_sets[neighbors[nr][nc]].erase({nr, nc});
                neighbors[nr][nc]++;
                if (solution[nr][nc] < 0) neighbor_sets[neighbors[nr][nc]].insert({nr, nc});
            }
        }
    };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (row_max[i] == col_max[j])
                place(i, j, row_max[i]);

    for (int number = N * M; number > 0; number--)
        if (!done[number]) {
            int row = -1, col = -1;

            for (int i = 0; i < N; i++)
                if (row_max[i] == number)
                    row = i;

            for (int j = 0; j < M; j++)
                if (col_max[j] == number)
                    col = j;

            if (row >= 0) {
                int best_col = -1;

                for (int j = 0; j < M; j++)
                    if (solution[row][j] < 0 && col_max[j] >= number && (best_col < 0 || neighbors[row][j] > neighbors[row][best_col]))
                        best_col = j;

                assert(best_col >= 0);
                place(row, best_col, number);
            } else if (col >= 0) {
                int best_row = -1;

                for (int i = 0; i < N; i++)
                    if (solution[i][col] < 0 && row_max[i] >= number && (best_row < 0 || neighbors[i][col] > neighbors[best_row][col]))
                        best_row = i;

                assert(best_row >= 0);
                place(best_row, col, number);
            } else {
                for (int neigh = DIRS; neigh >= 0; neigh--)
                    for (pair<int, int> p : neighbor_sets[neigh])
                        if (row_max[p.first] >= number && col_max[p.second] >= number) {
                            neighbor_sets[neigh].erase(p);
                            place(p.first, p.second, number);
                            goto finish;
                        }

                finish: ;
            }
        }

    for (auto &row : solution)
        output_vector(row);
}