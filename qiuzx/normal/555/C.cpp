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
#define N 200010
using namespace std;
struct SegT{
	ll l,r,roof,pd;
}segt[8*N][2];
ll n,q;
map<ll,ll> taken;
vector<ll> qu;
vector<pair<pair<ll,ll>,ll> > que;
void build_tree(ll x,ll l,ll r)
{
	if(l>r)
	{
		return;
	}
	segt[x][0].l=segt[x][1].l=l;
	segt[x][0].r=segt[x][1].r=r;
	segt[x][0].roof=segt[x][1].roof=0;
	segt[x][0].pd=segt[x][1].pd=0;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	return;
}
void push_down(ll x,ll tp)
{
	ll a=x<<1;
	segt[a][tp].roof=max(segt[a][tp].roof,segt[x][tp].pd);
	segt[a][tp].pd=max(segt[a][tp].pd,segt[x][tp].pd);
	segt[a|1][tp].roof=max(segt[a|1][tp].roof,segt[x][tp].pd);
	segt[a|1][tp].pd=max(segt[a|1][tp].pd,segt[x][tp].pd);
	segt[x][tp].pd=0;
	return;
}
void update(ll x,ll l,ll r,ll v,ll tp)
{
	ll tl=segt[x][tp].l,tr=segt[x][tp].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x][tp].roof=max(segt[x][tp].roof,v);
		segt[x][tp].pd=max(segt[x][tp].pd,v);
		push_down(x,tp);
		return;
	}
	push_down(x,tp);
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(a,l,r,v,tp);
	}
	if(mid<r)
	{
		update(a|1,l,r,v,tp);
	}
	segt[x][tp].roof=max(segt[a][tp].roof,segt[a|1][tp].roof);
	return;
}
ll query(ll x,ll l,ll tp)
{
	ll tl=segt[x][tp].l,tr=segt[x][tp].r;
	if(tl>l||tr<l)
	{
		return 0;;
	}
	if(tl==l&&tr==l)
	{
		return segt[x][tp].roof;
	}
	push_down(x,tp);
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		return query(a,l,tp);
	}
	return query(a|1,l,tp);
}
int main(){
	ll x,y,i;
	char c;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld %lld %c",&x,&y,&c);
		qu.push_back(x);
		que.push_back(make_pair(make_pair(x,y),(c=='U')));
	}
	sort(qu.begin(),qu.end());
	qu.erase(unique(qu.begin(),qu.end()),qu.end());
	build_tree(1,0,qu.size()-1);
	for(i=0;i<que.size();i++)
	{
		if(taken.count(que[i].F.F))
		{
			puts("0");
			continue;
		}
		taken[que[i].F.F]=1;
		x=lower_bound(qu.begin(),qu.end(),que[i].F.F)-qu.begin();
		y=query(1,x,que[i].S);
		if(que[i].S==0)
		{
			printf("%lld\n",que[i].F.F-y);
			update(1,lower_bound(qu.begin(),qu.end(),y)-qu.begin(),x,que[i].F.S,1);
		}
		else
		{
			printf("%lld\n",que[i].F.S-y);
			update(1,x,upper_bound(qu.begin(),qu.end(),n-y+1)-qu.begin()-1,que[i].F.F,0);
		}
	}
	return 0;
}