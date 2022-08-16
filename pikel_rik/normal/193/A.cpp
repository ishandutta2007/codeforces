#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 50 + 5;

int n, m;
string a[N];

bool visited[N][N];
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int newi = i + dirx[k], newj = j + diry[k];
            if (newi >= 0 and newi < n and newj >= 0 and newj < m and !visited[newi][newj] and a[newi][newj] == '#') {
                q.emplace(newi, newj);
                visited[newi][newj] = true;
            }
        }
    }
}

int neighbors(int i, int j) {
    int c = 0;
    if (i > 0 and a[i - 1][j] == '#')
        c++;
    if (j > 0 and a[i][j - 1] == '#')
        c++;
    if (i + 1 < n and a[i + 1][j] == '#')
        c++;
    if (j + 1 < m and a[i][j + 1] == '#')
        c++;
    return c;
}

bool connected() {
    int c = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] and a[i][j] == '#') {
                bfs(i, j);
                c++;
            }
        }
    }
    return c == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    int c = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) c += (a[i][j] == '#');
    
    if (c <= 2) {
        cout << "-1\n";
        return 0;
    }

    int ans = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                a[i][j] = '.';
                if (!connected())
                    ans = 1;
                a[i][j] = '#';
            }
        }
    }
    cout << ans << "\n";
    return 0;
}