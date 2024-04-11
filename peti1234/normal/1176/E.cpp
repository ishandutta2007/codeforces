#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, szint[c];
vector<int> sz[c], ps, pn;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (szint[a]%2) {
        pn.push_back(a);
    } else {
        ps.push_back(a);
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        if (ps.size()>pn.size()) {
            swap(ps, pn);
        }
        cout << ps.size() << "\n";
        for (auto x:ps) {
            cout << x << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            szint[i]=0, v[i]=0;
            sz[i].clear();
        }
        ps.clear(), pn.clear();
    }
    return 0;
}