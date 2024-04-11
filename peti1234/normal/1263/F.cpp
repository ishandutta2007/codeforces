#include <bits/stdc++.h>

using namespace std;
int n, a;
int mely[2001];
int f[2001];
int k[2001];
int v[2001];
int inv[2001];
int dp[2001][2001][2];
int ans[2001][2001][2];
vector<int> sz[2001];
int t[2001];
void dfs(int a)
{
    if (!sz[a].size()) {
        k[a]=inv[a], v[a]=inv[a];
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        mely[x]=mely[a]+1;
        dfs(x);
        k[a]=min(k[a], k[x]);
        v[a]=max(v[a], v[x]);
    }
}
void sol(int a, int q)
{
    int x=t[a];
    int z=mely[x];
    int p=a-1;
    dp[a][0][q]=z;
    int y=x;
    int db=0;
    while(y!=1) {
        y=f[y];
        db++;
        for (int i=k[y]; i<=p; i++) {
            dp[a][i][q]=db;
        }
        p=k[y]-1;
    }
}
int main()
{
    cin >> n;
    int sum=-2;
    for (int q=0; q<=1; q++) {
        cin >> a;
        sum+=a;
        for (int i=1; i<=a; i++) {
            sz[i].clear();
        }
        for (int i=2; i<=a; i++) {
            int x;
            cin >> x;
            sz[x].push_back(i);
            f[i]=x;
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            inv[t[i]]=i;
        }
        for (int i=1; i<=a; i++) {
            k[i]=2001, v[i]=0;
        }
        dfs(1);
        for (int i=1; i<=n; i++) {
            sol(i, q);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            ans[i][j][0]=10001;
            ans[i][j][1]=10001;
        }
    }
    ans[1][0][0]=dp[1][0][0];
    ans[1][0][1]=dp[1][0][1];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<i-1; j++) {
            ans[i][i-1][0]=min(ans[i][i-1][0], ans[i-1][j][1]+dp[i][j][0]);
            ans[i][j][0]=min(ans[i][j][0], ans[i-1][j][0]+dp[i][i-1][0]);
            ans[i][i-1][1]=min(ans[i][i-1][1], ans[i-1][j][0]+dp[i][j][1]);
            ans[i][j][1]=min(ans[i][j][1], ans[i-1][j][1]+dp[i][i-1][1]);
        }
    }
    int mini=INT_MAX;
    for (int i=0; i<n; i++) {
        mini=min({mini, ans[n][i][0], ans[n][i][1]});
    }
    cout << sum-mini << "\n";

    return 0;
}