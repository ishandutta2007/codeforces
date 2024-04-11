#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, m, t[c][c], tav[c][c];
long long sok=1e17, mini[2]={sok, sok}, ans=sok, lep;
bool v[c][c];
queue<pair<int, pair<int, int> > >q;
bool jo(int a, int b) {
    if (a<=0 || a>n || b<=0 || b>m || t[a][b]==-1 || v[a][b]) {
        return 0;
    }
    return 1;
}
void add(int a, int b, int c) {
    if (jo(b, c)) {
        q.push({a, {b, c}});
        v[b][c]=1;
        tav[b][c]=a;
    }
}
void bfs(int id) {
    while (q.size()>0) {
        int ert=q.front().first, s=q.front().second.first, o=q.front().second.second;
        if (t[s][o]>0) {
            mini[id]=min(mini[id], lep*ert+t[s][o]);
        }
        q.pop();
        add(ert+1, s-1, o);
        add(ert+1, s+1, o);
        add(ert+1, s, o-1);
        add(ert+1, s, o+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> lep;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    add(0, 1, 1);
    bfs(0);
    if (v[n][m]) {
        ans=min(ans, lep*tav[n][m]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            v[i][j]=0, tav[i][j]=0;
        }
    }
    add(0, n, m);
    bfs(1);
    ans=min(ans, mini[0]+mini[1]);
    if (ans==sok) {
        ans=-1;
    }
    cout << ans << "\n";
    return 0;
}