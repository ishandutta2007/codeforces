//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,k,dp[N],trs[N][20],cang[N][20];
string s;
char buf[N];
bool check(ll x)
{
	ll i,j;
	for(i=0;i<k;i++)
	{
		cang[n][i]=n;
	}
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='?')
		{
			for(j=0;j<k;j++)
			{
				cang[i][j]=cang[i+1][j];
			}
		}
		else
		{
			for(j=0;j<k;j++)
			{
				if((s[i]-'a')==j)
				{
					cang[i][j]=cang[i+1][j];
				}
				else
				{
					cang[i][j]=i;
				}
			}
		}
	}
	for(i=0;i<k;i++)
	{
		trs[n][i]=n;
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<k;j++)
		{
			trs[i][j]=trs[i+1][j];
			if(cang[i][j]-i>=x)
			{
				trs[i][j]=min(trs[i][j],i+x-1);
			}
		}
	}
	for(i=0;i<(1<<k);i++)
	{
		dp[i]=INF;
	}
	dp[0]=0;
	for(i=0;i<(1<<k);i++)
	{
		if(dp[i]>=n)
		{
			continue;
		}
		for(j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				continue;
			}
			dp[i|(1<<j)]=min(dp[i|(1<<j)],trs[dp[i]][j]+1);
		}
	}
	if(dp[(1<<k)-1]<=n)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,j,l,r,mid;
	scanf("%lld%lld",&n,&k);
	scanf("%s",&buf);
	s=buf;
	l=0;
	r=n+1;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	printf("%lld\n",l);
	return 0;
}