// Problem: F. Double Knapsack
// Contest: Codeforces - Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/contest/618/problem/F
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
vector<ll> veca,vecb;
ll n,m,i,j,k,t,t1,u,v,a,b,sw;
vector<pii(ll)> bruh[1000001];
int main()
{
	fio;
	cin>>n;
	u=0;
	veca.push_back(u);
	for (i=0;i<n;i++)
	{
		cin>>v;
		u+=v;
		veca.push_back(u);
	}
	u=0;
	vecb.push_back(u);
	for (i=0;i<n;i++)
	{
		cin>>v;
		u+=v;
		vecb.push_back(u);
	}
	if (veca[n]>vecb[n]) 
	{
		swap(veca,vecb);
		sw=1;
	}
	j=0;
	for (i=0;i<=n;i++)
	{
		while(vecb[j]<veca[i]) j++;
		bruh[vecb[j]-veca[i]].push_back({i,j});
		if (bruh[vecb[j]-veca[i]].size()==2)
		{
			if (sw==1)
			{
				a=bruh[vecb[j]-veca[i]][0].se;
				b=bruh[vecb[j]-veca[i]][1].se;
				if (a>b) swap(a,b);
				cout<<b-a;
				cout<<endl;
				for (k=a+1;k<=b;k++)
				{
					cout<<k<<' ';
				}
				cout<<endl;
				a=bruh[vecb[j]-veca[i]][0].fi;
				b=bruh[vecb[j]-veca[i]][1].fi;
				if (a>b) swap(a,b);
				cout<<b-a;
				cout<<endl;
				for (k=a+1;k<=b;k++)
				{
					cout<<k<<' ';
				}
				cout<<endl;
			}
			else
			{
				
				a=bruh[vecb[j]-veca[i]][0].fi;
				b=bruh[vecb[j]-veca[i]][1].fi;
				if (a>b) swap(a,b);
				cout<<b-a;
				cout<<endl;
				for (k=a+1;k<=b;k++)
				{
					cout<<k<<' ';
				}
				cout<<endl;
				a=bruh[vecb[j]-veca[i]][0].se;
				b=bruh[vecb[j]-veca[i]][1].se;
				if (a>b) swap(a,b);
				cout<<b-a;
				cout<<endl;
				for (k=a+1;k<=b;k++)
				{
					cout<<k<<' ';
				}
				cout<<endl;
			}
			return 0;
		}
	}
}