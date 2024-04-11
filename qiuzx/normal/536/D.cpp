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
#define N 2010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll n,m,st,ed,ds[N],dt[N],val[N],dp[N][N][2],sum_col[N][N],sum_row[N][N],sum_all[N][N],sza,szb,grid[N][N];
set<ll> dist;
vector<pair<ll,ll> > vt[N];
priority_queue<pair<ll,ll> > pq;
void get_dist()
{
	ll i,x,y;
	pq.push(make_pair(0,st));
	for(i=0;i<n;i++)
	{
		ds[i]=dt[i]=LINF;
	}
	ds[st]=dt[ed]=0;
	while(!pq.empty())
	{
		x=pq.top().S;
		if(pq.top().F!=(-ds[x]))
		{
			pq.pop();
			continue;
		}
		pq.pop();
		for(i=0;i<vt[x].size();i++)
		{
			y=vt[x][i].F;
			if(ds[y]>ds[x]+vt[x][i].S)
			{
				ds[y]=ds[x]+vt[x][i].S;
				pq.push(make_pair(-ds[y],y));
			}
		}
	}
	pq.push(make_pair(0,ed));
	while(!pq.empty())
	{
		x=pq.top().S;
		if(pq.top().F!=(-dt[x]))
		{
			pq.pop();
			continue;
		}
		pq.pop();
		for(i=0;i<vt[x].size();i++)
		{
			y=vt[x][i].F;
			if(dt[y]>dt[x]+vt[x][i].S)
			{
				dt[y]=dt[x]+vt[x][i].S;
				pq.push(make_pair(-dt[y],y));
			}
		}
	}
	return;
}
ll dfs(ll x,ll y,ll pl)
{
	if(x>=sza||y>=szb)
	{
		return 0;
	}
	if(dp[x][y][pl]!=-LINF)
	{
		return dp[x][y][pl];
	}
	ll a,tr;
	tr=(pl==0?(sum_row[x+1][szb]-sum_row[x+1][y]):(sum_col[sza][y+1]-sum_col[x][y+1]));
	a=dfs(x+(pl^1),y+pl,pl);
	dp[x][y][pl]=a+tr;
	a=dfs(x+(pl^1),y+pl,pl^1);
	if((pl==0&&sum_all[x+1][szb]-sum_all[x+1][y]!=sum_all[x][szb]-sum_all[x][y])||(pl==1&&sum_all[sza][y+1]-sum_all[x][y+1]!=sum_all[sza][y]-sum_all[x][y]))
	{
		dp[x][y][pl]=max(dp[x][y][pl],-a+tr);
	}
	return dp[x][y][pl];
}
int main(){
	ll i,j,x,y,z,cnt,nw,ans=-LINF;
	n=rint();
	m=rint();
	st=rint()-1;
	ed=rint()-1;
	for(i=0;i<n;i++)
	{
		val[i]=rint();
	}
	for(i=0;i<m;i++)
	{
		x=rint()-1;
		y=rint()-1;
		z=rint();
		if(x==y)
		{
			continue;
		}
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	get_dist();
	for(i=0;i<n;i++)
	{
		dist.insert(ds[i]);
	}
	for(i=0;i<n;i++)
	{
		cnt=0;
		for(set<ll>::iterator it=dist.begin();it!=dist.end();it++)
		{
			cnt++;
			if((*it)==ds[i])
			{
				ds[i]=cnt;
				break;
			}
		}
	}
	sza=dist.size();
	dist.clear();
	for(i=0;i<n;i++)
	{
		dist.insert(dt[i]);
	}
	for(i=0;i<n;i++)
	{
		cnt=0;
		for(set<ll>::iterator it=dist.begin();it!=dist.end();it++)
		{
			cnt++;
			if((*it)==dt[i])
			{
				dt[i]=cnt;
				break;
			}
		}
	}
	szb=dist.size();
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			grid[i][j]=-LINF;
		}
	}
	for(i=0;i<n;i++)
	{
		if(grid[ds[i]][dt[i]]==-LINF)
		{
			grid[ds[i]][dt[i]]=val[i];
		}
		else
		{
			grid[ds[i]][dt[i]]+=val[i];
		}
	}
	for(i=0;i<=n;i++)
	{
		sum_row[i][0]=0;
		sum_col[0][i]=0;
		sum_all[i][0]=0;
		for(j=1;j<=n;j++)
		{
			sum_row[i][j]=sum_row[i][j-1]+(grid[i][j]==-LINF?0:grid[i][j]);
			sum_col[j][i]=sum_col[j-1][i]+(grid[j][i]==-LINF?0:grid[j][i]);
			sum_all[i][j]=sum_all[i][j-1]+(grid[i][j]!=-LINF);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			sum_all[i][j]=sum_all[i-1][j]+sum_all[i][j];
		}
	}
	for(i=0;i<=sza;i++)
	{
		for(j=0;j<=szb;j++)
		{
			dp[i][j][0]=dp[i][j][1]=-LINF;
		}
	}
	ans=dfs(0,0,0);
	if(ans<0)
	{
		puts("Cry");
	}
	else if(ans==0)
	{
		puts("Flowers");
	}
	else
	{
		puts("Break a heart");
	}
	return 0;
}