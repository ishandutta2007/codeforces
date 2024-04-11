#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ans;
vector<int> sz[c];
bool v[c];
bool dfs(int a) {
    v[a]=true;
    int si=sz[a].size(), spec=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            if (dfs(x)) {
                spec=1;
            }
        }
    }
    if (si==1) {
        spec=1;
    }
    if (spec) {
        if (si>2) {
            ans--;
        } else {
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n;
    ans=0;
    for (int i=1; i<=n; i++) {
        v[i]=0, sz[i].clear();
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    if (n==1) {
        cout << 0 << "\n";
        return;
    }
    int pos=0;
    for (int i=1; i<=n; i++) {
        if (sz[i].size()==1) ans++;
        if (sz[i].size()>2) pos=i;
    }
    if (!pos) {
        cout << 1 << "\n";
        return;
    }
    dfs(pos);
    cout << ans << "\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
1 2 1 3 1 4 1 5
*/