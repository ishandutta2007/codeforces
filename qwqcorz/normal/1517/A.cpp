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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
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
		ll n=read(),ans=0;
		if (n%2050) puts("-1");
		else
		{
			n/=2050;
			while (n)
			{
				ans+=n%10;
				n/=10;
			}
			print(ans);
		}
	}
	
	return 0;
}