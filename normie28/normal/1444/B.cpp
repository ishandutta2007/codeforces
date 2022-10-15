
// Problem : B. Divide and Sum
// Contest : Codeforces - Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad)
// URL : https://codeforces.com/contest/1444/problem/B
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>

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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;

//---------END-------//
ll n,m,i,j,u,t,k,v,arr[100001],l1,l2;
ll bow (ll a, ll x)
{
	if (!x) return 1;
	else 
	{
		ll res=bow(a,x/2);
		res*=res;
		res%=MOD;
		if (x%2) res*=a;
		res%=MOD;
		return res;
	}
}
vector<ll> lis;
int main()
{
	fio;
	cin>>n;
	for (i=0;i<2*n;i++)
	{
		cin>>m;
		lis.push_back(m);
	}
	sort(lis.begin(),lis.end());
	for (i=0;i<2*n;i++) if (i<n)
	{
		u-=lis[i];
	}
	else u+=lis[i];
	l1=1;
	l2=1;
	for (i=1;i<=n;i++) {
		l1*=i;
		l1%=MOD;
	}
	u%=MOD;
	for (i=1;i<=2*n;i++) l2*=i,l2%=MOD;
	u*=l2;
	u%=MOD;
	l1=bow(l1,MOD-2);
	u*=l1;
	u%=MOD;
	u*=l1;
	u%=MOD;
	cout<<u;
}