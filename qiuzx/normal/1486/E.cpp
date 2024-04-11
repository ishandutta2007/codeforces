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
#define N 100010
using namespace std;
ll n,m,dp[N][60];
vector<pair<ll,ll> > vt[N];
priority_queue<pair<ll,pair<ll,ll> > > pq;
int main(){
	ll i,x,y,z,nx,ny;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	pq.push(make_pair(0,make_pair(0,0)));
	while(!pq.empty())
	{
		z=-pq.top().F;
		x=pq.top().S.F;
		y=pq.top().S.S;
		pq.pop();
		if(z!=dp[x][y])
		{
			continue;
		}
		for(i=0;i<vt[x].size();i++)
		{
			nx=vt[x][i].F;
			ny=vt[x][i].S+y;
			if(y==0)
			{
				if(dp[nx][ny]>z)
				{
					dp[nx][ny]=z;
					pq.push(make_pair(-z,make_pair(nx,ny)));
				}
			}
			else
			{
				if(dp[nx][0]>z+ny*ny)
				{
					dp[nx][0]=z+ny*ny;
					pq.push(make_pair(-dp[nx][0],make_pair(nx,0)));
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(dp[i][0]>=INF)
		{
			dp[i][0]=-1;
		}
		printf("%lld ",dp[i][0]);
	}
	puts("");
	return 0;
}