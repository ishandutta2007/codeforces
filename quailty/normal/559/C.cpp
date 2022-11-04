#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2005;
const int MAXL=200000;
const int Mod=1000000007;
pair<int,int>b[MAXN];
int f[MAXL+5],inv[MAXL+5];
int dp[MAXN];
int fast_pow(int a,int k)
{
    int res=1;
    while(k>0)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int C(int n,int k)
{
    if(n<k)return 0;
    return 1LL*f[n]*inv[k]%Mod*inv[n-k]%Mod;
}
void build()
{
    f[0]=1;
    for(int i=1;i<=MAXL;i++)
        f[i]=1LL*i*f[i-1]%Mod;
    for(int i=0;i<=MAXL;i++)
        inv[i]=fast_pow(f[i],Mod-2);
}
int main()
{
    build();
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&b[i].first,&b[i].second);
    b[n]=make_pair(h,w);
    sort(b,b+n+1);
    for(int i=0;i<=n;i++)
    {
        dp[i]=C(b[i].first+b[i].second-2,b[i].first-1);
        for(int j=0;j<i;j++)
            if(b[j].second<=b[i].second)
            {
                dp[i]-=1LL*C((b[i].first-b[j].first)+(b[i].second-b[j].second),(b[i].first-b[j].first))*dp[j]%Mod;
                dp[i]=(dp[i]%Mod+Mod)%Mod;
            }
    }
    printf("%d\n",dp[n]);
    return 0;
}