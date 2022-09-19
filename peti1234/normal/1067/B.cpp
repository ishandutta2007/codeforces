#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, k, dist[c][3];
bool v[c][3], jo, baj;
vector<int> sz[c];
void dfs(int a, int b) {
    v[a][b]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x][b]) dist[x][b]=dist[a][b]+1, dfs(x, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {int x, y; cin >> x >> y; sz[x].push_back(y), sz[y].push_back(x);}
    for (int i=1; i<=n; i++) if (sz[i].size()==1) {dfs(i, 0); break;}
    for (int i=1; i<=n; i++) if (dist[i][0]==2*k) {jo=1, dfs(i, 1); break;}
    for (int i=1; i<=n; i++) if (dist[i][0]==k && dist[i][1]==k) dfs(i, 2);
    for (int i=1; i<=n; i++) {int x=dist[i][2], y=sz[i].size(); if ((!x && y<3) || (0<x && x<k && y<4) || (x==k && y!=1) || x>k) baj=1;}
    if (jo && !baj) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}