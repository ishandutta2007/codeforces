#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
const ll p=1e9+7;

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
ll dp[N][2],g[N];

int main()
{
	dp[0][0]=dp[0][1]=dp[1][0]=dp[1][1]=0;
	g[0]=g[1]=0;
	for (ll i=2;i<=2e6;i++)
	{
		dp[i][0]=(g[i-1]+2ll*g[i-2])%p;
		dp[i][1]=(dp[i-1][0]+2ll*dp[i-2][0]+(i>=3ll))%p;
		g[i]=max(dp[i][0],dp[i][1]);
	}
	ll T=read();
	while (T--)
	{
		ll n=read();
		print(g[n]*4ll%p);
	}

	return 0;
}