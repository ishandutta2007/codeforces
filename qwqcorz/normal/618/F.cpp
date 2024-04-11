#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const ll N=1e6+5;

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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
bool flag=0;
ll a[N],b[N];
pair<ll,ll>f[N];
void output(ll l1,ll r1,ll l2,ll r2)
{
	if (flag) swap(l1,l2),swap(r1,r2);
	print(r1-l1);
	for (ll i=l1+1;i<=r1;i++) print(i,' ');
	puts("");
	print(r2-l2);
	for (ll i=l2+1;i<=r2;i++) print(i,' ');
	puts("");
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	memset(f,-1,sizeof(f));
	ll n=read();
	for (ll i=1;i<=n;i++) a[i]=a[i-1]+read();
	for (ll i=1;i<=n;i++) b[i]=b[i-1]+read();
	if (a[n]>b[n]) swap(a,b),flag=1;
	for (ll i=0,j=0;i<=n;i++)
	{
		while (j<=n&&b[j+1]<a[i]+n) j++;
		if (f[b[j]-a[i]].fi>=0)
		{
			output(f[b[j]-a[i]].fi,i,f[b[j]-a[i]].se,j);
			return 0;
		}
		else f[b[j]-a[i]]=mk(i,j);
	}

	return 0;
}