#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;

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
struct node
{
	ll t,b;
	bool operator <(const node &a)const
	{
		return b>a.b;
	}
}a[N];
priority_queue<ll,vector<ll>,greater<ll> >h;

int main()
{
	ll n=read(),k=read(),sum=0,ans=0;
	for (ll i=1;i<=n;i++)
	{
		a[i].t=read();
		a[i].b=read();
	}
	sort(a+1,a+1+n);
	for (ll i=1;i<=n;i++)
	{
		sum+=a[i].t;
		h.push(a[i].t);
		if (i>k)
		{
			sum-=h.top();
			h.pop();
		}
		ans=max(ans,sum*a[i].b);
	}
	print(ans);

	return 0;
}