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

signed main()
{
	ll T=read();
	while (T--)
	{
		ll x=read(),y=read(),ans=0,i;
		for (i=1;i*(i-1)-1<x&&i<=y+1;i++) ans+=max(min(x,i*(i-1)-1)/i,0ll);
		for (ll l=i,r;l<=y+1;l=r+1)
		{
			if (x/l==0) break;
			r=min(x/(x/l),y+1);
//			print(l,' ');
//			print(r);
			ans+=(x/l)*(r-l+1);
		}
		print(ans);
	}

	return 0;
}