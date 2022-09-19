#include <bits/stdc++.h>

using namespace std;
const int c=400002;
vector<int> sz[c], s[c];
pair<int, int> sol[c];
int n, m, f[c], eler[c], visz[c], cnt, comp[c], maxi;
bool v[c];
void dfs(int a) {
    v[a]=1, cnt++;
    eler[a]=cnt, visz[a]=cnt, comp[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            if (visz[x]<=eler[a]) comp[a]+=comp[x], comp[x]=0;
            visz[a]=min(visz[a], visz[x]);
        } else if (x!=f[a]) {
            visz[a]=min(visz[a], eler[x]);
        }
    }
    if (comp[a]>comp[maxi]) maxi=a;
}
void dfs2(int a) {
    v[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x]) {
            sol[y]={x, a};
            dfs2(x);
        } else sol[y]={a, x};
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(i), s[b].push_back(i);
    }
    dfs(1);
    for (int i=1; i<=n; i++) v[i]=0;
    cout << comp[maxi] << "\n";
    dfs2(maxi);
    for (int i=1; i<=m; i++) {
        cout << sol[i].first << " " << sol[i].second << "\n";
    }
    return 0;
}