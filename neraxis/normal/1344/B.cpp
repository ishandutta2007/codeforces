#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1005;

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
string s[N];
bool check[N][N];

bool inb(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs(int x, int y) {
    queue<ii> q;
    q.push({x, y});
    check[x][y] = 1;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = u.x + dx[i];
            int yy = u.y + dy[i];
            if (inb(xx, yy) && check[xx][yy] == 0 && s[xx][yy] == '#') {
                q.push({xx, yy});
                check[xx][yy] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int cnt = 0;
    bool ok = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    bool row, col;
    row = col = 0;
    for (int i = 1; i <= n; i++) {
        bool bl = 0;
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') bl = 1; 
        }
        if (bl == 0) row = 1;
    }
    for (int i = 1; i <= m; i++) {
        bool bl = 0;
        for (int j = 1; j <= n; j++) {
            if (s[j][i] == '#') bl = 1;
        }
        if (bl == 0) col = 1;
    }
    for (int i = 1; i <= n; i++) {
        int bl = 0;
        for (int j = 1; j <= m; j++) {
            if (bl == 2 && s[i][j] == '#') ok = 0;
            if (s[i][j] == '#') bl = 1;
            if (bl && s[i][j] == '.') bl = 2;
        }
    }
    for (int i = 1; i <= m; i++) {
        int bl = 0;
        for (int j = 1; j <= n; j++) {
            if (bl == 2 && s[j][i] == '#') ok = 0;
            if (s[j][i] == '#') bl = 1;
            if (bl && s[j][i] == '.') bl = 2;
        }
    }
    if (ok == 0 || (row ^ col)) return cout << -1, 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#' && check[i][j] == 0) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}