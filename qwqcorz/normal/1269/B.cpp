#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5;

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
ll n,m,a[N],b[N];
bool check(ll num)
{
	ll add=(b[num]-a[1]+m)%m;
	for (ll i=1;i<=n;i++)
	if ((a[i]+add)%m!=b[(i+num-2)%n+1]) return 0;
	return 1;
}

int main()
{
	a[0]=-1;
	n=read();
	m=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (ll i=1;i<=n;i++)
	if (check(i))
	{
		print((b[i]-a[1]+m)%m);
		return 0;
	}
}