#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3005;
const int Mod=1000000007;
char s[MAXN][MAXN];
int dp[MAXN][MAXN];
void solve(int sx,int sy)
{
    memset(dp,0,sizeof(dp));
    dp[sx][sy]=(s[sx][sy]=='.');
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
        {
            if(s[i][j]=='#')continue;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%Mod;
            dp[i][j]=(dp[i][j]+dp[i][j-1])%Mod;
        }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    solve(1,2);
    int ax=dp[n-1][m],ay=dp[n][m-1];
    solve(2,1);
    int bx=dp[n][m-1],by=dp[n-1][m];
    int res=(1LL*ax*bx%Mod-1LL*ay*by%Mod+Mod)%Mod;
    return 0*printf("%d",res);
}