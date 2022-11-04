#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int fp(int a,int k,int Mod)
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
int fac[250005],inv[250005];
int f[(1<<16)+5],dp[2][(1<<16)+5];
int main()
{
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    int res=fp(k,n,p);
    if(n&1)return 0*printf("%d\n",res);
    for(int i=(fac[0]=1);i<=n;i++)
        fac[i]=1LL*i*fac[i-1]%p;
    for(int i=0;i<=n;i++)
        inv[i]=fp(fac[i],p-2,p);
    vector<int> one;
    for(int i=0;i<30;i++)
        if(n>>i&1)one.push_back(1<<i);
    int t=(int)one.size();
    for(int i=0;i<(1<<t);i++)
    {
        for(int j=0;j<t;j++)
            if(i>>j&1)f[i]+=one[j];
        f[i]=inv[f[i]];
    }
    dp[0][0]=1;
    while(k)
    {
        if(k&1)
        {
            memset(dp[1],0,sizeof(dp[1]));
            for(int i=0;i<(1<<t);i++)
            {
                int sub=i,cnt=0;
                ull sum=0;
                do
                {
                    sum+=1LL*dp[0][sub]*f[i-sub];
                    if((++cnt)==18)sum%=p,cnt=0;
                    sub=(sub-1)&i;
                }
                while(sub!=i);
                dp[1][i]=sum%p;
            }
            memcpy(dp[0],dp[1],sizeof(dp[1]));
        }
        {
            memset(dp[1],0,sizeof(dp[1]));
            for(int i=0;i<(1<<t);i++)
            {
                int sub=i,cnt=0;
                ull sum=0;
                do
                {
                    sum+=1LL*f[sub]*f[i-sub];
                    if((++cnt)==18)sum%=p,cnt=0;
                    sub=(sub-1)&i;
                }
                while(sub!=i);
                dp[1][i]=sum%p;
            }
            memcpy(f,dp[1],sizeof(dp[1]));
        }
        k>>=1;
    }
    res=(res-1LL*dp[0][(1<<t)-1]*fac[n]%p+p)%p;
    return 0*printf("%d\n",res);
}