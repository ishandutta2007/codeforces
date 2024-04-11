#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int m, s[c];
vector<char> ans[200005];
vector<int> t[200005];
map<int, vector<pair<int, int> > > sz;
void solve(int id) {
    while (sz[id].size()>0) {
        auto p=sz[id].back();
        int a=p.first, b=p.second;
        if (!t[a][b]) {
            sz[id].pop_back();
        } else {
            int f=s[a]-1-b, kov=t[a][f];
            ans[a][b]='L';
            ans[a][f]='R';
            t[a][b]=0, t[a][f]=0;
            solve(kov);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m;
    for (int i=1; i<=m; i++) {
        int n;
        cin >> n;
        s[i]=n;
        ans[i].resize(n), t[i].resize(n);
        for (int j=0; j<n; j++) {
            cin >> t[i][j];
            sz[t[i][j]].push_back({i, j});
        }
    }
    for (auto p:sz) {
        int si=p.second.size();
        if (si%2) {
            cout << "NO\n";
            return 0;
        }
    }
    for (auto p:sz) {
        solve(p.first);
    }
    cout << "YES\n";
    for (int i=1; i<=m; i++) {
        for (int j=0; j<s[i]; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}