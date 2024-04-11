#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, st[c], be[c], ki[c], f[c], visz[c], visz2[c], cbe, cki, db;
vector<int> sz[c], s[c];
bool v[c], jo;
void dfs(int a) {
    v[a]=true, be[a]=cbe, cbe++;
    int v1=a, v2=a;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            f[x]=a, dfs(x);
            if (be[visz[x]]<be[v2]) v2=visz[x];
            if (be[v2]<be[v1]) swap(v1, v2);
            if (be[visz2[x]]<be[v2]) v2=visz2[x];
        }
        else if (be[x]<be[v2]) v2=x;
        if (be[v2]<be[v1]) swap(v1, v2);
    }
    if (be[v2]<be[a]) st[a]=2;
    visz[a]=v1, visz2[a]=v2;
    ki[a]=cki, cki++;
}
void dfs2(int a) {
    v[a]=1;
    for (int i=0; i<s[a].size(); i++) {
        int x=s[a][i];
        if (!v[x]) {st[x]=st[a], dfs2(x);}
    }
}
int vel() {
    long long a=rand(), b=rand(), c=rand();
    return (a*b+c)%n+1;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) sz[i].clear(), s[i].clear(), st[i]=0;
        db=0, jo=0;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
        }
        for (int i=1; i<=100; i++) {
            if (!jo) {
                int p=vel(), r=0; f[p]=0;
                for (int i=1; i<=n; i++) v[i]=0, st[i]=0;
                cbe=1, cki=1;
                dfs(p);
                for (int i=1; i<=n; i++) for (int j=0; j<sz[i].size(); j++) {
                    int x=sz[i][j];
                    if (f[x]!=i && (be[i]<be[x] || ki[i]>ki[x])) r=1;
                }
                if (!r) {
                    st[p]=1, jo=true;
                    for (int i=1; i<=n; i++) {v[i]=0; if (!st[i]) s[visz[i]].push_back(i);}
                    for (int i=1; i<=n; i++) if (st[i]) dfs2(i);
                }
            }
        }
        for (int i=1; i<=n; i++) if (st[i]==1) db++;
        if (db*5<n) cout << -1;
        else for (int i=1; i<=n; i++) if (st[i]==1) cout << i << " ";
        cout << "\n";
    }
    return 0;
}