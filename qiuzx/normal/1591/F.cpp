//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
struct SegT{
	ll l,r,val,upd,coef,pd;
}segt[N*8];
ll n,a[N],difs[N],cnt=0;
vector<ll> vals;
void build_tree(ll x,ll l,ll r)
{
	segt[x].l=l;
	segt[x].r=r;
	segt[x].val=0;
	segt[x].upd=0;
	segt[x].pd=-1;
	segt[x].coef=1;
	if(l==r)
	{
		segt[x].val=vals[min(l,a[0])];
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	return;
}
void push_down2(ll x)
{
	ll a=x<<1;
	segt[x].val=segt[x].pd;
	segt[a].pd=segt[x].pd;
	segt[a].coef=1;
	segt[a].upd=0;
	segt[a|1].pd=segt[x].pd;
	segt[a|1].coef=1;
	segt[a|1].upd=0;
	segt[x].pd=-1;
	return;
}
void push_down(ll x)
{
	ll a=x<<1;
	if(segt[x].pd!=-1)
	{
		push_down2(x);
	}
	segt[x].val=(segt[x].val*segt[x].coef+mod)%mod;
	segt[x].val=(segt[x].val+mod+((vals[segt[x].l]*segt[x].upd)%mod))%mod;
	segt[a].coef*=segt[x].coef;
	segt[a].upd=(segt[x].coef*segt[a].upd+segt[x].upd+mod*2)%mod;
	segt[a|1].coef*=segt[x].coef;
	segt[a|1].upd=(segt[x].coef*segt[a|1].upd+segt[x].upd+mod*2)%mod;
	segt[x].coef=1;
	segt[x].upd=0;
	return;
}
void update(ll x,ll l,ll r,ll val)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(l>tr||tl>r)
	{
		return;
	}
	push_down(x);
	if(l<=tl&&tr<=r)
	{
		if(val==-1)
		{
			segt[x].upd=(-segt[x].upd+mod)%mod;
			segt[x].coef*=-1;
		}
		else
		{
			segt[x].upd=(segt[x].upd+val)%mod;
		}
		push_down(x);
		return;
	}
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(a,l,r,val);
	}
	if(mid<r)
	{
		update(a|1,l,r,val);
	}
	return;
}
void update2(ll x,ll l,ll r,ll val)
{
	ll tl=segt[x].l,tr=segt[x].r,a=x<<1;
	if(l>tr||tl>r)
	{
		return;
	}
	push_down(x);
	if(l<=tl&&tr<=r)
	{
		segt[x].coef=1;
		segt[x].upd=0;
		segt[x].pd=val;
		push_down(x);
		segt[a].coef=1;
		segt[a].upd=0;
		segt[a|1].coef=1;
		segt[a|1].upd=0;
		return;
	}
	ll mid=(tl+tr)>>1;
	if(mid>=l)
	{
		update2(a,l,r,val);
	}
	if(mid<r)
	{
		update2(a|1,l,r,val);
	}
	return;
}
ll query(ll x,ll l)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>l||tr<l)
	{
		return 0;
	}
	push_down(x);
	if(l==tl&&tr==l)
	{
		return segt[x].val;
	}
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		return query(a,l);
	}
	return query(a|1,l);
}
int main(){
	ll i,v;
	n=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
		vals.push_back(a[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(i=0;i<n;i++)
	{
		a[i]=lower_bound(vals.begin(),vals.end(),a[i])-vals.begin();
	}
	build_tree(1,0,vals.size()-1);
	for(i=1;i<n;i++)
	{
		v=query(1,a[i-1]);
		update(1,0,a[i],-1);
		update(1,0,a[i],v);
		v=query(1,a[i]);
		if(a[i]+1<vals.size())
		{
			update2(1,a[i]+1,vals.size()-1,v);
		}
	}
	printf("%lld\n",query(1,a[n-1]));
	return 0;
}