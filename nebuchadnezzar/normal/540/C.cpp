#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define x0 qwe0
#define x1 qwe1
#define y0 ewq0
#define y1 ewq1

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 505;

int n, m;
int field[MAXN][MAXN];
int x0, y0, x1, y1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool used[MAXN][MAXN];

int dfs(int x, int y) {
    used[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx == x1 && ny == y1) {
            return 1;
        }
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && field[nx][ny]) {
            if (dfs(nx, ny)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '.') {
                field[i][j] = 1;
            }
        }
    }

    cin >> x0 >> y0 >> x1 >> y1;
    --x0;--y0;--x1;--y1;

    if (dfs(x0, y0)) {
        if (!field[x1][y1]) {
            cout << "YES\n";
            return 0;
        }
        int num = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny]) {
                ++num;
            }
            if (nx == x0 && ny == y0) {
                ++num;
            }
        }
        if (num > 1) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}