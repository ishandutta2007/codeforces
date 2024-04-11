#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;
const ll p=1e9+7;

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
ll a[N],pw[N],ans=0;

signed main()
{
	ll n=read();
	for (ll i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*2%p;
	for (ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (ll i=1;i<=n;i++) ans=(ans+a[i]*pw[i-1]%p-a[i]*pw[n-i]%p+p)%p;
	print(ans);

	return 0;
}