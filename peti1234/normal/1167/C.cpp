#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> sz[500001];
bool v[500001];
int ans[500001];
int os[500001];
void dfs(int a)
{
    v[a]=true;
    if (os[a]==0) {
        os[a]=a;
    }
    ans[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            os[x]=os[a];
            dfs(x);
            ans[a]+=ans[x];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int p;
        cin >> p;
        int a;
        if (p>0) {
            cin >> a;
        }
        for (int i=1; i<p; i++) {
            int b;
            cin >> b;
            sz[a].push_back(b);
            sz[b].push_back(a);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        ans[i]=ans[os[i]];
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}