#include <bits/stdc++.h>

using namespace std;
int q;
bool v[300001];
int maxi=0;
vector<int> sz[300001];
int n;
int dfs(int a)
{
    v[a]=true;
    int e=0, m=0, p=sz[a].size();
    for (int i=0; i<p; i++) {
        int x=sz[a][i];
        if (!v[x]) {
            int y=dfs(x);
            if (y>m) m=y;
            if (m>e) swap(m, e);
        }
    }
    m=max(m, 1);
    maxi=max(maxi, e+m+p-1);
    return max(e+p-1, 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            v[i]=0;
        }
        maxi=0;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
            sz[b].push_back(a);
        }
        dfs(1);
        cout << maxi << "\n";
    }
    return 0;
}