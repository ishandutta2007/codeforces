
// Problem : D. Picking Strings
// Contest : Codeforces - VK Cup 2018 - Round 1
// URL : https://codeforces.com/problemset/problem/923/D
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
int cntA1[100001],cntB1[100001];
int cntA2[100001],cntB2[100001];
int consA[100001];
string s1,s2;
int n,m,i,j,k,t,t1,u,v,a1,a2,b1,b2,l1,r1,l2,r2;
int main()
{
	fio;
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	for (i=1;i<=n;i++)
	{
		if (s1[i-1]=='A')
		{
			cntA1[i]=cntA1[i-1]+1;
			cntB1[i]=cntB1[i-1];
		}
		else
		{
			cntA1[i]=0;
			cntB1[i]=cntB1[i-1]+1;
		}
	}
	for (i=1;i<=m;i++)
	{
		if (s2[i-1]=='A')
		{
			cntA2[i]=cntA2[i-1]+1;
			cntB2[i]=cntB2[i-1];
		}
		else
		{
			cntA2[i]=0;
			cntB2[i]=cntB2[i-1]+1;
		}
	}
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>l1>>r1>>l2>>r2;
		a1=min(cntA1[r1],r1-l1+1);
		b1=cntB1[r1]-cntB1[l1-1];
		a2=min(cntA2[r2],r2-l2+1);
		b2=cntB2[r2]-cntB2[l2-1];
		if (((b2-b1)%2)or(a1<a2)or(b1>b2)) cout<<0;
		else
		{
			if (((a1-a2)%3)and(b1==b2)) cout<<0;
			else 
			if ((b1)or(b1==b2)) cout<<1;
			else
			{
				if (a1==a2) cout<<0;
				else cout<<1;
			}
		}
	}
}