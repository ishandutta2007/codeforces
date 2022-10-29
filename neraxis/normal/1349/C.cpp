#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1005;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, t;
bool a[N][N];
int d[N][N];
bool check[N][N];
bool colo[N][N];

bool inG(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> t;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    queue<pair<ii, bool>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (inG(xx, yy) && a[xx][yy] == a[i][j]) check[i][j] = 1;
            }
        }
    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) {
                q.push({{i, j}, a[i][j]});
                colo[i][j] = a[i][j];
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u.x.x;
        int y = u.x.y;
        bool col = u.y;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!inG(xx, yy)) continue;
            if (check[xx][yy]) continue;
            check[xx][yy] = 1;
            q.push({{xx, yy}, col});
            d[xx][yy] = d[x][y] + 1;
            colo[xx][yy] = col;
        }
    }
    while (t--) {
        int i, j;
        long long p;
        cin >> i >> j >> p;
        int ans;
        if (p < d[i][j] || d[i][j] == -1) ans = a[i][j];
        else {
            ans = (p + colo[i][j]) % 2;
        }
        cout << ans << '\n';
    }
    return 0;
}