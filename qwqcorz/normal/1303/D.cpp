#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+1e3;
const ll inf=N;

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
bool b[100];
ll a[N],t[100];
ll turn(ll m)
{
	ll n=-1;
	for (ll i=0;i<100;i++) t[i]=b[i]=0;
	while (m)
	{
		b[++n]=m&1;
		m>>=1;
	}
	return n;
}

int main()
{
	ll T=read();
	while (T--)
	{
		ll m=read(),n=read();
		ll len=turn(m),Max=len;
		for (ll i=1;i<=n;i++)
		{
			a[i]=read();
			ll x=log2(a[i]);
			Max=max(Max,x);
			t[x]++;
		}
		ll now=0,low=inf,ans=0;
		for (ll i=0;i<=Max;i++)
		{
			now+=t[i];
			if (b[i])
			if (now==0) low=min(low,i);
				   else now--;
			if (now==0) continue;
			if (low<inf)
			{
				now--;
				ans+=i-low;
				low=inf;
			}
			now/=2;
		}
		if (low<inf) puts("-1");
				else print(ans);
	}

	return 0;
}