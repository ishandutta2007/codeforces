#include <bits/stdc++.h>

using namespace std;
const int c=1005, s=42;
int n, m, k, w, t[c][c], dist[c][c][s];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
vector<pair<int, int> > sz[s];
queue<pair<int, int> > q;
bool v[c][c], cl[s];
void add(int fi, int se, int p, int ert) {
    if (!v[fi][se]) {
        v[fi][se]=1;
        dist[fi][se][p]=ert;
        q.push({fi, se});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
            sz[t[i][j]].push_back({i, j});
        }
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            v[i][j]=1;
        }
    }
    for (int p=1; p<=k; p++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                v[i][j]=0;
            }
        }
        for (int j=1; j<=k; j++) {
            cl[j]=0;
        }
        for (pair<int, int> i:sz[p]) {
            v[i.first][i.second]=1;
            q.push({i.first, i.second});
        }
        while (q.size()>0) {
            int a=q.front().first, b=q.front().second, szin=t[a][b], ert=dist[a][b][p];
            q.pop();
            if (!cl[szin]) {
                cl[szin]=1;
                for (pair<int, int> x:sz[szin]) {
                    int fi=x.first, se=x.second;
                    add(x.first, x.second, p, ert+1);
                }
            }
            for (int k=0; k<4; k++) {
                add(a-dx[k], b-dy[k], p, ert+1);
            }
        }
    }
    cin >> w;
    for (int i=1; i<=w; i++) {
        int a, b, c, d, mini;
        cin >> a >> b >> c >> d;
        mini=abs(a-c)+abs(b-d);
        for (int i=1; i<=k; i++) {
            mini=min(mini, dist[a][b][i]+dist[c][d][i]+1);
        }
        cout << mini << "\n";
    }
    return 0;
}