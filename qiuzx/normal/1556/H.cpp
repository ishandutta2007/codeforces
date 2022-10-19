//ANMHLIJKTJIY!
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 52
using namespace std;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
double start=clock();
const double TL=4.5;
const double Start=1000;
const double Change=0.999;
const double eps=1e-6;
ll n,m,k,mxdeg[N],deg[N],dist[N][N],st[N][N],fa[N];
ll getf(ll x)
{
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
struct simulateAnneal{
	ll curans,mnans;
	void init()
	{
		curans=LINF;
		mnans=LINF;
		return;
	}
	pair<ll,ll> get_change()
	{
		ll x,y;
		x=y=-1;
		while(x==y)
		{
			x=rnd()%n;
			y=rnd()%n;
		}
		st[x][y]^=1;
		st[y][x]^=1;
		return make_pair(x,y);
	}
	void rem_change(ll x,ll y)
	{
		st[x][y]^=1;
		st[y][x]^=1;
		return;
	}
	ll calc_val()
	{
		ll i,j,ret=0;
		vector<pair<ll,pair<ll,ll> > > req;
		for(i=0;i<n;i++)
		{
			deg[i]=0;
			fa[i]=i;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(st[i][j])
				{
					if(getf(i)==getf(j))
					{
						return LINF;
					}
					ret+=dist[i][j];
					deg[i]++;
					deg[j]++;
					fa[getf(i)]=getf(j);
				}
				else
				{
					req.push_back(make_pair(dist[i][j],make_pair(i,j)));
				}
			}
		}
		for(i=0;i<k;i++)
		{
			if(deg[i]>mxdeg[i])
			{
				return LINF;
			}
		}
		sort(req.begin(),req.end());
		for(i=0;i<req.size();i++)
		{
			ll x=req[i].S.F,y=req[i].S.S;
			if(getf(x)==getf(y))
			{
				continue;
			}
			if(x<k&&deg[x]>=mxdeg[x])
			{
				continue;
			}
			if(y<k&&deg[y]>=mxdeg[y])
			{
				continue;
			}
			deg[x]++;
			deg[y]++;
			fa[getf(x)]=getf(y);
			ret+=req[i].F;
		}
		ll cnt=0;
		for(i=0;i<n;i++)
		{
			if(getf(i)==i)
			{
				cnt++;
			}
		}
		if(cnt<=1)
		{
			return ret;
		}
		return LINF;
	}
	void solve()
	{
		double T;
		for(T=Start;T>eps;T*=Change)
		{
			pair<ll,ll> modify=get_change();
			ll nval=calc_val();
			ll delta=curans-nval;
			if(exp((double)delta/T)>(double)(rnd()%1000000000)/(double)1000000000.0)
			{
				curans=nval;
				mnans=min(mnans,curans);
			}
			else
			{
				rem_change(modify.F,modify.S);
			}
		}
		return;
	}
}sa;
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<k;i++)
	{
		scanf("%lld",&mxdeg[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			scanf("%lld",&dist[i][j]);
			dist[j][i]=dist[i][j];
		}
	}
	memset(st,0,sizeof(st));
	sa.init();
	while(clock()<start+CLOCKS_PER_SEC*TL)
	{
		sa.solve();
	}
	printf("%lld\n",sa.mnans);
	return 0;
}