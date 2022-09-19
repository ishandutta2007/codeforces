#include <bits/stdc++.h>

using namespace std;
const int c=5002;
vector<int> sz[c];
int par[c], inv[c], pot[c], t[c], kerd[c], ans[c], n, m, q, mex;
bool h[c], v[c];
bool dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=inv[x];
        if (x==mex) {
            par[a]=mex, inv[mex]=a;
            return true;
        }
        if (!v[y]) {
            if (dfs(y)) {
                par[a]=x, inv[x]=a;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m, v[m+1]=true, v[0]=true;
    for (int i=1; i<=m; i++) par[i]=m+1;
    for (int i=1; i<=n; i++) cin >> pot[i];
    for (int i=1; i<=n; i++) cin >> t[i];
    cin >> q;
    for (int i=1; i<=q; i++) cin >> kerd[i], h[kerd[i]]=true;
    for (int i=1; i<=n; i++) {
        if (!h[i]) {
            sz[t[i]].push_back(pot[i]);
            bool jo=1;
            while(jo) {
                jo=0;
                for (int i=1; i<=m; i++) if (par[i]==m+1 && dfs(i)) {
                    mex++, jo=true;
                    for (int i=1; i<=m; i++) v[i]=0;
                    break;
                }
            }
        for (int i=1; i<=m; i++) v[i]=0;
        }
    }
    for (int i=q; i>=1; i--) {
        sz[t[kerd[i]]].push_back(pot[kerd[i]]);
        ans[i]=mex;
        bool jo=1;
        while(jo) {
            jo=0;
            for (int i=1; i<=m; i++) if (par[i]==m+1 && dfs(i)) {
                mex++, jo=true;
                for (int i=1; i<=m; i++) v[i]=0;
                break;
            }
        }
        for (int i=1; i<=m; i++) v[i]=0;
    }
    for (int i=1; i<=q; i++) cout << ans[i] << "\n";
    return 0;
}
/*
3 2
0 0 1
1 2 1
0
*/