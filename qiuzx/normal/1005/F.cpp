#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 200010
using namespace std;
ll n,m,k,st[N],dep[N];
bool vis[N];
queue<ll> q;
vector<vector<ll> > ans;
vector<pair<ll,ll> > ed[N];
vector<ll> vt[N];
void dfs(ll x)
{
	ll i;
	if(x==n)
	{
		vector<ll> v;
		for(i=0;i<m;i++)
		{
			v.push_back(st[i]);
		}
		ans.push_back(v);
		return;
	}
	if(vt[x].empty())
	{
		dfs(x+1);
		return;
	}
	for(i=0;i<vt[x].size();i++)
	{
		st[vt[x][i]]=1;
		dfs(x+1);
		if(ans.size()>=k)
		{
			return;
		}
		st[vt[x][i]]=0;
	}
	return;
}
int main(){
	ll i,j,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		ed[x].push_back(make_pair(y,i));
		ed[y].push_back(make_pair(x,i));
	}
	q.push(0);
	dep[0]=0;
	vis[0]=true;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<ed[x].size();i++)
		{
			if(!vis[ed[x][i].F])
			{
				dep[ed[x][i].F]=dep[x]+1;
				q.push(ed[x][i].F);
				vis[ed[x][i].F]=true;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<ed[i].size();j++)
		{
			if(dep[ed[i][j].F]==dep[i]-1)
			{
				vt[i].push_back(ed[i][j].S);
			}
		}
	}
	dfs(0);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		for(j=0;j<ans[i].size();j++)
		{
			printf("%d",ans[i][j]);
		}
		putchar('\n');
	}
	return 0;
}