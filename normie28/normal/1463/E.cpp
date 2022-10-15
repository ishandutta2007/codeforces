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
ll par[300001];
ll nxt[300001];
ll used[300001];
vector<ll> gt[300001],gr[300001];
ll cnt[300001];
ll indeg[300001];
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> stacc,fin;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>par[i];
		if (par[i])
		{
			gt[par[i]].push_back(i);
		}
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		indeg[v]++;
		if (nxt[u])
		{
              	cout<<"dupe";
			cout<<0;
			return 0;
		}
		else nxt[u]=v;
	}
	for (i=1;i<=n;i++) if (!indeg[i])
	{
		t++;
		u=i;
		while(true)
		{
			if (used[u])
			{
              	cout<<"not a line";
				cout<<0;
				return 0;
			}
			used[u]=t;
			gr[t].push_back(u);
			if ((par[u])and(used[par[u]]!=t)) cnt[t]++;
			if (!nxt[u]) break;
			u=nxt[u];
		}
	}
	for (i=1;i<=t;i++) if (!cnt[i])
	{
		stacc.push_back(i);
	}
	while(stacc.size())
	{
		u=stacc[stacc.size()-1];
    	// cout<<u<<endl;
		stacc.pop_back();
		for (i=0;i<gr[u].size();i++)
		{
			fin.push_back(gr[u][i]);
			for (auto g : gt[gr[u][i]]) if ((i+1==gr[u].size())or(g-gr[u][i+1]))
			{
      //        cout<<"release "<<gr[u][i]<<' '<<g<<endl;
				cnt[used[g]]--;
				if (!cnt[used[g]]) stacc.push_back(used[g]);
			}
		}
	}
	if (fin.size()<n) cout<<0;
	else for (auto g : fin) cout<<g<<' ';
}