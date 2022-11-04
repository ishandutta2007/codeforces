#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
int fp(int a,int k)
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
int f[5005],dp[5005];
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(y%x)return 0*printf("0\n");
    y/=x;
    int cnt=0;
    for(int i=1;i*i<=y;i++)if(y%i==0)
    {
        f[cnt++]=i;
        if(i*i!=y)f[cnt++]=y/i;
    }
    sort(f,f+cnt);
    for(int i=0;i<cnt;i++)
        dp[i]=fp(2,y/f[i]-1);
    for(int i=cnt-1;i>=0;i--)
        for(int j=0;j<i;j++)
            if(f[i]%f[j]==0)
                dp[j]=(dp[j]-dp[i]+Mod)%Mod;
    return 0*printf("%d\n",dp[0]);
}