
// Problem : E. Little Elephant and Inversions
// Contest : Codeforces - Codeforces Round #136 (Div. 1)
// URL : https://codeforces.com/problemset/problem/220/E
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
ordered_set(ll) setl,setr;
ll arr[100001];
ll minr,cntl,cntr,cntlr;
ll n,m,i,j,k,t,t1,u,v,a,b,res;
int main()
{
//	ofile;
	fio;
	cin>>n>>k;
	for (i=1;i<=n;i++) cin>>arr[i];
	minr=n;
	setr.insert(arr[minr]*1e6+minr);
	while(true)
	{
		minr--;
		if (minr==0)
		{
			minr++;
			break;
		}
		else
		{
			cntr+=setr.order_of_key(arr[minr]*1e6);
			setr.insert(arr[minr]*1e6+minr);
			if (cntr>k)
			{
			cntr-=setr.order_of_key(arr[minr]*1e6);
			setr.erase(arr[minr]*1e6+minr);
				minr++;
				break;
			}
		}
	}
//	cout<<minr<<endl;
	for (i=1;i<=n;i++)
	{
		if (minr==i)
		{
			cntlr-=setl.size()-setl.order_of_key(arr[minr]*1e6+1e6);
			cntr-=setr.order_of_key(arr[minr]*1e6);
			setr.erase(arr[minr]*1e6+minr);
			minr++;
		}
			cntlr+=setr.order_of_key(arr[i]*1e6);
			cntl+=setl.size()-setl.order_of_key(arr[i]*1e6+1e6);
			setl.insert(arr[i]*1e6+i);
		while (cntl+cntr+cntlr>k)
		if (minr==n+1) break;
		else
		{
			cntlr-=setl.size()-setl.order_of_key(arr[minr]*1e6+1e6);
			cntr-=setr.order_of_key(arr[minr]*1e6);
			setr.erase(arr[minr]*1e6+minr);
			minr++;
		}
		res+=n+1-minr;
	}
	cout<<res;
}