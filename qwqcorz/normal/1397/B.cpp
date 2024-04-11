#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
const ll inf=1ll<<60;

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
	ll n=read(),ans=inf;
	for (ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (ll k=1;1;k++)
	{
//		if (k%1000==0) print(k);
		bool flag=1;
		ll now=1,tot=0;
		for (ll i=1;i<=n;i++)
		{
			if (now>1000000000000ll)
			{
				flag=0;
				break;
			}
			tot+=llabs(a[i]-now);
			now*=k;
		}
		if (!flag) break;
		ans=min(ans,tot);
	}
	print(ans);

	return 0;
}