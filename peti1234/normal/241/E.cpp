#include <bits/stdc++.h>

using namespace std;
const int c=10005;
int n, m, dist[c], x[c], y[c], suly[c];
bool v[c][2], fontos[c];
vector<int> sz[c][2];
void dfs(int a, int b) {
    v[a][b]=true;
    for (auto x:sz[a][b]) {
        if (!v[x][b]) {
            dfs(x, b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a][0].push_back(b), sz[b][1].push_back(a);
        x[2*i-1]=a, y[2*i-1]=b, suly[2*i-1]=2;
        x[2*i]=b, y[2*i]=a, suly[2*i]=-1;
    }
    dfs(1, 0), dfs(n, 1);

    for (int i=2; i<=n; i++) {
        dist[i]=c;
    }
    m*=2;
    for (int i=1; i<=m; i++) {
        if (v[x[i]][0] && v[x[i]][1] && v[y[i]][0] && v[y[i]][1]) fontos[i]=1;
    }
    for (int it=1; it<=n; it++) {
        for (int i=1; i<=m; i++) {
            if (!fontos[i]) continue;
            dist[y[i]]=min(dist[y[i]], dist[x[i]]+suly[i]);
        }
    }
    
    for (int i=1; i<=m; i++) {
        if (!fontos[i]) continue;
        if (dist[y[i]]>dist[x[i]]+suly[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i=1; i<=m; i+=2) {
        if (!fontos[i]) cout << 1 << "\n";
        else cout << dist[y[i]]-dist[x[i]] << "\n";
    }
    return 0;
}