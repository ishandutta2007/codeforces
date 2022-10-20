#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e3+5;
const ll p=998244353;

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
ll tot[N],dp[N];

int main()
{
	tot[0]=0;
	ll n=read(),m=read(),ans=0;
	for (ll i=1;i<=n;i++)
	{
		dp[0]=1;
		for (ll j=1;j<=n;j++) dp[j]=0;
		for (ll j=1,sum=1;j<=n;j++)
		{
			if (j>i) sum=(sum-dp[j-i-1]+p)%p;
			dp[j]=sum;
			sum=(sum+dp[j])%p;
		}
		tot[i]=dp[n];
	}
	for (ll i=1;i<=min(n,m);i++)
	ans=(ans+(tot[i]-tot[i-1]+p)%p*tot[min((m-1)/i,n)]%p*2%p)%p;
	print(ans);

	return 0;
}