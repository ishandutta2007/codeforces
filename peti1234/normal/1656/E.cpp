#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, ans[c];
vector<int> sz[c];
bool v[c];
void dfs(int a, int b) {
    v[a]=true;
    ans[a]=b*sz[a].size();
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x, -b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1, 1);
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            v[i]=0, ans[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}