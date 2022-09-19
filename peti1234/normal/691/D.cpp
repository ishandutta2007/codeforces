#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, t[c], ans[c];
vector<int> sz[c], p, q;
bool v[c];
void dfs(int a) {
    v[a]=true;
    p.push_back(a), q.push_back(t[a]);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
            sort(p.begin(), p.end());
            sort(q.rbegin(), q.rend());
            for (int j=0; j<p.size(); j++) {
                ans[p[j]]=q[j];
            }
            p.clear(), q.clear();
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}