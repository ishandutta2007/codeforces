#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1000;

int n, m, k, a[N][N];
vector<pair<int, int>> v[40];

int lvl[40][N][N];
bool visitedc[40], visited[N][N];

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            v[--a[i][j]].emplace_back(i, j);
        }
    }

    for (int i = 0; i < k; i++) {
        memset(visited, false, sizeof(visited));
        memset(visitedc, false, sizeof(visitedc));

        queue<pair<int, int>> q;
        for (auto& [x, y] : v[i]) {
            q.emplace(x, y);
            visited[x][y] = true;
        }

        visitedc[i] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int new_x = x + dirx[j], new_y = y + diry[j];
                if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and !visited[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    lvl[i][new_x][new_y] = 1 + lvl[i][x][y];
                    q.emplace(new_x, new_y);
                }
            }
            if (!visitedc[a[x][y]]) {
                for (auto& [new_x, new_y] : v[a[x][y]]) {
                    if (!visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        lvl[i][new_x][new_y] = 1 + lvl[i][x][y];
                        q.emplace(new_x, new_y);
                    }
                }
                visitedc[a[x][y]] = true;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1, --r2, --c2;

        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (int i = 0; i < k; i++) {
            ans = min(ans, 1 + lvl[i][r1][c1] + lvl[i][r2][c2]);
        }
        cout << ans << '\n';
    }
    return 0;
}