#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=20;
int n, q, ans[c], si[c], koz[c], mini[c], cnt;
int szint[c], fel[c][k];
vector<int> sz[c], akt, fa[c];
bool v[c], v3[c];
int dfs(int a, int ert) {
    v[a]=true;
    si[a]=1;
    for (auto x:sz[a]) {
        if (!ans[x] && !v[x]) {
            int s=dfs(x, ert);
            si[a]+=si[x];
            if (s) return s;
        }
    }
    if (2*si[a]>=ert) return a;
    return 0;
}
void dfs2(int a) {
    v[a]=true;
    akt.push_back(a);
    for (auto x:sz[a]) {
        if (!ans[x] && !v[x]) {
            dfs2(x);
        }
    }
}
void solve(vector<int> s, int ert) {
    /*cout << "solve: ";
    for (auto x:s) cout << x << " ";
    cout << "\n";*/
    int cent=dfs(s[0], s.size());
    ans[cent]=++ert;
    koz[++cnt]=cent, mini[cnt]=c;
    for (auto x:s) {
        fa[x].push_back(cnt);
    }
    for (auto x:s) v[x]=0;
    for (auto x:sz[cent]) {
        if (ans[x]) continue;
        akt.clear();
        dfs2(x);
        for (auto y:akt) v[y]=0;
        solve(akt, ert);
    }
}
void dfs3(int a) {
    v3[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=(fel[fel[a][i-1]][i-1]);
    }
    for (auto x:sz[a]) {
        if (!v3[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs3(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) a=fel[a][i];
    }
    for (int i=k-1;i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a==b) return a;
    return fel[a][0];
}
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}
void add(int a) {
    for (auto x:fa[a]) {
        mini[x]=min(mini[x], tav(a, koz[x]));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    vector<int> s;
    for (int i=1; i<=n; i++) s.push_back(i);
    solve(s, 0);
    szint[1]=1;
    dfs3(1);
    /*for (int i=1; i<=n; i++) {
        //cout << ans[i] << " ";
        cout << (char)('A'+ans[i]-1) << " ";
    }
    cout << "\n";*/
    add(1);
    while (q--) {
        int id, a;
        cin >> id >> a;
        if (id==1) {
            add(a);
        } else {
            int ans=c;
            for (auto x:fa[a]) {
                ans=min(ans, mini[x]+tav(a, koz[x]));
            }
            cout << ans << "\n";
        }
    }
    return 0;
}