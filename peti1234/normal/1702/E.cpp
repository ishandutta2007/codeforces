#include <bits/stdc++.h>

using namespace std;
const int c=200005;
vector<int> sz[c];
bool v[c];
vector<int> vis;
void dfs(int a) {
    v[a]=true;
    vis.push_back(a);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    bool jo=1;
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>2) {
            jo=0;
        }
        if (sz[i].size()==1 && !v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i] && sz[i].size()==2) {
            vis.clear();
            dfs(i);
            int si=vis.size();
            if (si%2) {
                jo=0;
            }
        }
    }


    for (int i=1; i<=n; i++) {
        sz[i].clear();
        v[i]=0;
    }
    vis.clear();
    cout << (jo ? "YES" : "NO") << "\n";
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
/*
1
stringology
*/