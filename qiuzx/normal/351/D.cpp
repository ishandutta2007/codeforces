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
#define N 100010
#define B 320
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
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			val[x]+=v;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,v);
		}
		if(mid<r)
		{
			update(a|1,l,r,v);
		}
		return;
	}
	ll query(ll x,ll l)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl==l&&tr==l)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=val[x];
		if(mid>=l)
		{
			return ret+query(a,l);
		}
		return ret+query(a|1,l);
	}
}segt;
ll n,m,cnt[N],sum=0,ans[N],a[N];
vector<pair<pair<ll,ll>,ll> > qry,ask[N];
vector<pair<ll,ll> > req[N];
vector<ll> occ[N];
bool cmp(pair<pair<ll,ll>,ll> x,pair<pair<ll,ll>,ll> y)
{
	if(x.F.F/B!=y.F.F/B)
	{
		return (x.F.F/B)<(y.F.F/B);
	}
	if((x.F.F/B)&1)
	{
		return (x.F.S>y.F.S);
	}
	return (x.F.S<y.F.S);
}
void upd(ll x)
{
	++cnt[a[x]];
	if(cnt[a[x]]==1)
	{
		++sum;
	}
	return;
}
void erz(ll x)
{
	--cnt[a[x]];
	if(cnt[a[x]]==0)
	{
		--sum;
	}
	return;
}
void addquery(ll l1,ll r1,ll l2,ll r2)
{
//	cout<<l1<<"~"<<r1<<" : "<<l2<<"~"<<r2<<endl
	//ql:[l1,r1], qr:[l2,r2]
	ask[l1].push_back(make_pair(make_pair(l2,r2),1));
	ask[r1+1].push_back(make_pair(make_pair(l2,r2),-1));
	return;
}
int main(){
	ll i,j,l,r,ql,qr;
	n=rint();
	for(i=0;i<N;++i)
	{
		occ[i].push_back(-1);
	}
	for(i=0;i<n;++i)
	{
		a[i]=rint();
		occ[a[i]].push_back(i);
	}
	for(i=0;i<N;++i)
	{
		occ[i].push_back(n);
	}
	for(i=0;i<N;++i)
	{
		for(l=1;l+1<occ[i].size();l=r-1)
		{
			for(r=l+1;r+1<occ[i].size();++r)
			{
				if(occ[i][r]-occ[i][r-1]!=occ[i][l+1]-occ[i][l])
				{
					break;
				}
			}
			for(j=l;j<=r;++j)
			{
				addquery(occ[i][l-1]+1,occ[i][j],occ[i][j],occ[i][r]-1);
			}
			if(r==occ[i].size()-1)
			{
				break;
			}
		}
	}
	m=rint();
	for(i=0;i<m;++i)
	{
		l=rint()-1,r=rint()-1;
		qry.push_back(make_pair(make_pair(l,r),i));
		req[l].push_back(make_pair(r,i));
	}
	segt.build(1,0,n);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<ask[i].size();j++)
		{
			segt.update(1,ask[i][j].F.F,ask[i][j].F.S,ask[i][j].S);
		}
		for(j=0;j<req[i].size();j++)
		{
			ans[req[i][j].S]=(segt.query(1,req[i][j].F)==0);
		}
	}
	sort(qry.begin(),qry.end(),cmp);
	l=r=0;
	for(i=0;i<m;++i)
	{
		ql=qry[i].F.F,qr=qry[i].F.S;
		while(r<=qr)
		{
			upd(r);
			++r;
		}
		while(r-1>qr)
		{
			--r;
			erz(r);
		}
		while(l<ql)
		{
			erz(l);
			++l;
		}
		while(l>ql)
		{
			--l;
			upd(l);
		}
		ans[qry[i].S]+=sum;
	}
	for(i=0;i<m;i++)
	{
		rout(ans[i]),putchar('\n');
	}
	return 0;
}