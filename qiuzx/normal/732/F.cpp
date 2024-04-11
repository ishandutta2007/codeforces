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
#define N 400010
using namespace std;
bool vis[N]; 
ll n,m,lw[N],din[N],tp[N],cnt=0,ans[N],mxnd=-1;
vector<pair<ll,ll> > vt[N],bri,vt2[N],ed;
vector<ll> sz[N];
map<ll,ll> mp;
void dfs(ll x,ll lst,ll ed)
{
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			if(vis[vt[x][i].F])
			{
				lw[x]=min(lw[x],din[vt[x][i].F]);
			}
			else
			{
				dfs(vt[x][i].F,x,vt[x][i].S);
				lw[x]=min(lw[x],lw[vt[x][i].F]);
			}
		}
	}
	if(lw[x]==din[x]&&x!=0)
	{
		bri.push_back(make_pair(min(x,lst)*n+max(x,lst),ed));
		mp[min(x,lst)*n+max(x,lst)]=1;
	}
	return;
}
void dfs2(ll x)
{
	vis[x]=true;
	tp[x]=cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(mp[min(x,vt[x][i].F)*n+max(x,vt[x][i].F)]==1)
		{
			continue;
		}
		ans[vt[x][i].S]=x*n+vt[x][i].F;
		if(vis[vt[x][i].F])
		{
			continue;
		}
		dfs2(vt[x][i].F);
	}
	sz[cnt].push_back(x);
	return;
}
void dfs3(ll x,ll lst)
{
	ll i;
	for(i=0;i<vt2[x].size();i++)
	{
		if(vt2[x][i].F!=lst)
		{
			if(tp[ed[vt2[x][i].S].S]==x)
			{
				ans[vt2[x][i].S]=ed[vt2[x][i].S].F*n+ed[vt2[x][i].S].S;
			}
			else
			{
				ans[vt2[x][i].S]=ed[vt2[x][i].S].S*n+ed[vt2[x][i].S].F;
			}
			dfs3(vt2[x][i].F,x);
		}
	}
	return;
}
int main(){
	ll i,j,x,y,mx;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
		ed.push_back(make_pair(x,y));
	}
	dfs(0,-1,-1);
	memset(vis,false,sizeof(vis));
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs2(i);
			cnt++;
		}
	}
	mx=0;
	for(i=0;i<cnt;i++)
	{
		if(sz[i].size()>mx)
		{
			mx=sz[i].size();
			mxnd=i;
		}
	}
	for(i=0;i<bri.size();i++)
	{
		x=bri[i].F/n;
		y=bri[i].F%n;
		x=tp[x];
		y=tp[y];
		vt2[x].push_back(make_pair(y,bri[i].S));
		vt2[y].push_back(make_pair(x,bri[i].S));
	}
	dfs3(mxnd,-1);
	printf("%lld\n",mx);
	for(i=0;i<ed.size();i++)
	{
		printf("%lld %lld\n",ans[i]/n+1,ans[i]%n+1);
	}
	return 0;
}