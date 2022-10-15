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
ll solve(vector<pii(ll)> bruh)
{
	sort(bruh.begin(),bruh.end(),[](pii(ll) a, pii(ll) b){return (a.se<b.se);});
	vector<pii(ll)> rangeL,rangeR;
	ll u,v,res=0;
	u=1e9;v=-1e9;
	
	for (ll i=0;i<(ll)bruh.size();i++)
	{
		u=min(u,bruh[i].fi);
		v=max(v,bruh[i].fi);
		rangeL.push_back({u,v});
	}
	
	u=1e9;v=-1e9;
	for (ll i=(ll)bruh.size()-1;i>=0;i--)
	{
		assert((i>=0)and(i<bruh.size()));
		u=min(u,bruh[i].fi);
		v=max(v,bruh[i].fi);
		rangeR.push_back({u,v});
	}
	
	reverse(rangeR.begin(),rangeR.end());
	for (ll i=0;i+1<(ll)bruh.size();i++)
	{
		u=max(rangeL[i].fi,rangeR[i+1].fi);
		v=min(rangeL[i].se,rangeR[i+1].se);
		if (v-u>=0) res+=(v-u)*(bruh[i+1].se-bruh[i].se);
	}
	
	return res;
}
vector<pii(ll)> buc0,buc1;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>u>>v;
		if ((u+v)%2==0)
		{
			buc0.emplace_back((u+v)/2,(u-v)/2);
		}
		else
		{
			buc1.emplace_back((u+v+1)/2,(u-v+1)/2);
		}
	}
	cout<<solve(buc0)+solve(buc1);
}