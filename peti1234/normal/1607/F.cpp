#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int w, n, m, dist[c][c], cnt;
pair<int, int> spec[c*c];
bool v[c][c];
char dir[c][c];
int dfs(int a, int b) {
    spec[++cnt]={a, b};
    if (a<1 || a>n || b<1 || b>m || v[a][b]) return dist[a][b];
    v[a][b]=1;
    if (dir[a][b]=='U') dist[a][b]=dfs(a-1, b)+1;
    if (dir[a][b]=='D') dist[a][b]=dfs(a+1, b)+1;
    if (dir[a][b]=='L') dist[a][b]=dfs(a, b-1)+1;
    if (dir[a][b]=='R') dist[a][b]=dfs(a, b+1)+1;
    return dist[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> dir[i][j];
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (!v[i][j]) {
            dfs(i, j);
            pair<int, int> p=spec[cnt];
            for (int i=1; i<cnt; i++) {
                if (spec[i]==p) {
                    int specert=cnt-i;
                    for (int j=i; j<=cnt; j++) {
                        dist[spec[j].first][spec[j].second]=specert;
                    }
                }
            }
            cnt=0;
        }
        int x=1, y=1, ert=dist[x][y];
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (dist[i][j]>ert) x=i, y=j, ert=dist[i][j];
        cout << x << " " << y << " " << ert << "\n";
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) dist[i][j]=0, v[i][j]=0;
    }
    return 0;
}