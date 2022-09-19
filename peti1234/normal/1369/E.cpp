#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, fsz[c], db[c];
vector<pair<int, int> > sz[c];
vector<int> sol;
bool v[c], h[c];
void dfs(int a) {
    h[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i].first, y=sz[a][i].second;
        db[x]++;
        if (!v[y]) sol.push_back(y), v[y]=true;
        if (!h[x] && sz[x].size()<=db[x]) dfs(x);
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> db[i];
    for (int i=1; i<=m; i++) {int a, b; cin >> a >> b; sz[a].push_back({b, i}), sz[b].push_back({a, i});}
    for (int i=1; i<=n; i++) if (!h[i] && sz[i].size()<=db[i]) dfs(i);
    if (sol.size()<m) cout << "DEAD\n";
    else {
        cout << "ALIVE\n";
        for (int i=m-1; i>=0; i--) cout << sol[i] << " ";
    }
    return 0;
}