#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, t[c];
vector<int> sz[c], ans;
void dfs(int a) {
    for (auto x:sz[a]) {
        int si=sz[x].size();
        if (!si) ans.push_back(x);
    }
    for (auto x:sz[a]) {
        int si=sz[x].size();
        if (si) {
            ans.push_back(x);
            dfs(x);
        }
    }
}
void solve() {
    cin >> n;
    int pos=0;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]>i) pos++;
        sz[t[i]].push_back(i);
    }
    dfs(0), dfs(n+1);
    cout << pos << "\n";
    for (auto x:ans) cout << x << " ";
    cout << "\n";

    for (int i=0; i<=n+1; i++) {
        sz[i].clear();
    }
    ans.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}