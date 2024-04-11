#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1100, max_m = 1100, max_k = 40;
int n, m, k;
int col[max_n][max_m], dist[max_n][max_m][max_k];

void scan() {
    int xr[]{-1, 1, 0, 0}, yr[]{0, 0, -1, 1};
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> col[i][j];
            col[i][j]--;
        }
    }
    vector<pair<int, int>> loc[k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            loc[col[i][j]].emplace_back(i, j);
        }
    }

    for (int c = 0; c < k; c++) {
        deque<pair<int, int>> bfs;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (col[i][j] == c) bfs.emplace_back(i, j);
                else dist[i][j][c] = inf;
            }
        }

        bool used[k];
        for (int i = 0; i < k; i++) used[i] = false;
        used[c] = true;
        while (!bfs.empty()) {
            pair v = bfs.front();
            bfs.pop_front();

            for (int i = 0; i < 4; i++) {
                int to_x = v.first + xr[i];
                int to_y = v.second + yr[i];

                if (to_x < 0 || to_y < 0 || to_x >= n || to_y >= m || dist[to_x][to_y][c] != inf) continue;

                dist[to_x][to_y][c] = dist[v.first][v.second][c] + 1;
                bfs.emplace_back(to_x, to_y);
            }

            if (used[col[v.first][v.second]]) continue;

            used[col[v.first][v.second]] = true;
            for (pair i : loc[col[v.first][v.second]]) {
                if (dist[i.first][i.second][c] == inf) {
                    dist[i.first][i.second][c] = dist[v.first][v.second][c] + 1;
                    bfs.emplace_back(i.first, i.second);
                }
            }
        }
    }
}

int get(int x1, int y1, int x2, int y2) {
    int ans = abs(x1 - x2) + abs(y1 - y2);
    for (int i = 0; i < k; i++) {
        ans = min(ans, dist[x1][y1][i] + dist[x2][y2][i] + 1);
    }
    return ans;
}

void solve() {
    scan();
    int q;
    cin >> q;
    for (; q > 0; q--) {
        int o1, o2, o3, o4;
        cin >> o1 >> o2 >> o3 >> o4;
        int ans = get(o1 - 1, o2 - 1, o3 - 1, o4 - 1);
        cout << ans << '\n';
    }
}


signed main() {
    //freopen("search4.in", "r", stdin);
    //freopen("search4.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
}