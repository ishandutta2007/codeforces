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
#define N 35
using namespace std;
ll n,m,vans=0;
bool vis[N][N],tk[N],vis2[7][7],prt;
pair<ll,ll> adj[N][N],tsqs[N];
vector<pair<ll,ll> > squ;
char grid[N][N],ans[N][N],fans[N][N];
bool check()
{
	ll i,j,x,y,a,b;
	for(i=0;i<7;i++)
	{
		a=tsqs[i].F;
		b=tsqs[i].S;
		x=squ[a].F;
		y=squ[a].S;
		ans[x][y]=ans[x+1][y]=ans[x][y+1]=ans[x+1][y+1]=('0'+i);
		x=squ[b].F;
		y=squ[b].S;
		ans[x][y]=ans[x+1][y]=ans[x][y+1]=ans[x+1][y+1]=('0'+i);
	}
	memset(vis2,false,sizeof(vis2));
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(grid[i][j]!='.'&&(!vis[i][j]))
			{
				vis[i][j]=vis[adj[i][j].F][adj[i][j].S]=true;
				if(vis2[min(ans[i][j]-'0',ans[adj[i][j].F][adj[i][j].S]-'0')][max(ans[i][j]-'0',ans[adj[i][j].F][adj[i][j].S]-'0')])
				{
					return false;
				}
				vis2[min(ans[i][j]-'0',ans[adj[i][j].F][adj[i][j].S]-'0')][max(ans[i][j]-'0',ans[adj[i][j].F][adj[i][j].S]-'0')]=true;
			}
		}
	}
	return true;
}
void dfs(ll x)
{
	ll i,j;
	if(x==7)
	{
		if(check())
		{
			vans+=5040;
			if(!prt)
			{
				prt=true;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=m;j++)
					{
						fans[i][j]=ans[i][j];
					}
				}
			}
		}
		return;
	}
	for(i=0;i<14;i++)
	{
		if(!tk[i])
		{
			tk[i]=true;
			tsqs[x].F=i;
			break;
		}
	}
	for(i=0;i<14;i++)
	{
		if(!tk[i])
		{
			tk[i]=true;
			tsqs[x].S=i;
			dfs(x+1);
			tk[i]=false;
		}
	}
	tk[tsqs[x].F]=false;
	return;
}
int main(){
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(grid[i][j]=='.')
			{
				adj[i][j]=make_pair(-1,-1);
				continue;
			}
			if(grid[i-1][j]==grid[i][j])
			{
				adj[i][j]=make_pair(i-1,j);
			}
			else if(grid[i+1][j]==grid[i][j])
			{
				adj[i][j]=make_pair(i+1,j);
			}
			else if(grid[i][j-1]==grid[i][j])
			{
				adj[i][j]=make_pair(i,j-1);
			}
			else
			{
				adj[i][j]=make_pair(i,j+1);
			}
			if(vis[i][j])
			{
				continue;
			}
			squ.push_back(make_pair(i,j));
			vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=vis[i][j]=true;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			ans[i][j]=grid[i][j];
		}
	}
	dfs(0);
	cout<<vans<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<fans[i][j];
		}
		puts("");
	}
	return 0;
}