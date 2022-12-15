#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n, m, dis[3333][3333], u, v, x, y, l1, xx, yy, l2;
vector<int> adj[3333];
queue<int> q;

void bfs(int x) {
    dis[x][x] = 0;
    q.push(x);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int nex: adj[u]) if (dis[x][nex] == -1) {
            dis[x][nex] = 1 + dis[x][u];
            q.push(nex);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (z, m) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    reset(dis, -1);
    FOR (i, 1, n) bfs(i);
    cin >> x >> y >> l1 >> xx >> yy >> l2;
    int ans = mod;
    FOR (i, 1, n) FOR (j, 1, n) {
        if (dis[x][i] + dis[i][j] + dis[j][y] <= l1 && dis[xx][i] + dis[i][j] + dis[j][yy] <= l2) 
            ans = min(ans, dis[x][i] + dis[xx][i] + dis[i][j] + dis[j][y] + dis[j][yy]);
        if (dis[x][i] + dis[i][j] + dis[j][y] <= l1 && dis[xx][j] + dis[i][j] + dis[i][yy] <= l2) 
            ans = min(ans, dis[x][i] + dis[xx][j] + dis[i][j] + dis[j][y] + dis[i][yy]);
    }
    if (dis[x][y] <= l1 && dis[xx][yy] <= l2) ans = min(ans, dis[x][y] + dis[xx][yy]);
    if (ans == mod) cout << -1;
    else cout << m - ans;
}