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
#define N 55
using namespace std;
ll n,m,g1,g2,s1,s2,dist[N][N],hsh[N][N],mn[N],mx[N],dp[N][N][N];
bool graph[N][N],gpos[N],spos[N],bpos[N];
ll get_dp(ll gold,ll bron,ll sill,ll silr)// 
{
	ll i,j,k,ret=0;
	memset(gpos,false,sizeof(gpos));
	memset(spos,false,sizeof(spos));
	memset(bpos,false,sizeof(bpos));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(hsh[i][j]<=gold)
			{
				gpos[i]=true;
			}
			if(hsh[i][j]>sill&&hsh[i][j]<silr)
			{
				spos[i]=true;
			}
			if(hsh[i][j]>=bron)
			{
				bpos[i]=true;
			}
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			for(k=0;j+k<=i;k++)
			{
				if(j>0&&gpos[i-1])
				{
					dp[i][j][k]+=dp[i-1][j-1][k];
				}
				if(k>0&&spos[i-1])
				{
					dp[i][j][k]+=dp[i-1][j][k-1];
				}
				if(bpos[i-1]&&j+k<i)
				{
					dp[i][j][k]+=dp[i-1][j][k];
				}
			}
		}
	}
	for(i=g1;i<=g2;i++)
	{
		for(j=s1;j<=s2;j++)
		{
			ret+=dp[n][i][j];
		}
	}
	return ret;
}
int main(){
	ll i,j,k,x,y,z,ans=0;
	scanf("%lld%lld",&n,&m);
	memset(dist,63,sizeof(dist));
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		graph[x][y]=graph[y][x]=true;
		dist[x][y]=dist[y][x]=z;
	}
	for(i=0;i<n;i++)
	{
		dist[i][i]=0;
	}
	scanf("%lld%lld%lld%lld",&g1,&g2,&s1,&s2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				dist[j][k]=min(dist[j][k],dist[i][j]+dist[i][k]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			hsh[i][j]=dist[i][j]*n+i;
		}
	}
	memset(mn,127,sizeof(mn));
	memset(mx,-127,sizeof(mx));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			mn[i]=min(mn[i],hsh[i][j]);//minimum possible score
			mx[i]=max(mx[i],hsh[i][j]);//maximum ...
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ans+=get_dp(mn[i],mx[j],mn[i],mx[j])-get_dp(mn[i],mx[j]+1,mn[i],mx[j])-get_dp(mn[i]-1,mx[j],mn[i],mx[j])+get_dp(mn[i]-1,mx[j]+1,mn[i],mx[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}