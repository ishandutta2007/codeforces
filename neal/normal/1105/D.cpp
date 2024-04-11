#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int NM_MAX = 1005;
const int P_MAX = 10;
const char EMPTY = '.';

const int DIRS = 4;
const int DR[DIRS] = {-1, 0, +1, 0};
const int DC[DIRS] = {0, +1, 0, -1};

int N, M, P;
int S[P_MAX];
char grid[NM_MAX][NM_MAX];
vector<pair<int, int>> active[P_MAX];
vector<pair<int, int>> current;

bool has_active() {
    for (int i = 1; i <= P; i++)
        if (!active[i].empty())
            return true;

    return false;
}

int seen[NM_MAX][NM_MAX];
int dist[NM_MAX][NM_MAX];
int seen_index = 0;

void expand(int p) {
    current.clear();
    seen_index++;
    vector<pair<int, int>> q;

    for (pair<int, int> coord : active[p]) {
        dist[coord.first][coord.second] = 0;
        seen[coord.first][coord.second] = seen_index;
        q.emplace_back(coord.first, coord.second);
    }

    for (int front = 0; front < (int) q.size(); front++) {
        int r = q[front].first, c = q[front].second;
        grid[r][c] = p + '0';

        if (dist[r][c] >= S[p])
            continue;

        for (int dir = 0; dir < DIRS; dir++) {
            int nr = r + DR[dir];
            int nc = c + DC[dir];

            if (grid[nr][nc] == EMPTY && seen[nr][nc] != seen_index) {
                seen[nr][nc] = seen_index;
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace_back(nr, nc);
                current.emplace_back(nr, nc);
            }
        }
    }

    active[p] = current;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> P;

    for (int p = 1; p <= P; p++)
        cin >> S[p];

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
            grid[i + 1][j + 1] = str[j];
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (isdigit(grid[i][j]))
                active[grid[i][j] - '0'].emplace_back(i, j);

    while (has_active()) {
        for (int p = 1; p <= P; p++)
            expand(p);
    }

    vector<int> answers(P_MAX, 0);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (isdigit(grid[i][j]))
            answers[grid[i][j] - '0']++;

    for (int p = 1; p <= P; p++)
        cout << answers[p] << (p < P ? ' ' : '\n');
}