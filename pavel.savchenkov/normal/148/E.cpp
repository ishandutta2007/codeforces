#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int t[101][101];
int szt[101];

int n,m;
int d[101][101];
int dp[101][10001];
int s[101][101];

int sum(int i,int l,int r)
{
    if (l == 1) return s[i][r];
    return s[i][r] - s[i][l-1];
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&szt[i]);
        for (int j=1;j<=szt[i];j++)
            scanf("%d",&t[i][j]);
    }
    
    for (int i=1; i<=n; i++)
    {
        s[i][1] = t[i][1];
        for (int j=2; j<=szt[i]; j++)
            s[i][j] = s[i][j-1] + t[i][j];
    }
    
    for (int k=1; k<=n; k++)
    {
        for (int i=0; i<=szt[k]; i++) d[k][i] = 0;
        
        for (int i=1; i<=szt[k]; i++)
            for (int j=i+1; j<=szt[k]; j++)
                d[k][i+szt[k]-j+1] = max(d[k][i+szt[k]-j+1],sum(k,1,i) + sum(k,j,szt[k]));
            
        for (int i=1; i<=szt[k]; i++) d[k][i] = max(d[k][i],s[k][i]);
        for (int i=szt[k]; i>=1; i--) d[k][i] = max( d[k][i],sum(k,szt[k]-i+1,szt[k]) );
    }
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dp[i][j] = 0;
        
    for (int i=1; i<=szt[1]; i++) dp[1][i] = d[1][i];
    
    for (int i=1; i<n; i++)
     for (int j=0; j<=m; j++)
     {
        for (int k=0; k<=szt[i+1]; k++)
            if (j+k<=m) dp[i+1][j+k] = max(dp[i+1][j+k],dp[i][j] + d[i+1][k]);
     }
    
    cout << dp[n][m] << endl;
    return 0;
}