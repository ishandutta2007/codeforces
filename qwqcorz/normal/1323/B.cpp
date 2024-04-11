#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e4+5;

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
ll a[N],b[N],as[N],bs[N];

int main()
{
	a[0]=b[0]=0;
	memset(as,0,sizeof(as));
	memset(bs,0,sizeof(bs));
	ll n=read(),m=read(),k=read(),ans=0;
	for (ll i=1;i<=n;i++) a[i]=a[i-1]+read();
	for (ll i=1;i<=m;i++) b[i]=b[i-1]+read();
	for (ll i=1;i<=n;i++) if (k%i==0)
	for (ll j=i;j<=n;j++) if (a[j]-a[j-i]==i) as[i]++;
	for (ll i=1;i<=m;i++) if (k%i==0)
	for (ll j=i;j<=m;j++) if (b[j]-b[j-i]==i) bs[i]++;
	for (ll i=1;i<=n;i++) if (k%i==0) ans+=as[i]*(k/i>m?0ll:bs[k/i]);
	print(ans);

	return 0;
}