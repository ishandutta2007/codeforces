//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
ll n,k,grid[N][N][2],dist[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j,l1,r1,l2,r2,x,y,d;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(i=0;i<=k;i++)
		{
			for(j=0;j<=k;j++)
			{
				dist[i][j]=LINF;
				grid[i][j][0]=grid[i][j][1]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>l1>>r1>>l2>>r2;
			grid[min(l1,l2)][min(r1,r2)][l1==l2]++;
		}
		//(x,y,0)->(k-x,k-y+1,0) , (x,y,1)->(k-x+1,k-y,1)
		priority_queue<pair<ll,pair<ll,ll> > > pq;
		pq.push(make_pair(0,make_pair(k/2,k/2)));
		dist[k/2][k/2]=0;
		while(!pq.empty())
		{
			x=pq.top().S.F,y=pq.top().S.S,d=-pq.top().F;
			pq.pop();
			if(dist[x][y]!=d)
			{
				continue;
			}
			//move up
			if(x>0&&dist[x-1][y]>d+grid[x][y][1]+grid[k-x+1][k-y][1])
			{
				dist[x-1][y]=d+grid[x][y][1]+grid[k-x+1][k-y][1];
				pq.push(make_pair(-dist[x-1][y],make_pair(x-1,y)));
			}
			//move left
			if(y>0&&dist[x][y-1]>d+grid[x][y][0]+grid[k-x][k-y+1][0])
			{
				dist[x][y-1]=d+grid[x][y][0]+grid[k-x][k-y+1][0];
				pq.push(make_pair(-dist[x][y-1],make_pair(x,y-1)));
			}
			//move down
			if(x<k&&dist[x+1][y]>d+grid[x+1][y][1]+grid[k-(x+1)+1][k-y][1])
			{
				dist[x+1][y]=d+grid[x+1][y][1]+grid[k-(x+1)+1][k-y][1];
				pq.push(make_pair(-dist[x+1][y],make_pair(x+1,y)));
			}
			//move right
			if(y<k&&dist[x][y+1]>d+grid[x][y+1][0]+grid[k-x][k-(y+1)+1][0])
			{
				dist[x][y+1]=d+grid[x][y+1][0]+grid[k-x][k-(y+1)+1][0];
				pq.push(make_pair(-dist[x][y+1],make_pair(x,y+1)));
			}
		}
		ll ans=LINF;
		for(i=0;i<=k;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(i==0||i==k||j==0||j==k)
				{
					ans=min(ans,dist[i][j]);
				}
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}