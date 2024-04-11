// Problem: C. Tournament
// Contest: Codeforces - Codeforces Round #443 (Div. 1)
// URL: https://codeforces.com/problemset/problem/878/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int pp[50001][11];
struct cmp {
	int operator()(pii(int) a, pii(int) b)
	{
		return (a.se<b.se);
	}
};
set<pii(int),cmp> br;
vector<int> aa[11];
ordered_set(int) oth[11];
void merg(int a, int b)
{
	if (a>b) return;
	auto it=br.lower_bound({a,a});
	int l=1e9,r=0;
	while(true)
	{
		l=min(l,it->fi);
		r=max(r,it->se);
		if (it->se>=b) 
		{
			br.erase(it);
			break;
		}
		it=br.erase(it);
	}
	br.insert({l,r});
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++) cin>>pp[i][j];
		for (j=1;j<=m;j++) aa[j].push_back(i);
	}
	for (i=1;i<=m;i++)
	{
		sort(aa[i].begin(),aa[i].end(),[](int a, int b){
			return (pp[a][i]<pp[b][i]);
		});
		for (j=0;j<n;j++) pp[aa[i][j]][i]=j+1;
	}
	for (i=1;i<=n;i++)
	{
	//	for (j=1;j<=m;j++) cout<<pp[i][j]<<' ';
	//	cout<<endl;
	}
	for (i=1;i<=n;i++) br.insert({i,i});
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++) oth[j].insert(pp[i][j]);
		for (j=2;j<=m;j++)
		{
			auto it=oth[j].lower_bound(pp[i][j]);
			++it;
			if (it!=oth[j].end())
			{
				u=i;
				v=aa[j][(*(it))-1];
				merg(pp[v][1],pp[u][1]);
			}
			--it;
			if (it!=oth[j].begin())
			{
				--it;
				u=i;
				v=aa[j][(*(it))-1];
				merg(pp[u][1],pp[v][1]);
				++it;
			}
		}
	//	for (auto g: br) cout<<"range "<<g.fi<<' '<<g.se<<endl;  
		a=(*(--oth[1].end()));
		b=br.lower_bound({a,a})->fi;
		cout<<i-oth[1].order_of_key(b)<<endl;
	}
}