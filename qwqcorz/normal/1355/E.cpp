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
ll n,x,y,z,a[N];
ll check(ll h)
{
	ll t=0,s=0,ret=0;
	for (ll i=1;i<=n;i++)
	if (a[i]>h) t+=a[i]-h;
		   else s+=h-a[i];
	if (s<=t)
	{
		ret=s*z;
		t-=s;
		s=0;
	}
	else
	{
		ret=t*z;
		s-=t;
		t=0;
	}
	return ret+s*x+t*y;
}

int main()
{
	n=read();
	x=read();
	y=read();
	z=min(x+y,read());
	for (ll i=1;i<=n;i++) a[i]=read();
	ll l=0,r=(ll)1e9;
	while (l<r)
	{
		ll mid=(l+r)/2;
		if (check(mid)<check(mid+1)) r=mid;
								else l=mid+1;
	}
	print(min(check(l),check(r)));

	return 0;
}