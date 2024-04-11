// Problem : Searching Local Minimum
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1479/problem/A
// Memory Limit : 512 MB
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
int get (int n)
{
	int x;
	cout<<"? "<<n<<endl;
	cin>>x;
	return x;
}
int ret(int n)
{
	cout<<"! "<<n<<endl;
	exit(0);
}
int check(int x)
{
	int l,r,v,vl,vr;
	v=get(x);
	if (x==1) l=1;
	else 
	{
		vl=get(x-1);
		if (vl>v) l=1;
		else l=0;
	}
	if (x==n) r=1;
	else 
	{
		vr=get(x+1);
		if (vr>v) r=1;
		else r=0;
	}
	if (l*r) ret(x);
	else if (!l) return 0;
	else return 1;
}
void bs(int l, int r)
{
	if (l==r) ret(l);
	{
		int mid=(l+r)/2;
		if (!check(mid)) bs(l,mid-1); else bs(mid+1,r);
	}
}
int main()
{
	cin>>n;
	bs(1,n);
}