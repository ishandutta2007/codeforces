#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int Mod=998244353;
ll fac[MAXN],inv[MAXN];
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
ll C(int n,int k)
{
    return fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int main()
{
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    if(k>=n)return 0*printf("0\n");
    for(int i=(fac[0]=1);i<=n;i++)
        fac[i]=i*fac[i-1]%Mod;
    for(int i=0;i<=n;i++)
        inv[i]=fp(fac[i],Mod-2);
    ll res=0;
    for(int i=0;i<=n-k;i++)
        res=(res+(i&1 ? -1 : 1)*C(n-k,i)*fp(n-k-i,n))%Mod;
    res=(res+Mod)*C(n,n-k)%Mod;
    if(k)res=res*2%Mod;
    return 0*printf("%lld\n",(res+Mod)%Mod);
}