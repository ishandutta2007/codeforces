
// Problem : F. Magnets
// Contest : Codeforces - Codeforces Global Round 13
// URL : https://codeforces.com/problemset/problem/1491/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n,m,i,j,k,t,t1,u,v,a,b;
int iter=0;
vector<int> va,vb,vc;
int ask()
{
	if (va.size()*vb.size()>n) exit(3);
	iter++;
	if (iter>n+floor(log2(n))) exit(3);
	cout<<"? "<<va.size()<<' '<<vb.size()<<endl;
	for (auto g : va) cout<<g<<' '; cout<<endl;
	for (auto g : vb) cout<<g<<' '; cout<<endl; 
	int m;
	cin>>m;
	return m;
}
int answer()
{
	cout<<"! "<<vc.size()<<' ';
	for (auto g : vc) cout<<g<<' ';cout<<endl;
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		iter=0;
		va.clear();
		vb.clear();
		vc.clear();
		for (i=2;i<=n;i++)
		{
			va.push_back(i-1);
			vb={i};
			u=ask();
			if (u) break;
		}
		u=i;
		for (i=u+1;i<=n;i++) 
		{
			va={u};
			vb={i};
			if (!ask()) vc.push_back(i);
		}
		int l=1,r=u-1,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			va.clear();
			for (i=l;i<=mid;i++) va.push_back(i);
			vb={u};
			if (ask()) r=mid; else l=mid+1;
		}
		for (i=1;i<u;i++) if (i!=l) vc.push_back(i);
		answer();
	}
}