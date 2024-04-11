#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    x+=y,x=(x>=Mod ? x-Mod : (x<0 ? x+Mod : x));
}
char L[MAXN],R[MAXN];
int dp[MAXN][2][3],cof[MAXN],cnt[MAXN],sum[MAXN];
int cal(char str[])
{
    int n=strlen(str+1);
    memset(dp,0,sizeof(dp));
    dp[0][1][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            for(int k=4;k<=7;k+=3)
            {
                if(j && k+'0'<str[i])continue;
                int tj=(j && k+'0'==str[i]);
                add(dp[i][tj][0],dp[i-1][j][0]);
                add(dp[i][tj][1],(10LL*dp[i-1][j][1]+1LL*k*dp[i-1][j][0])%Mod);
                add(dp[i][tj][2],(100LL*dp[i-1][j][2]+20LL*k*dp[i-1][j][1]+1LL*k*k*dp[i-1][j][0])%Mod);
            }
    int res=(dp[n][0][2]+dp[n][1][2])%Mod;
    for(int i=n;i>=0;i--)
    {
        cnt[n-i]=(dp[i][0][0]+dp[i][1][0])%Mod;
        sum[n-i]=(dp[i][0][1]+dp[i][1][1])%Mod;
    }
    for(int i=0,j=1,k=0;i<n;i++,j=10LL*j%Mod,k=(10LL*k+7)%Mod)
        sum[i]=(1LL*j*sum[i]+1LL*k*cnt[i])%Mod;
    for(int i=0;i<n;i++)
    {
        add(sum[i],-sum[i+1]);
        add(res,1LL*sum[i]*cof[i]%Mod);
    }
    return res;
}
void build()
{
    cof[0]=3;
    for(int i=1;i<MAXN;i++)
        cof[i]=(10LL*cof[i-1]%Mod+Mod-3)%Mod;
}
int main()
{
    build();
    scanf("%s%s",L+1,R+1);
    printf("%d\n",(cal(L)-cal(R)+Mod)%Mod);
    return 0;
}