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
ll a[N];

int main()
{
	ll n=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	puts("1 1");
	print(-a[1]);
	if (n==1)
	{
		puts("1 1\n0");
		puts("1 1\n0");
		return 0;
	}
	print(2,' ');
	print(n);
	for (ll i=2;i<=n;i++) print(a[i]*(n-1),' ');
	puts("");
	print(1,' ');
	print(n);
	print(0,' ');
	for (ll i=2;i<=n;i++) print(-a[i]*n,' ');

	return 0;
}