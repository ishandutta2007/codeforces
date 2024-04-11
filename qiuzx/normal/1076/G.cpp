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
#define ll int
#define N 200010
using namespace std;
struct Data{
	ll trs[6];
};
ll a[N],b[N],n,m,q;
struct SegT{
	ll lo[N<<2],hi[N<<2],pd[N<<3];
	Data val[N<<3][2];
	Data pushup(Data x,Data y)
	{
		Data ret;
		ll i;
		for(i=0;i<=m;i++)
		{
			ret.trs[i]=x.trs[y.trs[i]];
		}
		return ret;
	}
	void build(ll x,ll l,ll r)
	{
		lo[x]=l;
		hi[x]=r;
		pd[x]=0;
		ll i;
		if(l==r)
		{
			for(i=0;i<m;i++)
			{
				val[x][0].trs[i]=val[x][1].trs[i]=i+1;
			}
			val[x][0].trs[m]=(a[l]?m:0);
			val[x][1].trs[m]=(b[l]?m:0);
			return;
		}
		ll mid=(l+r)>>1,nxt=(x<<1);
		build(nxt,l,mid);
		build(nxt|1,mid+1,r);
		val[x][0]=pushup(val[nxt][0],val[nxt|1][0]);
		val[x][1]=pushup(val[nxt][1],val[nxt|1][1]);
		return;
	}
	void pushdown(ll x)
	{
		if(pd[x]==0)
		{
			return;
		}
		ll nxt=(x<<1);
		pd[nxt]^=1;
		pd[nxt|1]^=1;
		swap(val[nxt][0],val[nxt][1]);
		swap(val[nxt|1][0],val[nxt|1][1]);
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		pushdown(x);
		if(l<=tl&&tr<=r)
		{
			pd[x]^=1;
			swap(val[x][0],val[x][1]);
			pushdown(x);
			return;
		}
		ll mid=(tl+tr)>>1,nxt=x<<1;
		if(mid>=l)
		{
			update(nxt,l,r);
		}
		if(mid<r)
		{
			update(nxt|1,l,r);
		}
		val[x][0]=pushup(val[nxt][0],val[nxt|1][0]);
		val[x][1]=pushup(val[nxt][1],val[nxt|1][1]);
		return;
	}
	Data query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		pushdown(x);
		if(l<=tl&&tr<=r)
		{
			return val[x][0];
		}
		ll mid=(tl+tr)>>1,nxt=x<<1;
		if(mid<l)
		{
			return query(nxt|1,l,r);
		}
		if(mid>=r)
		{
			return query(nxt,l,r);
		}
		return pushup(query(nxt,l,r),query(nxt|1,l,r));
	}
}segt;
int main(){
	ll i,tp,l,r;
	long long x;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		x&=1;
		a[i]=(x^1);
		b[i]=x;
	}
	segt.build(1,0,n-1);
	while(q--)
	{
		scanf("%d%d%d",&tp,&l,&r);
		l--;
		r--;
		if(tp==1)
		{
			scanf("%lld",&x);
			if(x&1)
			{
				segt.update(1,l,r);
			}
		}
		else
		{
			printf("%d\n",(segt.query(1,l,r).trs[m]==0)+1);
		}
	}
	return 0;
}