#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 200011
ll n,k,nxt[MAXN],f[MAXN];
char s[MAXN];
int main()
{
    int n,k;scanf("%d%d%s",&n,&k,s+1);
    nxt[n+1]=ll(1e9);
    for(ll i=n;i;--i)nxt[i]=(s[i]=='1'?i:nxt[i+1]);
    for(ll i=1;i<=n;++i)
    {
        f[i]=f[i-1]+i;
        ll pos=nxt[std::max(1ll,i-k)];
        if(pos<=i+k)f[i]=std::min(f[i],f[std::max(1ll,pos-k)-1]+pos);
    }
    printf("%lld",f[n]);
}