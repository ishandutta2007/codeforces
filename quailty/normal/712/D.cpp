#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100105;
const int Mod=1000000007;
int fac[MAXN<<1],inv[MAXN<<1];
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
void build()
{
    for(int i=(fac[0]=1);i<2*MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<2*MAXN;i++)
        inv[i]=fp(fac[i],Mod-2);
}
int C(int n,int k)
{
    if(n<k)return 0;
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int cal(int k,int t,int x)
{
    int res=0;
    for(int i=0;i<=t;i++)
        res=(res+(i&1 ? -1LL : 1LL)*C(t,i)*C(x-i*(2*k+1)+t-1,t-1))%Mod;
    return (res+Mod)%Mod;
}
int cnt[MAXN<<1],pre[MAXN<<1];
int main()
{
    build();
    int a,b,k,t;
    scanf("%d%d%d%d",&a,&b,&k,&t);
    for(int i=0;i<=(2*k+1)*t;i++)
        cnt[i]=cal(k,t,i);
    memcpy(pre,cnt,sizeof(cnt));
    for(int i=1;i<=(2*k+1)*t;i++)
        pre[i]=(pre[i]+pre[i-1])%Mod;
    int res=0;
    for(int i=max(0,b-a+1);i<=(2*k+1)*t;i++)
        res=(res+1LL*cnt[i]*pre[min(i-(b-a+1),(2*k+1)*t)])%Mod;
    return 0*printf("%d",res);
}