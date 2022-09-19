#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, pos[c], id=1, db;
vector<int> sz[c], s[c];
bool fel[c], le[c], v[c], r;
string ss;
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) if (!v[sz[a][i]]) dfs(sz[a][i]);
    pos[a]=id, id++;
}
void fdfs(int a) {
    fel[a]=true;
    for (int i=0; i<s[a].size(); i++) if (!fel[s[a][i]]) fdfs(s[a][i]);
}
void ldfs(int a) {
    le[a]=true;
    for (int i=0; i<sz[a].size(); i++) if (!le[sz[a][i]]) ldfs(sz[a][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), s[b].push_back(a);
    }
    for (int i=1; i<=n; i++) if (!v[i]) dfs(i);
    for (int i=1; i<=n; i++) for (int j=0; j<sz[i].size(); j++) if (pos[i]<pos[sz[i][j]]) r=true;
    if (r) cout << -1 << endl;
    else {
        for (int i=1; i<=n; i++) {
            if (fel[i] || le[i]) ss+='E';
            else ss+='A', db++;
            if (!fel[i]) fdfs(i);
            if (!le[i]) ldfs(i);
        }
        cout << db << endl;
        cout << ss << endl;
    }
    return 0;
}