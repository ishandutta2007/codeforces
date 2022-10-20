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
	int l,r,val,pd;
}segt[N*8];
int n;
vector<pair<int,pair<ll,ll> > > qry;
vector<ll> allv;
void build_tree(int x,int l,int r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	segt[x].val=0;
	segt[x].pd=-2;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	return;
}
void upd(int x,int req)
{
	if(req==1)
	{
		segt[x].val=segt[x].r-segt[x].l+1;
		segt[x].pd=1;
	}
	else if(req==-1)
	{
		segt[x].val=0;
		segt[x].pd=-1;
	}
	else if(req==0)
	{
		segt[x].val=segt[x].r-segt[x].l+1-segt[x].val;
		segt[x].pd=((abs(segt[x].pd%2)^1))*(-2)-segt[x].pd;
	}
	return;
}
void push_down(int x)
{
	int a=x<<1;
	if(segt[x].pd==-2)
	{
		return;
	}
	upd(a,segt[x].pd);
	upd(a|1,segt[x].pd);
	segt[x].pd=-2;
	return;
}
void update(int x,int l,int r,int tp)
{
	int tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		upd(x,tp);
		push_down(x);
		return;
	}
	push_down(x);
	assert(segt[x].pd==-2);
	int mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(a,l,r,tp);
	}
	if(mid<r)
	{
		update(a|1,l,r,tp);
	}
	segt[x].val=segt[a].val+segt[a|1].val;
	return;
}
int query(int x,int l,int r)
{
	if(l==r)
	{
		return l;
	}
	push_down(x);
	int mid=(l+r)>>1,a=x<<1;
	if(segt[a].val==mid-l+1)
	{
		return query(a|1,mid+1,r);
	}
	return query(a,l,mid);
}
int main(){
	int i,t;
	ll l,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%lld%lld",&t,&l,&r);
		allv.push_back(l);
		allv.push_back(r+1);
		qry.push_back(make_pair(t,make_pair(l,r)));
	}
	allv.push_back(1);
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	build_tree(1,0,allv.size()-1);
	for(i=0;i<n;i++)
	{
		t=qry[i].F;
		l=lower_bound(allv.begin(),allv.end(),qry[i].S.F)-allv.begin();
		r=upper_bound(allv.begin(),allv.end(),qry[i].S.S)-allv.begin()-1;
		if(t==1)
		{
			update(1,l,r,1);
		}
		else if(t==2)
		{
			update(1,l,r,-1);
		}
		else
		{
			update(1,l,r,0);
		}
		printf("%lld\n",allv[query(1,0,allv.size()-1)]);
	}
	return 0;
}