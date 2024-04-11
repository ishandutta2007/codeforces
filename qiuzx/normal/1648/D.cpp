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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
struct Val{
	ll mxf,mxg,sum;
};
Val merg(Val x,Val y)
{
	Val res;
	res.mxf=max(x.mxf,y.mxf);
	res.mxg=max(x.mxg,y.mxg);
	res.sum=max(max(x.sum,y.sum),x.mxf+y.mxg);
	return res;
}
struct SegT{
	ll lo[N<<2],hi[N<<2];
	Val val[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x].mxf=val[x].mxg=val[x].sum=-LINF;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll vf,ll vg)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			val[x].mxf=max(val[x].mxf,vf);
			val[x].mxg=max(val[x].mxg,vg);
			val[x].sum=val[x].mxf+val[x].mxg;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,vf,vg);
		}
		else
		{
			update(a|1,l,vf,vg);
		}
		val[x]=merg(val[a],val[a|1]);
		return;
	}
	Val query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=r)
		{
			return query(a,l,r);
		}
		if(mid<l)
		{
			return query(a|1,l,r);
		}
		return merg(query(a,l,r),query(a|1,l,r));
	}
}segt;
ll n,q,a[3][N],sum[3][N],ans=-LINF;
vector<pair<pair<ll,ll>,ll> > op;
int main(){
	ll i,j,l,r,k;
	n=rint(),q=rint();
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=rint();
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for(i=0;i<q;i++)
	{
		l=rint(),r=rint(),k=rint();
		op.push_back(make_pair(make_pair(l,r),k));
	}
	sort(op.begin(),op.end());
	segt.build(1,1,n);
	for(i=1;i<=n;i++)
	{
		segt.update(1,i,sum[0][i]-sum[1][i-1],sum[1][i]-sum[2][i-1]);
	}
	for(i=0;i<op.size();i++)
	{
		l=op[i].F.F,r=op[i].F.S,k=op[i].S;
		Val cur=segt.query(1,l,r);
		if(r<n)
		{
			segt.update(1,r+1,cur.mxf-k,-LINF);
		}
		ans=max(ans,cur.sum-k+sum[2][n]);
	}
	printf("%lld\n",ans);
	return 0;
}