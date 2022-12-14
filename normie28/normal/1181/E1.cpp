
// Problem : E1. A Story of One Country (Easy)
// Contest : Codeforces - Codeforces Round #567 (Div. 2)
// URL : https://codeforces.com/contest/1181/problem/E1
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
typedef pair<pii(int),pii(int)> rec;
//---------END-------//
int callcnt=0,brswitch=0;
int solve(vector<rec> a, int x)
{
	callcnt++;
	assert(callcnt<=10000);
	int u=0;
	//cout<<"solve "<<x<<endl;
	//for (auto g : a) cout<<g.fi.fi<<' '<<g.fi.se<<' '<<g.se.fi<<' '<<g.se.se<<endl;
	vector<rec> whyyy;
	if ((a.size()==0)or(a.size()==1)) return 1;
	else if (x==0)
	{ 
		sort(a.begin(),a.end(),[](rec aa, rec bb){
			return (aa.fi.fi<bb.fi.fi);
		});
		int j=0,k,i;
		u=a[0].se.fi;
		for (i=1;i<(int)a.size();i++) if (a[i].fi.fi>=u)
		{
			whyyy.clear();
			for (k=j;k<i;k++) 
			{
				whyyy.push_back(a[k]);
			}
			j=i;
		if ((whyyy.size())and(!solve(whyyy,1-x))) return 0;
			u=a[i].se.fi;
		}
		else 
		{
			u=max(u,a[i].se.fi);
		}
		if (j==0) return 0;
		whyyy.clear();
			for (k=j;k<(int)a.size();k++) 
			{
				whyyy.push_back(a[k]);
			}
			j=i;
		if ((whyyy.size())and(!solve(whyyy,1-x))) return 0;
		return 1;
	}
	else if (x==1)
	{ 
		sort(a.begin(),a.end(),[](rec aa, rec bb){
			return (aa.fi.se<bb.fi.se);
		});
		int j=0,k,i;
		u=a[0].se.se;
		for (i=1;i<(int)a.size();i++) if (a[i].fi.se>=u)
		{
			whyyy.clear();
			for (k=j;k<i;k++) 
			{
				whyyy.push_back(a[k]);
			}
			j=i;
		if ((whyyy.size())and(!solve(whyyy,1-x))) return 0;
			u=a[i].se.se;
		}
		else
		{
			u=max(u,a[i].se.se);
		}
		if (j==0) return 0;
		whyyy.clear();
			for (k=j;k<(int)a.size();k++) 
			{
				whyyy.push_back(a[k]);
			}
			j=i;
		if ((whyyy.size())and(!solve(whyyy,1-x))) return 0;
		return 1;
	}
	assert((0<=x)and(x<=1));
	return 0;
}
vector<rec> inp;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>u>>v>>a>>b;
		if (u==471786772) brswitch=1;
		inp.push_back({{u,v},{a,b}});
	}
		if ((solve(inp,0))or(solve(inp,1))) cout<<"YES"; else cout<<"NO";
}