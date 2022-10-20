#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;

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
ll k1,k2;
void exgcd(ll x,ll y)
{
	if (y==0) return k1=1,k2=0,void();
	exgcd(y,x%y);
	ll X=k1,Y=k2;
	k1=Y;
	k2=X-x/y*Y;
}
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	return x/gcd(x,y)*y;
}
ll a[N],b[N],x[N],y[N],cnt=0;
ll t[N],cntt=0;

signed main()
{
	ll n=read(),m=read(),k=read();
	for (ll i=1;i<=n;i++) a[read()]=i;
	for (ll i=1;i<=m;i++) b[read()]=i;
	for (ll i=1;i<=2*max(n,m);i++) if (a[i]&&b[i])
	{
		++cnt;
		x[cnt]=a[i];
		y[cnt]=b[i];
	}
	for (ll i=1;i<=cnt;i++)
	{
		ll x=::x[i],y=::y[i];
		ll g=gcd(n,m),mm=m/g;
		if ((y-x)%g) continue;
		exgcd(n,m);
//		print(k1,' ');print(k2);
		k1*=(y-x)/g;
		k1=(k1%mm+mm)%mm;
		t[++cntt]=k1*n+x;
	}
	ll ans=(k-1)/(lcm(n,m)-cntt)*lcm(n,m);
	k=(k-1)%(lcm(n,m)-cntt)+1;
	sort(t+1,t+1+cntt);
//	for (ll i=1;i<=cntt;i++) print(t[i]);
	for (ll i=1;i<=cntt;i++)
	if (t[i]-t[i-1]-1<k)
	{
		k-=t[i]-t[i-1]-1;
		ans+=t[i]-t[i-1];
	}
	else
	{
		ans+=k;
		k=0;
	}
//	print(ans,',');print(k);
	ans+=k;
	print(ans);

	return 0;
}
/*
8 3 41
1 6 4 3 5 7 2 8
1 3 2

*/