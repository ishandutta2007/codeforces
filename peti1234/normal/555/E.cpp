#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=20;
int n, m, q, ki[c], szint[c], nagy[c], kis[c], eler[c], visz[c], f[c], fel[c][k], cnt;
vector<int> sz[c], id[c], sz2[c];
bool v[c], v2[c], v3[c], baj;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[b]=a;
    }
}
void dfs(int a) {
    v[a]=true;
    cnt++, eler[a]=cnt, visz[a]=cnt;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=id[a][i];
        if (!v[x]) {
            f[x]=y;
            dfs(x);
            if (visz[x]!=eler[x]) {
                unio(a, x);
            }
            visz[a]=min(visz[a], visz[x]);
        } else {
            if (f[a]!=y) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
}
void dfs2(int a) {
    v2[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz2[a]) {
        if (!v2[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs2(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        a=fel[a][0];
    }
    if (!a) {
        baj=1;
    }
    return szint[a];
}
void dfs3(int a) {
    v3[a]=true;
    for (int x:sz2[a]) {
        if (!v3[x]) {
            dfs3(x);
            nagy[a]=max(nagy[a], nagy[x]-1);
            kis[a]=max(kis[a], kis[x]-1);
        }
    }
    if (kis[a] && nagy[a]) {
        baj=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        id[a].push_back(i), id[b].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j:sz[i]) {
            int a=holvan(i), b=holvan(j);
            if (i>j && a!=b) {
                sz2[a].push_back(b), sz2[b].push_back(a);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v2[i]) {
            szint[i]=1;
            dfs2(i);
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b, c; cin >> a >> b;
        a=holvan(a), b=holvan(b);
        c=lca(a, b);
        nagy[a]=max(nagy[a], szint[a]-c);
        kis[b]=max(kis[b], szint[b]-c);
    }
    for (int i=1; i<=n; i++) {
        if (!v3[i]) {
            dfs3(i);
        }
    }
    if (baj) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}