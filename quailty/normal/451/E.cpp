#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=20;
const ll Mod=1000000007LL;
ll f[MAXN],inv[MAXN];
ll C(ll n,ll k)
{
    if(k>n)return 0;
    ll res=1;
    for(int i=1;i<=k;i++)
    {
        res=(n-i+1)%Mod*res%Mod;
        res=res*inv[i]%Mod;
    }
    return res;
}
int main()
{
    for(int i=(inv[1]=1)+1;i<MAXN;i++)
        inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
    ll n,s;
    scanf("%lld%lld",&n,&s);
    for(int i=0;i<n;i++)
        scanf("%lld",&f[i]);
    ll res=0;
    for(int i=0;i<(1<<n);i++)
    {
        ll k=1,t=s;
        for(int j=0;j<n;j++)
            if(i&(1<<j))k=-k,t-=f[j]+1;
        res=(res+k*C(t+n-1,n-1))%Mod;
    }
    return 0*printf("%lld",(res+Mod)%Mod);
}