#include<bits/stdc++.h>
#define ll long long
using namespace std;

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
ll c[114514],cnt=0;

signed main()
{
	for (ll i=3;i*i<=2e9;i+=2) c[++cnt]=(i*i+1)/2;
	ll T=read();
	while (T--)
	{
		ll n=read();
		print(upper_bound(c+1,c+1+cnt,n)-c-1);
	}

	return 0;
}