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
ll a[N],sum1[N],sum2[N];

signed main()
{
	ll n=read(),q=read(),k=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=3;i<=n;i++)
	{
		sum1[i]+=a[i]-a[i-2]-2;
		sum2[i-2]+=a[i]-a[i-2]-2;
	}
	for (ll i=1;i<=n;i++) sum1[i]=sum1[i-1]+sum1[i];
	for (ll i=1;i<=n;i++) sum2[i]=sum2[i-1]+sum2[i];
	for (ll i=1;i<=q;i++)
	{
		ll l=read(),r=read();
		if (l==r) print(k-1);
			 else print(sum1[r]-sum2[l-1]+a[l+1]-2+k-a[r-1]-1);
	}

	return 0;
}