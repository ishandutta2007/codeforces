#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int NM_MAX = 2005;
const int INF = 1e9 + 5;

const int DR[] = {-1, 0, +1, 0};
const int DC[] = {0, -1, 0, +1};

int N, M, R, C, X, Y;
vector<string> grid;
int dist[NM_MAX][NM_MAX];

bool valid(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < M;
}

void bfs() {
    memset(dist, 63, sizeof(dist));
    vector<pair<int, int>> queue0, queue1;
    int front = 0;
    queue0.emplace_back(R, C);
    dist[R][C] = 0;

    while (front < (int) queue0.size() || !queue1.empty()) {
        if (front >= (int) queue0.size()) {
            queue0.clear();
            swap(queue0, queue1);
            front = 0;
        }

        pair<int, int> current = queue0[front++];
        int r = current.first, c = current.second;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + DR[dir];
            int nc = c + DC[dir];
            int cost = dir % 2;

            if (valid(nr, nc) && grid[nr][nc] == '.' && dist[r][c] + cost < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + cost;
                (cost == 0 ? queue0 : queue1).emplace_back(nr, nc);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R >> C >> X >> Y;
    grid.resize(N);
    R--; C--;

    for (int i = 0; i < N; i++)
        cin >> grid[i];

    assert(grid[R][C] == '.');
    bfs();
    int answer = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int diff = c - C;
            int sum = dist[r][c];

            if (sum >= INF)
                continue;

            assert((diff + sum) % 2 == 0);
            int right = (sum + diff) / 2;
            int left = (sum - diff) / 2;

            if (left <= X && right <= Y)
                answer++;
        }

    cout << answer << '\n';
}