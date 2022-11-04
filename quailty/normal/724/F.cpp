#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int Mod,inv[1005];
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
    if(x<0)x+=Mod;
}
inline int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int dp[1005][15];
int main()
{
    int n,d;
    scanf("%d%d%d",&n,&d,&Mod);
    if(n<=2)return 0*printf("1");
    for(int i=1;i<=n;i++)
        inv[i]=fp(i,Mod-2);
    dp[1][0]=1;
    int res=0;
    for(int k=1;k<=n;k++)
        for(int i=n;i>=2;i--)
            for(int j=d;j>=1;j--)
            {
                int sum=0,now=1,cnt=(k>1 ? dp[k][d-1] : 1);
                for(int t=0;t<=j && t*k<i;t++)
                {
                    add(sum,1LL*now*dp[i-t*k][j-t]%Mod);
                    now=1LL*now*(cnt+t)%Mod*inv[t+1]%Mod;
                }
                dp[i][j]=sum;
                if(k==n/2 && i==n && j==d)add(res,dp[i][j]);
            }
    if(n%2==0)add(res,-1LL*dp[n/2][d-1]*(dp[n/2][d-1]-1)/2%Mod);
    printf("%d\n",res);
    return 0;
}