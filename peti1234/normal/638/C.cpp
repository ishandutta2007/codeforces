#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, maxi;
vector<int> sz[c], s[c], ans[c];
bool v[c];
void dfs(int a, int fel) {
    int pos=fel;
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            pos=(pos+1)%maxi;
            dfs(x, pos);
        } else {
            int y=s[a][i];
            ans[fel+1].push_back(y);
        }
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
        s[a].push_back(i), s[b].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        int si=sz[i].size();
        maxi=max(maxi, si);
    }
    dfs(1, 0);
    cout << maxi << "\n";
    for (int i=1; i<=maxi; i++) {
        cout << ans[i].size() << " ";
        for (int x:ans[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}