#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
ll f[1000005],inv[1000005];
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
void build()
{
    f[0]=1;
    for(int i=1;i<=1000000;i++)
        f[i]=f[i-1]*i%Mod;
    for(int i=0;i<=1000000;i++)
        inv[i]=fp(f[i],Mod-2);
}
ll C(int n,int k)
{
    if(k>n)return 0LL;
    return f[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int s[15];
bool check(int sum,int a,int b)
{
    int cnt=0;
    while(sum)
    {
        s[cnt++]=sum%10;
        sum/=10;
    }
    for(int i=0;i<cnt;i++)
        if(s[i]!=a && s[i]!=b)
            return 0;
    return 1;
}
int main()
{
    build();
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        int sum=a*i+b*(n-i);
        if(check(sum,a,b))
            ans=(ans+C(n,i))%Mod;
    }
    printf("%I64d\n",ans);
    return 0;
}