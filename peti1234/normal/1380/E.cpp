#include <bits/stdc++.h>

using namespace std;
const int c=400002;
int n, m, fel[c][21], szint[c], hv[c], t[c], kom[c], sum;
vector<int> sz[c];
void dfs(int a) {
    for (int i=1; i<=20; i++) fel[a][i]=fel[fel[a][i-1]][i-1];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        szint[x]=szint[a]+1, fel[x][0]=a;
        dfs(x);
    }
}
int main()
{
    cin >> n >> m, sum=n-1;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=m; i++) hv[i]=i;
    for (int i=1; i<m; i++) {
        int a, b, aa, bb;
        cin >> a >> b;
        sz[i+m].push_back(hv[a]), sz[i+m].push_back(hv[b]);
        hv[a]=i+m, hv[b]=i+m;
    }
    dfs(2*m-1);
    for (int i=1; i<n; i++) {
        int a=t[i], b=t[i+1];
        if (szint[a]<szint[b]) swap(a, b);
        for (int i=20; i>=0; i--) if (szint[fel[a][i]]>=szint[b]) a=fel[a][i];
        for (int i=20; i>=0; i--) if (fel[a][i]!=fel[b][i]) a=fel[a][i], b=fel[b][i];
        if (a!=b) a=fel[a][0];
        kom[max(a-m, 0)]++;
    }
    for (int i=0; i<m; i++) sum-=kom[i], cout << sum << "\n";
    return 0;
}