#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sz[c];
long long t[c], l[c], maxi, n;
void dfs(int a) {
    if (sz[a].empty()) l[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        dfs(x);
        l[a]+=l[x], t[a]+=t[x];
    }
    maxi=max(maxi, (t[a]+l[a]-1)/l[a]);
}
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        sz[x].push_back(i);
    }
    for (int i=1; i<=n; i++) cin >> t[i];
    dfs(1);
    cout << maxi << "\n";
    return 0;
}