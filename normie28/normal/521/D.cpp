/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
vector<pii(ll)> buc[100001];
ll st[100001];
pii(ll) maxx[100001];
vector<piii(ll)> muls;
ll typ[100001];
vector<ll> fin;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>k>>n>>m;
	for (i=1;i<=k;i++) cin>>st[i];
	for (i=1;i<=n;i++)
	{
		cin>>u>>v>>a;
      typ[i]=u;
		if (u==1)
		{
    //      cout<<maxx[v].fi<<' '<<maxx[v].se<<' '<<i<<endl;
			if ((a>st[v])and(a>maxx[v].fi))
			maxx[v]={a,i};
		}
		else if (u==2)
		{
			buc[v].push_back({a,i});
		}
		else
		{
			muls.push_back({i,{a,1}});
		}
	}
	for (i=1;i<=k;i++)
	{
		if (maxx[i].fi)
		{
			buc[i].push_back({maxx[i].fi-st[i],maxx[i].se});
		}
		sort(buc[i].begin(),buc[i].end(),[](pii(ll) a, pii(ll) b){
			return (a.fi>b.fi);
		});
		u=st[i];
		for (j=0;j<buc[i].size();j++)
		{
			muls.push_back({buc[i][j].se,{buc[i][j].fi+u,u}});
			u+=buc[i][j].fi;
		}
	}
 // for (auto g : muls) cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
	sort(muls.begin(),muls.end(),[](piii(ll) a, piii(ll) b)
	{
		return ((a.se.fi-a.se.se)*(b.se.se)>(b.se.fi-b.se.se)*(a.se.se));
	});
	u=min(m,muls.size());
	cout<<u<<endl;
	for (i=0;i<u;i++) fin.push_back(muls[i].fi);
  	sort(fin.begin(),fin.end(),[](int a, int b){return (typ[a]<typ[b]);});
  	for (i=0;i<u;i++) cout<<fin[i]<<' ';
}