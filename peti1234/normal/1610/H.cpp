#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=20;
int n, m, f[c], fel[c][k], db[c], szint[c];
vector<int> sz[c], p[c];
vector<pair<int, int> > spec, r;
void dfs(int a) {
    r.push_back({szint[a], a});
    fel[a][0]=f[a];
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (auto x:sz[a]) {
        szint[x]=szint[a]+1;
        dfs(x);
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
    if (a==b) return a;
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    return fel[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=2; i<=n; i++) {
        cin >> f[i];
        sz[f[i]].push_back(i);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        if (szint[x]>szint[y]) {
            swap(x, y);
        }
        int s=lca(x, y);
        if (s!=x) {
            spec.push_back({x, y});
        } else {
            int sy=y;
            for (int i=k-1; i>=0; i--) {
                if (szint[fel[sy][i]]>szint[x]) {
                    sy=fel[sy][i];
                }
            }
            if (sy==y) {
                cout << -1 << "\n";
                return 0;
            }
            p[sy].push_back(y);
        }
    }
    sort(r.rbegin(), r.rend());
    for (auto xx:r) {
        int a=xx.second;
        for (auto x:p[a]) {
            if (db[x]==db[a]) {
                db[a]++;
            }
        }
        db[f[a]]+=db[a];
    }
    for (auto x:spec) {
        int a=x.first, b=x.second, c=lca(a, b);
        if (db[a]+db[b]==db[1]) {
            db[1]++;
        }
    }
    cout << db[1] << "\n";
    return 0;
}