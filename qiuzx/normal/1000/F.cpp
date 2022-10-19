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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,q,a[N],ans[N],lstoc[N],lst[N];
vector<pair<ll,ll> > qry[N];
struct SegT{
	set<pair<ll,ll> > val[N];
	pair<ll,ll> res[N<<2];
	ll lo[N<<2],hi[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r;
		res[x]=make_pair(INF,0);
		if(l==r)
		{
			val[l].clear();
			return;
		}
		ll mid=(l+r)>>1,nxt=x<<1;
		build(nxt,l,mid);
		build(nxt|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,pair<ll,ll> v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			val[l].insert(v);
			res[x]=*val[l].begin();
			return;
		}
		ll mid=(tl+tr)>>1,nxt=x<<1;
		if(mid>=l)
		{
			update(nxt,l,v);
		}
		else
		{
			update(nxt|1,l,v);
		}
		res[x]=min(res[nxt],res[nxt|1]);
		return;
	}
	void recall(ll x,ll l,pair<ll,ll> v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			val[l].erase(v);
			res[x]=(val[l].empty())?make_pair(INF,0):*val[l].begin();
			return;
		}
		ll mid=(tl+tr)>>1,nxt=x<<1;
		if(mid>=l)
		{
			recall(nxt,l,v);
		}
		else
		{
			recall(nxt|1,l,v);
		}
		res[x]=min(res[nxt],res[nxt|1]);
		return;
	}
	pair<ll,ll> query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return res[x];
		}
		ll mid=(tl+tr)>>1,nxt=x<<1;
		pair<ll,ll> ret1=make_pair(INF,0),ret2=make_pair(INF,0);
		if(mid>=l)
		{
			ret1=query(nxt,l,r);
		}
		if(mid<r)
		{
			ret2=query(nxt|1,l,r);
		}
		return min(ret1,ret2);
	}
}segt;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll i,j,l,r;
	n=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
	}
	q=rint();
	for(i=0;i<q;i++)
	{
		l=rint()-1,r=rint()-1;
		qry[r].push_back(make_pair(l,i));
	}
	memset(lstoc,-1,sizeof(lstoc));
	segt.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		if(lstoc[a[i]]!=-1)
		{
			segt.recall(1,lstoc[a[i]],make_pair(lst[a[i]]+1,a[i]));
		}
		lst[a[i]]=lstoc[a[i]];
		lstoc[a[i]]=i;
		segt.update(1,lstoc[a[i]],make_pair(lst[a[i]]+1,a[i]));
		for(j=0;j<qry[i].size();j++)
		{
			pair<ll,ll> p=segt.query(1,qry[i][j].F,i);
			if(p.F<=qry[i][j].F)
			{
				ans[qry[i][j].S]=segt.query(1,qry[i][j].F,i).S;
			}
		}
	}
	for(i=0;i<q;i++)
	{
		rout(ans[i]),putchar('\n');
	}
	return 0;
}