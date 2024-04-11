#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
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
ll dp[N],a[N],one[N],two[N];

int main()
{
	ll n=read(),r1=read(),r2=read(),r3=read(),d=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++) dp[i]=inf;
	dp[0]=d*(n-1);
	for (ll i=1;i<=n;i++) one[i]=a[i]*r1+r3;
	for (ll i=1;i<=n;i++) two[i]=min(one[i],min(a[i]*r1+r1,r2)+r1);
	for (ll i=1;i<=n;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+one[i]);
		dp[i]=min(dp[i],dp[i-1]+two[i]+d*2);
		if (i>1) dp[i]=min(dp[i],dp[i-2]+two[i-1]+two[i]+d*2);
	}
	ll ans=dp[n],now=min(one[n],two[n]+2*d);
	for (int i=n-1;i>=1;i--)
	{
		ans=min(ans,dp[i]+now);
		now+=two[i]+d;
	}
	print(ans);

	return 0;
}