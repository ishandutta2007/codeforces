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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N],lsum[N],rsum[N];
pair<ll,ll>l[N],r[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),q=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++) lsum[i]=lsum[i-1]+a[i];
	for (ll i=n;i>=1;i--) rsum[i]=rsum[i+1]+a[i];
	while (q--)
	{
		ll k=read(),ans=n;
		for (ll i=1,j=1,sum=a[1];i<=n;sum+=a[++i])
		{
			while (sum>k) sum-=a[j++];
			if (j==1) l[i]=mk(i,0);
			else l[i]=mk(l[j-1].fi,l[j-1].se+1);
		}
		for (ll i=n,j=n,sum=a[n];i>=1;sum+=a[--i])
		{
			while (sum>k) sum-=a[j--];
			if (j==n) r[i]=mk(i,0);
			else r[i]=mk(r[j+1].fi,r[j+1].se+1);
		}
		for (ll i=0;i<n;i++) ans=min(ans,l[i].se+r[i+1].se+1+(lsum[l[i].fi]+rsum[r[i+1].fi]>k));
		print(ans);
	}
	
	return 0;
}