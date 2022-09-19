#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, ans[c], si[c];
vector<int> sz[c], akt;
bool v[c];
int dfs(int a, int ert) {
    v[a]=true;
    si[a]=1;
    for (auto x:sz[a]) {
        if (!ans[x] && !v[x]) {
            int s=dfs(x, ert);
            si[a]+=si[x];
            if (s) return s;
        }
    }
    if (2*si[a]>=ert) return a;
    return 0;
}
void dfs2(int a) {
    v[a]=true;
    akt.push_back(a);
    for (auto x:sz[a]) {
        if (!ans[x] && !v[x]) {
            dfs2(x);
        }
    }
}
void solve(vector<int> s, int ert) {
    /*cout << "solve: ";
    for (auto x:s) cout << x << " ";
    cout << "\n";*/
    int cent=dfs(s[0], s.size());
    ans[cent]=++ert;
    for (auto x:s) v[x]=0;
    for (auto x:sz[cent]) {
        if (ans[x]) continue;
        akt.clear();
        dfs2(x);
        for (auto y:akt) v[y]=0;
        solve(akt, ert);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    vector<int> s;
    for (int i=1; i<=n; i++) s.push_back(i);
    solve(s, 0);
    for (int i=1; i<=n; i++) {
        //cout << ans[i] << " ";
        cout << (char)('A'+ans[i]-1) << " ";
    }
    cout << "\n";
    return 0;
}