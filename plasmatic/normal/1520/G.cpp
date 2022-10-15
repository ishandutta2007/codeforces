// ./g-to-go-or-not-to-go.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 2e3 + 1;
int N, M, 
    disS[MN][MN], disE[MN][MN], grid[MN][MN];
ll W;

void bfs(int x, int y, int dis[MN][MN]) {
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < M; j++)
            dis[i][j] = INF;
    queue<pii> q;
    dis[x][y] = 0;
    q.emplace(x, y);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [tx, ty] : vector<pii>{{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}}) {
            if (tx < 0 || tx >= N || ty < 0 || ty >= M || grid[tx][ty] == -1 || dis[tx][ty] != INF) continue;
            dis[tx][ty] = dis[x][y]+1;
            q.emplace(tx, ty);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> W;
    vector<pii> portals;
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] > 0)
                portals.emplace_back(i, j);
        }
    }
    bfs(0, 0, disS);
    bfs(N-1, M-1, disE);

    ll ans = disS[N-1][M-1] == INF ? LLINF : W * disS[N-1][M-1], lhs = LLINF, rhs = LLINF;
    for (auto [x, y] : portals) {
        if (disS[x][y] != INF) lhs = min(lhs, W*disS[x][y]+grid[x][y]);
        if (disE[x][y] != INF) rhs = min(rhs, W*disE[x][y]+grid[x][y]);
    }
    if (lhs != LLINF && rhs != LLINF) ans = min(ans, lhs+rhs);
    cout << (ans == LLINF ? -1 : ans) << '\n';

    return 0;
}