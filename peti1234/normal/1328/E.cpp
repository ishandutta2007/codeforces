#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sz[c];
int n, q, db, p, r, akt, fel[c][22], szint[c];
bool v[c], f;
int lca(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    for (int i=20; i>=0; i--) {
        int x=fel[a][i];
        if (szint[x]>=szint[b]) a=x;
    }
    if (a==b) return a;
    return -1;
}
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<=20; i++) fel[a][i]=fel[fel[a][i-1]][i-1];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int m(int a) {
    if (a==1) return 1;
    return fel[a][0];
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
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=q; i++) {
        cin >> db >> akt;
        akt=m(akt), f=true;
        for (int i=1; i<db; i++) {
            cin >> p;
            p=m(p), r=lca(akt, p);
            if (r!=akt && r!=p) f=false;
            if (r==akt) akt=p;
        }
        if (f) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
// Knny volt, egy elrs miatt nem mkdtt.
// Dfs-nl nha rdemes nzni, hogy mikor mentem be s mikor hagytam el egy cscsot.