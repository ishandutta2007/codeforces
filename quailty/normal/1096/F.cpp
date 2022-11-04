#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll Mod=998244353;
ll fp(ll a,ll k)
{
    if(k<0)
    {
        a=fp(a,Mod-2);
        k=-k;
    }
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
struct BIT
{
    int c[MAXN],n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    void add(int p)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]++;
    }
    int sum(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)
            res+=c[i];
        return res;
    }
}bit;
int p[MAXN],u[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]),u[i]=1;
    for(int i=1;i<=n;i++)
        if(p[i]>0)u[p[i]]=0;
    for(int i=1;i<=n;i++)
        u[i]+=u[i-1];
    bit.init(n);
    ll res=1LL*u[n]*(u[n]-1)%Mod*fp(4,Mod-2)%Mod;
    for(int i=n,j=0;i>=1;i--)
    {
        if(p[i]>0)
        {
            res=(res+bit.sum(p[i]))%Mod;
            bit.add(p[i]);
            res=(res+j*fp(u[n],Mod-2)%Mod*u[p[i]])%Mod;
            res=(res+(u[n]-j)*fp(u[n],Mod-2)%Mod*(u[n]-u[p[i]]))%Mod;
        }
        else j++;
    }
    printf("%lld\n",res);
    return 0;
}