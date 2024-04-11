
// Problem : Fence Painting
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1481/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
//---------END-------//
int arr[100001];
int brr[100001];
int crr[100001];
int res[100001];
vector<int> need[100001],stock[100001],safe;
int n,m,i,j,k,t,t1,u,v,a,b,fail;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		safe.clear();
		for (i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		for (i=1;i<=n;i++)
		{
			cin>>brr[i];
		}
		for (i=1;i<=n;i++)
		{
			need[i].clear();
			stock[i].clear();
		}
		for (i=1;i<=m;i++)
		{
			cin>>crr[i];
		}
		for (i=1;i<=n;i++)
		{
			stock[brr[i]].push_back(i);
			if (arr[i]-brr[i])
			{
				need[brr[i]].push_back(i);
			}
		}
		fail=0;
		for (i=m;i>=1;i--)
		{
	//		cout<<i;
			if (need[crr[i]].size())
			{
				res[i]=need[crr[i]][need[crr[i]].size()-1];
				safe.push_back(need[crr[i]][need[crr[i]].size()-1]);
				need[crr[i]].pop_back();
			}
			else if (stock[crr[i]].size())
			{
				res[i]=stock[crr[i]][0];
				safe.push_back(stock[crr[i]][0]);
			}
			else if (safe.size())
			{
				res[i]=safe[0];
			}
			else fail=1;
		}
		for (i=1;i<=n;i++) if (need[i].size()) fail=1;
		if (fail) cout<<"NO\n";
		else 
		{
			cout<<"YES\n";
			for (i=1;i<=m;i++) cout<<res[i]<<' ';
			cout<<endl;
			 
		}
	}
}