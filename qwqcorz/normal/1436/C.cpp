#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
const ll p=1e9+7;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) c=getchar();
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll fact[N],inv[N];
ll P(ll n,ll m)
{
	if (n<m||n<0||m<0) return 0;
	return fact[n]*inv[n-m]%p;
}
ll power(ll a,ll b)
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

signed main()
{
	ll n=read(),x=read(),pos=read();

	fact[0]=1;
	for (ll i=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (ll i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;

	ll Less=0,More=0,l=0,r=n;
	while (l<r)
	{
		ll mid=(l+r)/2;
		if (mid==pos) l=mid+1;
		else if (mid<pos) Less++,l=mid+1;
		else More++,r=mid;
	}
	print(P(x-1,Less)*P(n-x,More)%p*fact[n-Less-More-1]%p);

	return 0;
}