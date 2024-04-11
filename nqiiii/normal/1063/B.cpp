#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2000;
int n, m, sx, sy, x, y;
int a[maxn + 10][maxn + 10], ans;
int dis[maxn + 10][maxn + 10];
bool vis[maxn + 10][maxn + 10];
deque<pair<int, int> > q;

void go(int x, int y, int d, bool b) {
    if (x <= 0 || x > n || y <= 0 || y > m || a[x][y]) return;
    if (d < dis[x][y]) {
        dis[x][y] = d;
        if (b) q.push_back(make_pair(x, y));
        else q.push_front(make_pair(x, y));
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &sx, &sy, &x, &y);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            while (!isgraph(c)) c = getchar();
            a[i][j] = c == '*';
        }
    memset(dis, 0x3f, sizeof dis); dis[sx][sy] = 0;
    q.push_back(make_pair(sx, sy));
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop_front();
        if (vis[p.first][p.second]) continue;
        vis[p.first][p.second] = 1;
        go(p.first - 1, p.second, dis[p.first][p.second], 0);
        go(p.first + 1, p.second, dis[p.first][p.second], 0);
        go(p.first, p.second - 1, dis[p.first][p.second] + 1, 1);
        go(p.first, p.second + 1, dis[p.first][p.second], 0);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            if (dis[i][j] < 1e9) {
                if (dis[i][j] <= x && j - (sy - dis[i][j]) <= y) ++ans;
            }
    }
    printf("%d", ans);
}