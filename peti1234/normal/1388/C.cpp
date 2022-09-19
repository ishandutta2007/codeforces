#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, m, db[c], s[c], b[c], r;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x), db[a]+=db[x], b[a]+=b[x];
    }
    if ((db[a]+s[a])%2 || 2*b[a]>s[a]+db[a] || s[a]>db[a]) r++;
    b[a]=(db[a]+s[a])/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, r=0;
        for (int i=1; i<=n; i++) sz[i].clear(), v[i]=0, b[i]=0;
        for (int i=1; i<=n; i++) cin >> db[i];
        for (int i=1; i<=n; i++) cin >> s[i];
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        if (r) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}