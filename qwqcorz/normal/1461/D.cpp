#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
map<ll,bool>can;
ll a[N],sum[N];
void solve(ll l,ll r)
{
	can[sum[r]-sum[l-1]]=1;
	ll mid=(a[l]+a[r])/2;
	ll Mid=upper_bound(a+l,a+r+1,mid)-a-1;
	if (r==Mid) return;
	solve(l,Mid);
	solve(Mid+1,r);
}

signed main()
{
	sum[0]=0;
	ll T=read();
	while (T--)
	{
		can.clear();
		ll n=read(),q=read();
		for (ll i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		for (ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		solve(1,n);
		for (ll i=1;i<=q;i++)
		{
			ll x=read();
			if (can.count(x)) puts("Yes");
						 else puts("No");
		}
	}

	return 0;
}