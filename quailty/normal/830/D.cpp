#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=405;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
}
int dp[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int l=0,r=j;r>=0;l++,r--)
            {
                int t=1LL*dp[i-1][l]*dp[i-1][r]%Mod;
                add(dp[i][j+1],t);
                add(dp[i][j],t);
                add(dp[i][j],2LL*(l+r)*t%Mod);
                add(dp[i][j-1],1LL*(l+r)*(l+r-1)*t%Mod);
            }
    return 0*printf("%d",dp[n][1]);
}