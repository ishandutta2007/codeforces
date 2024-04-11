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
vector<vector<int>> arr;
vector<vector<int>> brr;
int n,m,i,j,k,t,t1,u,v,a,b;
int rowsmol[1501],colcnt[1501];
vector<int> ord;
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		arr.push_back({});
		for (j=0;j<m;j++)
		{
			cin>>u;
			arr[i].push_back(u);
		}
	}
	for (i=0;i<n;i++)
	{
		brr.push_back({});
		for (j=0;j<m;j++)
		{
			cin>>u;
			brr[i].push_back(u);
		}
	}
	for (i=0;i<m;i++)
	{
		for (j=1;j<n;j++) if (brr[j][i]<brr[j-1][i]) colcnt[i]++; 
	}
	for (t=0;t<n;t++)
	{
		for (j=0;j<m;j++) if (colcnt[j]==0) break;
		if (j==m) break;
		colcnt[j]=-1;
		ord.push_back(j);
		for (i=1;i<n;i++) if ((brr[i][j]>brr[i-1][j])and(!rowsmol[i]))
		{
			rowsmol[i]=1;
			for (k=0;k<m;k++) if ((colcnt[k]>0)and(brr[i][k]<brr[i-1][k])) colcnt[k]--;
		}
	}
	stable_sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b){
		for (auto g : ord) 
		{
			if (a[g]<b[g]) return 1;
			if (a[g]>b[g]) return 0;
		}
		return 0;
	});
	for (i=0;i<n;i++) for (j=0;j<m;j++) if (arr[i][j]-brr[i][j]) return cout<<"-1",0;
	cout<<ord.size()<<endl;
	for (i=ord.size()-1;i>=0;i--) cout<<ord[i]+1<<' '; 
}