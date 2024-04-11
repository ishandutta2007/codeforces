#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+1e3;
const ll inf=1e6+1e3;

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
bool b[N];
ll st[N],en[N],a[inf];

int main()
{
	memset(a,0,sizeof(a));
	ll n=read(),ans=0,tot=0;
	for (ll i=1;i<=n;i++)
	{
		b[i]=0;
		ll m=read(),last=inf;
		for (ll j=1;j<=m;j++)
		{
			ll now=read();
			if (j==1) st[i]=now;
			if (j==m) en[i]=now;
			if (now>last) b[i]=1; 
			last=now;
		}
		if (b[i]) tot++;
	}
	for (ll i=1;i<=n;i++) if (!b[i]) a[st[i]]++;
	a[1000001]=0;
	for (ll i=1000000;i>=0;i--) a[i]+=a[i+1];
	for (ll i=1;i<=n;i++) if (!b[i]) ans+=a[en[i]+1]+tot;
	print(ans+tot*n);

	return 0;
}