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
#define N 2020
using namespace std;
bool vis[N];
ll n,m,x,y,lw[N],din[N],tp[N],chainlen=0,mmx,tot,leafnum=0,treenum=0,cnt=0,ans=0;
vector<pair<ll,ll> > ed;
vector<ll> vt[N],bri,sz[N],vt2[N];
map<ll,ll> mp;
void dfs(ll x,ll lst)
{
	vis[x]=true;
	din[x]=lw[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		if(vis[vt[x][i]])
		{
			lw[x]=min(lw[x],din[vt[x][i]]);
		}
		else
		{
			dfs(vt[x][i],x);
			lw[x]=min(lw[x],lw[vt[x][i]]);
		}
	}
	if(lw[x]==din[x]&&lst!=-1)
	{
		bri.push_back(min(x,lst)*n+max(x,lst));
		mp[min(x,lst)*n+max(x,lst)]=1;
	}
	return;
}
void dfs2(ll x)
{
	vis[x]=true;
	tp[x]=cnt;
	sz[cnt].push_back(x);
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i]])
		{
			continue;
		}
		if(mp[min(x,vt[x][i])*n+max(x,vt[x][i])]==1)
		{
			continue;
		}
		dfs2(vt[x][i]);
	}
	return;
}
ll dfs3(ll x)
{
	tot++;
	vis[x]=true;
	if(vt2[x].size()==1)
	{
		leafnum++;
	}
	else if(vt2[x].size()==0)
	{
		leafnum+=2;
	}
	ll i,a=0,b=0,val,mx=0;
	for(i=0;i<vt2[x].size();i++)
	{
		if(vis[vt2[x][i]])
		{
			continue;
		}
		val=dfs3(vt2[x][i]);
		mx=max(mx,val);
		if(val>a)
		{
			b=a;
			a=val;
		}
		else if(val>b)
		{
			b=val;
		}
	}
	chainlen=max(chainlen,a+b+1);
	return mx+1;
}
int main(){
	ll i;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		ed.push_back(make_pair(x,y));
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1);
		}
	}
	memset(vis,0,sizeof(vis));
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs2(i);
			cnt++;
		}
	}
	for(i=0;i<m;i++)
	{
		x=ed[i].F;
		y=ed[i].S;
		x=tp[x];
		y=tp[y];
		if(x!=y)
		{
			vt2[x].push_back(y);
			vt2[y].push_back(x);
		}
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<cnt;i++)
	{
		ans+=sz[i].size()-1;
		if(!vis[i])
		{
			treenum++;
			leafnum=0;
			chainlen=0;
			tot=0;
			dfs3(i);
			ans+=tot-chainlen-leafnum+2;
			//cout<<tot<<" "<<chainlen<<" "<<leafnum<<endl;
		}
	}
	printf("%lld\n",ans+treenum-1);
	return 0;
}