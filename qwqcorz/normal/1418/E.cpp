#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll p=998244353;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
inline ll power(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
ll d[N],sum[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) d[i]=read();
	sort(d+1,d+1+n);
	for (ll i=1;i<=n;i++) sum[i]=(sum[i-1]+d[i])%p;
	for (ll i=1;i<=m;i++)
	{
		ll a=read(),b=read();
		ll x=lower_bound(d+1,d+1+n,b)-d-1;
		ll cnt=n-x;
		if (cnt<a) puts("0");
		else
		{
			ll ans=(sum[n]-sum[x]+p)%p*(cnt-a)%p*power(cnt,p-2)%p;
			ans=(ans+sum[x]*(cnt+1-a)%p*power(cnt+1,p-2))%p;
			print(ans);
		}
	}
	
	return 0;
}