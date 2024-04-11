#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e6+3;

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
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
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
ll down_power(ll a,ll b)
{
	ll ret=1;
	if (b>a) return 0;
	for (ll i=0;i<b;i++) ret=ret*(a-i)%p;
	return ret;
}
ll calc(ll n,ll k)
{
	ll ret=n;
	for (k=(k-1)/2;k;k/=2) ret+=k;
	return ret;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),k=read();
	if (n<=60&&(1LL<<n)<k) return puts("1 1"),0;
	ll y=power(power(2,n),k),x=(y-down_power(power(2,n),k)+p)%p;
	ll g=power(power(2,calc(n,k)),p-2);
	x=x*g%p,y=y*g%p;
	print(x,' '),print(y);
	
	return 0;
}