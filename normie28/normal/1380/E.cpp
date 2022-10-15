/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef int ll;
//---------DSU PLS WORK-----------//

struct dsu
{
	ll n,par[200001],h[200001],sz[200001],res=0;
	set<ll> el[200001];
	dsu (ll n)
	{
		this->n=n;
		for (ll i=1;i<=n;i++) 
		{
			h[i]=1;
			par[i]=i;
			sz[i]=0;
		}
	}
	ll get_par(ll x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	ll check_same(ll a, ll b)
	{
		return (get_par(a)==get_par(b));
	}
	ll add_edge(ll a, ll b)
	{
		ll ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (sz[ha]<sz[hb])
			{
				par[ha]=hb;
				sz[hb]+=sz[ha];
				for (ll g : el[ha])
				{
					if (el[hb].find(g+1)!=el[hb].end()) res++;
					if (el[hb].find(g-1)!=el[hb].end()) res++;
				}
				for (ll g : el[ha])
				el[hb].insert(g);
			}
			else
			if (sz[ha]>sz[hb])
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				for (ll g : el[hb])
				{
					if (el[ha].find(g+1)!=el[ha].end()) res++;
					if (el[ha].find(g-1)!=el[ha].end()) res++;
				}
				for (ll g : el[hb])
				el[ha].insert(g);
			}
			else
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				h[ha]++;
				for (ll g : el[hb])
				{
					if (el[ha].find(g+1)!=el[ha].end()) res++;
					if (el[ha].find(g-1)!=el[ha].end()) res++;
				}
				for (ll g : el[hb])
				el[ha].insert(g);
			}
		}
	}
};
//---------END-------//
int n,m,k,c[501],sta[200001],t,t1,i,j;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    dsu gr(m);
    
    for (i=1;i<=n;i++)
    {
    	cin>>sta[i];
    	if ((i>1) and (sta[i]==sta[i-1])) gr.res++;
    	gr.el[sta[i]].insert(i);
    	gr.sz[sta[i]]++;
    }
    
    cout<<n-gr.res-1<<endl;
    for (i=1;i<m;i++)
    {
    	int lu,lv;
    	cin>>lu>>lv;
    	gr.add_edge(lu,lv);
    cout<<n-gr.res-1<<endl;
    }
    
}