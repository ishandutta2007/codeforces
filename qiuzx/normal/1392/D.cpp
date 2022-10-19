#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,dp[N][4][4];
char buf[N];
string s;
bool pos(ll dir,ll l,ll r)
{
	ll x1,x2;
	if(r<2)
	{
		x1=0;
	}
	else
	{
		x1=1;
	}
	if(l%2==0)
	{
		x2=1;
	}
	else
	{
		x2=0;
	}
	if(x1==dir&&x1==x2)
	{
		return false;
	}
	return true;
}
int main(){
	ll T,i,j,k,ans;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		scanf("%s",&buf);
		s=buf;
		for(i=0;i<n;i++)
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					dp[i][j][k]=LINF;
				}
			}
		}
		dp[1][0][0]=(s[0]!='L')+(s[1]!='R');
		dp[1][1][1]=(s[0]!='L')+(s[1]!='L');
		dp[1][2][2]=(s[0]!='R')+(s[1]!='R');
		dp[1][3][3]=(s[0]!='R')+(s[1]!='L');
		for(i=2;i+1<n;i++)
		{
			for(k=0;k<4;k++)
			{
				dp[i][0][k]=min(dp[i][0][k],min(dp[i-1][1][k],dp[i-1][3][k])+(s[i]!='R'));
				dp[i][1][k]=min(dp[i][1][k],dp[i-1][3][k]+(s[i]!='L'));
				dp[i][2][k]=min(dp[i][2][k],dp[i-1][0][k]+(s[i]!='R'));
				dp[i][3][k]=min(dp[i][3][k],min(dp[i-1][0][k],dp[i-1][2][k])+(s[i]!='L'));
			}
		}
		ans=LINF;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(j!=1&&k!=1&&pos(0,j,k))
				{
					ans=min(ans,dp[n-2][j][k]+(s[n-1]!='L'));
				}
			}
		}
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(j!=2&&k!=2&&pos(1,j,k))
				{
					ans=min(ans,dp[n-2][j][k]+(s[n-1]!='R'));
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}