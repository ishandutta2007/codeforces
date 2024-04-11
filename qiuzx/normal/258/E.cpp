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
ll n,m,ans[N],din[N],dout[N],cnt=0;
vector<ll> vt[N],con[N];
struct SegT{
	ll l,r,mn,pd,num;
}segt[8*N];
void build_tree(ll l,ll r,ll x)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	segt[x].mn=segt[x].pd=0;
	segt[x].num=r-l+1;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(l,mid,a);
	build_tree(mid+1,r,a|1);
	return;
}
void push_down(ll x)
{
	ll a=x<<1;
	segt[x].mn+=segt[x].pd;
	segt[a].pd+=segt[x].pd;
	segt[a|1].pd+=segt[x].pd;
	segt[x].pd=0;
	return;
}
void update(ll l,ll r,ll x)
{
	ll tl=segt[x].l,tr=segt[x].r;
	ll mid=(tl+tr)>>1,a=x<<1;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].pd++;
		return;
	}
	push_down(x);
	if(mid>=l)
	{
		update(l,r,a);
	}
	if(mid<r)
	{
		update(l,r,a|1); 
	}
	segt[x].mn=min(segt[a].mn+segt[a].pd,segt[a|1].mn+segt[a|1].pd);
	segt[x].pd=0;
	segt[x].num=0;
	if(segt[x].mn==segt[a].mn+segt[a].pd)
	{
		segt[x].num+=segt[a].num;
	}
	if(segt[x].mn==segt[a|1].mn+segt[a|1].pd)
	{
		segt[x].num+=segt[a|1].num;
	}
	return;
}
void recall(ll l,ll r,ll x)
{
	ll tl=segt[x].l,tr=segt[x].r;
	ll mid=(tl+tr)>>1,a=x<<1;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].pd--;
		return;
	}
	push_down(x);
	if(mid>=l)
	{
		recall(l,r,a);
	}
	if(mid<r)
	{
		recall(l,r,a|1); 
	}
	segt[x].mn=min(segt[a].mn+segt[a].pd,segt[a|1].mn+segt[a|1].pd);
	segt[x].pd=0;
	segt[x].num=0;
	if(segt[x].mn==segt[a].mn+segt[a].pd)
	{
		segt[x].num+=segt[a].num;
	}
	if(segt[x].mn==segt[a|1].mn+segt[a|1].pd)
	{
		segt[x].num+=segt[a|1].num;
	}
	return;
}
void dfs(ll x,ll lst)
{
	ll i;
	din[x]=++cnt;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
		}
	}
	dout[x]=cnt;
	return;
}
void dfs2(ll x,ll lst)
{
	ll i;
	for(i=0;i<con[x].size();i++)
	{
		update(din[con[x][i]],dout[con[x][i]],1);
	}
	ans[x]=n-1;
	if(segt[1].mn==0)
	{
		ans[x]-=segt[1].num;
	}
	ans[x]=max(ans[x],(ll)0);
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs2(vt[x][i],x);
		}
	}
	for(i=0;i<con[x].size();i++)
	{
		recall(din[con[x][i]],dout[con[x][i]],1);
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		con[x].push_back(x);
		con[x].push_back(y);
		con[y].push_back(x);
		con[y].push_back(y);
	}
	for(i=0;i<n;i++)
	{
		sort(con[i].begin(),con[i].end());
		con[i].erase(unique(con[i].begin(),con[i].end()),con[i].end());
	}
	build_tree(1,cnt,1);
	dfs2(0,-1);
	for(i=0;i<n;i++)
	{
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}