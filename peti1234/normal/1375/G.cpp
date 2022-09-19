#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, e, t[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) t[x]=t[a]+1, dfs(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {int a, b; cin >> a >> b; sz[a].push_back(b), sz[b].push_back(a);}
    dfs(1);
    for (int i=1; i<=n; i++) e+=t[i]%2;
    e=min(e, n-e);
    cout << e-1 << "\n";
    return 0;
}