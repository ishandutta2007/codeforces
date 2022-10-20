#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int K = 44;
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};
const short INF = 200;

int n, m, k;
int a[N][N];
short dist[K][N][N];
short distColor[K][K];
vector<short> ls[N][N], newLs[N][N];

bool inside(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= m;
}

void update(int u, int v, int it) {
    newLs[u][v].clear();
    for (int dir = 0; dir < 4; dir++) {
        int uu = u + X[dir];
        int vv = v + Y[dir];
        if (!inside(uu, vv)) continue;
        if (a[u][v] == a[uu][vv]) continue;
        for (int x : ls[uu][vv]) {
            if (dist[x][u][v] <= it) continue;
            dist[x][u][v] = it;
            newLs[u][v].push_back(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    // n = m = 1000;
    // k = 40;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // a[i][j] = rand() % k + 1;
            for (int x = 1; x <= k; x++) dist[x][i][j] = INF;
            dist[a[i][j]][i][j] = 0;
            ls[i][j].push_back(a[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) {
        fill(distColor[i] + 1, distColor[i] + k + 1, INF);
        distColor[i][i] = 0;
    }
    for (int it = 1; it <= k; it++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                update(i, j, it);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ls[i][j].swap(newLs[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int color = a[i][j];
            for (int c = 1; c <= k; c++) {
                distColor[color][c] = min(distColor[color][c], dist[c][i][j]);
            }       
        }
    }
    for (int x = 1; x <= k; x++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                distColor[i][j] = min(distColor[i][j], (short)(distColor[i][x] + distColor[x][j] + 1));
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int res = abs(r1 - r2) + abs(c1 - c2);
        for (int i = 1; i <= k; i++) {
            res = min(res, dist[i][r1][c1] + (short)1 + dist[i][r2][c2]);
            for (int j = 1; j <= k; j++) {
                res = min(res, dist[i][r1][c1] + dist[j][r2][c2] + (short)2 + distColor[i][j]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}