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
#define ll int
#define N 200010
using namespace std;
ll n,k,b[N],q;
vector<ll> allv,val;
vector<pair<pair<ll,ll>,ll> > qry;
/***************************************************************************************************/
struct SegT1{
	ll l,r,val;
}mval[N*4];
void build1(ll x,ll l,ll r)
{
	mval[x].l=l;
	mval[x].r=r;
	if(l==r)
	{
		mval[x].val=b[l];
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build1(a,l,mid);
	build1(a|1,mid+1,r);
	mval[x].val=min(mval[a].val,mval[a|1].val);
	return;
}
ll query1(ll x,ll l,ll r)
{
	ll tl=mval[x].l,tr=mval[x].r;
	if(tl>r||tr<l)
	{
		return MOD;//just in case x=1e9
	}
	if(l<=tl&&tr<=r)
	{
		return mval[x].val;
	}
	ll a=x<<1,mid=(tl+tr)>>1,ret=MOD;
	if(mid>=l)
	{
		ret=min(ret,query1(a,l,r));
	}
	if(mid<r)
	{
		ret=min(ret,query1(a|1,l,r));
	}
	return ret;
}
/***************************************************************************************************/
struct SegT{
	ll l,r,val,pd;
}segt[N*8];
void build_tree(ll x,ll l,ll r)
{
	segt[x].l=l;
	segt[x].r=r;
	segt[x].pd=-1;//no set
	if(l==r)
	{
		segt[x].val=val[l];
		return;
	}
	ll a=x<<1,mid=(l+r)>>1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	segt[x].val=min(segt[a].val,segt[a|1].val);
	return;
}
void push_down(ll x)
{
	if(segt[x].pd==-1)
	{
		return;
	}
	ll a=x<<1;
	segt[a].pd=segt[x].pd;
	segt[a|1].pd=segt[x].pd;
	segt[a].val=segt[x].pd;
	segt[a|1].val=segt[x].pd;
	segt[x].pd=-1;
	return;
}
void update(ll x,ll l,ll r,ll v)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].val=v;
		segt[x].pd=v;
		return;
	}
	push_down(x);
	ll a=x<<1,mid=(tl+tr)>>1;
	if(mid>=l)
	{
		update(a,l,r,v);
	}
	if(mid<r)
	{
		update(a|1,l,r,v);
	}
	segt[x].val=min(segt[a].val,segt[a|1].val);
	return;
}
ll query(ll x,ll l,ll r)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return MOD;
	}
	if(l<=tl&&tr<=r)
	{
		return segt[x].val;
	}
	push_down(x);
	ll mid=(tl+tr)>>1,a=x<<1,ret=MOD;
	if(mid>=l)
	{
		ret=min(ret,query(a,l,r));
	}
	if(mid<r)
	{
		ret=min(ret,query(a|1,l,r));
	}
	return ret;
}
/***************************************************************************************************/
int main(){
	ll i,tp,l,r,v;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	build1(1,0,n-1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&tp,&l,&r);
		if(tp==1)
		{
			scanf("%d",&v);
		}
		else
		{
			v=-1;
		}
		l--;
		r--;
		allv.push_back(l);
		allv.push_back(r+1);
		qry.push_back(make_pair(make_pair(l,r),v));
	}
	allv.push_back(0);
	allv.push_back(n*k);
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i+1<allv.size();i++)
	{
		if(allv[i+1]-allv[i]>=n)
		{
			val.push_back(query1(1,0,n-1));
		}
		else
		{
			if(allv[i]%n<=(allv[i+1]-1)%n)
			{
				val.push_back(query1(1,allv[i]%n,(allv[i+1]-1)%n));
			}
			else
			{
				val.push_back(min(query1(1,allv[i]%n,n-1),query1(1,0,(allv[i+1]-1)%n)));
			}
		}
	}
	build_tree(1,0,val.size()-1);
	for(i=0;i<qry.size();i++)
	{
		qry[i].F.F=lower_bound(allv.begin(),allv.end(),qry[i].F.F)-allv.begin();
		qry[i].F.S=upper_bound(allv.begin(),allv.end(),qry[i].F.S)-allv.begin()-1;
		if(qry[i].S==-1)
		{
			printf("%d\n",query(1,qry[i].F.F,qry[i].F.S));
		}
		else
		{
			update(1,qry[i].F.F,qry[i].F.S,qry[i].S);
		}
	}
	return 0;
}