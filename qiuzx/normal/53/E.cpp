#pragma GCC optimize(2)
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
#define N 1040
using namespace std;
ll n,m,k,ans=0,dp[N][N];
bool ed[15][15];
ll dfs(ll mask1,ll mask2)
{
	if(dp[mask1][mask2]!=-1)
	{
		return dp[mask1][mask2];
	}
	ll i,j,pre1,pre2;
	if(__builtin_popcount(mask1)==2)
	{
		for(i=0;i<n;i++)
		{
			if(mask1&(1<<i))
			{
				pre1=i;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(mask1&(1<<i))
			{
				pre2=i;
			}
		}
		if(mask2==mask1&&ed[pre1][pre2])
		{
			dp[mask1][mask2]=1;
		}
		else
		{
			dp[mask1][mask2]=0;
		}
		return dp[mask1][mask2];
	}
	dp[mask1][mask2]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(ed[i][j]&&(mask1&(1<<i))&&(mask1&(1<<j)))//connect an edge from i->j (j is the new leaf)
			{
				if(!(mask2&(1<<j)))
				{
					continue;
				}
				if(mask2&(1<<i))
				{
					continue;
				}
				if((1<<j)>((mask2)&(-mask2)))
				{
					continue;
				}
				pre1=mask1^(1<<j);
				//i is the original leaf
				pre2=(mask2^(1<<j))|(1<<i);
				dp[mask1][mask2]+=dfs(pre1,pre2);
				//i isn't the original leaf
				pre2=mask2^(1<<j);
				dp[mask1][mask2]+=dfs(pre1,pre2);
			}
		}
	}
	return dp[mask1][mask2];
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		ed[x][y]=ed[y][x]=true;
	}
	memset(dp,-1,sizeof(dp));
	for(i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==k)
		{
			ans+=dfs((1<<n)-1,i);
		}
	}
	/*for(i=0;i<(1<<n);i++)
	{
		for(j=i;j>0;j=(j-1)&i)
		{
			if(dp[i][j]>=0)
			{
				cout<<i<<" "<<j<<": "<<dp[i][j]<<endl;
			}
		}
	}*/
	printf("%lld\n",ans);
	return 0;
}