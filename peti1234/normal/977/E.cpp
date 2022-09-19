#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, ans, m;
vector<int> sz[c];
bool v[c], jo;
void dfs(int a) {
    v[a]=true;
    if (sz[a].size()!=2) {
        jo=0;
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
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
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        jo=1;
        if (!v[i]) {
            dfs(i);
            if (jo) {
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}