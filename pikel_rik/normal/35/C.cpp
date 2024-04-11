#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e3 + 5;

int n, m, lvl[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool visited[N][N];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.emplace(i, j);

    lvl[i][j] = 0;
    visited[i][j] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (auto &k : dir) {
            int x = p.first + k[0], y = p.second + k[1];
            if (x >= 1 and x <= n and y >= 1 and y <= m and !visited[x][y]) {
                q.emplace(x, y);
                lvl[x][y] = min(lvl[x][y], 1 + lvl[p.first][p.second]);
                visited[x][y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) lvl[i][j] = inf;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) visited[i][j] = false;
        bfs(x, y);
    }

    int t = -1, x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (lvl[i][j] > t) {
                t = lvl[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << x << " " << y << "\n";
    return 0;
}