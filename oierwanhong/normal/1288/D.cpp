//By luogu send again.
#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
#define MAXN 300011
#define MAXM 9
ll a[MAXN][MAXM],f[MAXN];
ll n,m;
ll getval(ll i,ll k)
{
	ll res=0;
	for(ll j=1;j<=m;++j)
		if(a[i][j]>=k)res|=1<<(j-1);
	return res;
}
pll check(ll k)
{
	for(ll i=1;i<=n;++i)f[i]=getval(i,k);
	std::sort(f+1,f+n+1);
	ll nn=std::unique(f+1,f+n+1)-f-1,all=(1<<m)-1;
	for(ll i=1;i<=nn;++i)
		for(ll j=1;j<=i;++j)
			if((f[i]|f[j])==all)
			{
				pll res;
				for(ll p=1;p<=n;++p)
				{
					if(getval(p,k)==f[i])res.first=p;
					if(getval(p,k)==f[j])res.second=p;
				}
				return res;
			}
	return pll(-1,-1);
}
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)a[i][j]=read();
	ll l=0,r=ll(1e9),mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid).first>=0)l=mid;
		else r=mid-1;
	}
	pll res=check(l);
	printf("%lld %lld",res.first,res.second);
	return 0;
}