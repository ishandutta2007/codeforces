#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+5;

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
ll x[N],y[N];

signed main()
{
	ll T=read();
	while (T--)
	{
		ll n=read();
		for (ll i=1;i<=n;i++)
		{
			x[i]=read();
			y[i]=read();
		}
		if (n&1) print(1);
		else
		{
			sort(x+1,x+1+n);
			sort(y+1,y+1+n);
			print((x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1));
		}
	}

	return 0;
}