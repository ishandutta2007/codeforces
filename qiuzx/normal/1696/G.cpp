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
ll X,Y;
struct Data{
	double v[3][3];
	void init()
	{
		ll i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				v[i][j]=0;
			}
		}
		return;
	}
	void print()
	{
		puts("*********************************");
		ll i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<v[i][j]<<" ";
			}
			puts("");
		}
		puts("*********************************");
		return;
	}
};
Data Merge(Data a,Data b)
{
	ll i,j,k,l;
	Data ret;
	ret.init();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if((i==1&&j==2)||(i==2&&j==1)||(i==1&&j==1))
			{
				continue;
			}
			for(k=0;k<3;k++)
			{
				for(l=0;l<3;l++)
				{
					ret.v[k][l]=max(ret.v[k][l],a.v[k][i]+b.v[j][l]);
				}
			}
		}
	}
	return ret;
}
struct SegT{
	ll lo[N<<2],hi[N<<2],pre[N];
	Data val[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r;
		if(l==r)
		{
			val[x].init();
			val[x].v[1][1]=(double)pre[l]/(double)X,val[x].v[2][2]=(double)pre[l]/(double)(X+Y);
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		val[x]=Merge(val[a],val[a|1]);
		return;
	}
	void update(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			pre[l]=v;
			val[x].init();
			val[x].v[1][1]=(double)pre[l]/(double)X,val[x].v[2][2]=(double)pre[l]/(double)(X+Y);
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,v);
		}
		else
		{
			update(a|1,l,v);
		}
		val[x]=Merge(val[a],val[a|1]);
		return;
	}
	Data query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid<l)
		{
			return query(a|1,l,r);
		}
		if(mid>=r)
		{
			return query(a,l,r);
		}
		return Merge(query(a,l,r),query(a|1,l,r));
	}
}segt;
ll n,q;
int main(){
	ll i,j;
	scanf("%lld%lld%lld%lld",&n,&q,&X,&Y);
	if(X<Y)
	{
		swap(X,Y);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&segt.pre[i]);
	}
	segt.build(1,0,n-1);
	while(q--)
	{
		ll tp,l,r;
		scanf("%lld%lld%lld",&tp,&l,&r);
		if(tp==1)
		{
			l--;
			segt.update(1,l,r);
		}
		else
		{
			l--,r--;
			Data ans=segt.query(1,l,r);
			double res=0;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					res=max(res,ans.v[i][j]);
				}
			}
			printf("%.15lf\n",res);
		}
	}
	return 0;
}