#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, m, p[c], f[c];
vector<int> sz[c], s[c], sol;
bool v[c], jo=1;
int dfs(int a) {
    v[a]=1;
    int fid=0, db=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) f[x]=a, db+=dfs(x);
        if (x==f[a]) fid=s[a][i];
    }
    if (p[a]!=-1 && db%2!=p[a]) {
        if (!fid) jo=0;
        sol.push_back(fid);
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> p[i];
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(i), s[b].push_back(i);
    }
    for (int i=1; i<=n; i++) if (!v[i] && p[i]==-1) dfs(i);
    for (int i=1; i<=n; i++) if (!v[i]) dfs(i);
    if (jo) {
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
    } else cout << -1 << "\n";
    return 0;
}