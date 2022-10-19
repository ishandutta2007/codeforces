#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,k,din[N],dout[N],hea[N],tp[N],cnt=0,dif[N],dep[N],par[N],a[N],cnt2=0;
vector<pair<ll,ll> > ed;
vector<ll> vt[N];
map<pair<ll,ll>,ll> mp;
ll dfs(ll x,ll lst)
{
	ll i,j=-1,t,mx=0,sz=1;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			t=dfs(vt[x][i],x);
			if(mx<t)
			{
				mx=t;
				j=vt[x][i];
			}
			sz+=t;
		}
	}
	hea[x]=j;
	return sz;
}
void dfs2(ll x,ll lst,ll d)
{
	par[x]=lst;
	din[x]=++cnt;
	dep[x]=d;
	ll i;
	if(tp[x]==-1)
	{
		tp[x]=x;
	}
	if(hea[x]!=-1)
	{
		tp[hea[x]]=tp[x];
		mp[make_pair(x,hea[x])]=cnt2++;
		dfs2(hea[x],x,d+1);
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=hea[x]&&vt[x][i]!=lst)
		{
			mp[make_pair(x,vt[x][i])]=cnt2++;
			dfs2(vt[x][i],x,d+1);
		}
	}
	dout[x]=cnt;
	return;
}
void update(ll x,ll y)
{
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]])
		{
			swap(x,y);
		}
		if(x!=tp[x])
		{
			dif[mp[make_pair(tp[x],hea[tp[x]])]]++;
			dif[mp[make_pair(par[x],x)]+1]--;
		}
		dif[mp[make_pair(par[tp[x]],tp[x])]]++;
		dif[mp[make_pair(par[tp[x]],tp[x])]+1]--;
		x=par[tp[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	if(x!=y)
	{
		dif[mp[make_pair(x,hea[x])]]++;
		dif[mp[make_pair(par[y],y)]+1]--;
	}
	return;
}
ll getans(ll x,ll y)
{
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	return a[mp[make_pair(x,y)]];
}
int main(){
	ll x,y,i;
	memset(tp,-1,sizeof(tp));
	memset(hea,-1,sizeof(hea));
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		ed.push_back(make_pair(x,y));
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	dfs2(0,-1,0);
	scanf("%lld",&k);
	for(i=0;i<k;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		update(x,y);
	}
	for(i=0;i<=n;i++)
	{
		a[i]=a[max(i-1,(ll)0)]+dif[i];
	}
	for(i=0;i<ed.size();i++)
	{
		printf("%lld\n",getans(ed[i].F,ed[i].S));
	}
	return 0;
}