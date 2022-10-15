// Problem: I. Lookup Tables
// Contest: Codeforces - Bubble Cup 13 - Finals [Online Mirror, unrated, Div. 1]
// URL: https://codeforces.com/problemset/problem/1423/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
unsigned int n,m,i,j,k,t,t1,u,v,a,b;
unsigned int ql[200001],qr[200001],qv[200001];
unsigned int arrlow[65537],prelow[65537];
unsigned int arrhigh[65537],prehigh[65537];
unsigned int reslow[65536],reshigh[65536];
void addlow(int l, int r)
{
	//cout<<"addlow "<<l<<' '<<r<<endl;
	arrlow[l]++;
	arrlow[r+1]--;
}
void addhigh(int l, int r)
{
	//cout<<"addhigh "<<l<<' '<<r<<endl;
	arrhigh[l]++;
	arrhigh[r+1]--;
}
int checklow(int l, int r)
{
//	cout<<"checklow "<<l<<' '<<r<<endl;
	return (prelow[r+1]-prelow[l]);
}
int checkhigh(int l, int r)
{
//	cout<<"checkhigh "<<l<<' '<<r<<endl;
	return (prehigh[r+1]-prehigh[l]);
}
void fail()
{
	cout<<"impossible";
	exit(0);
}
int main()
{
	fio;
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
		cin>>ql[i]>>qr[i]>>qv[i];
	}
	for (t=0;t<16;t++)
	{
	//	cout<<t<<endl;
		for (j=0;j<=(1<<m);j++) arrlow[j]=prelow[j]=0;
		for (j=0;j<=(1<<m);j++) arrhigh[j]=prehigh[j]=0;
		for (i=1;i<=n;i++) if (qv[i]&(1<<t))
		{
			
				addhigh(ql[i]>>m,qr[i]>>m);
			if ((ql[i]>>m)==(qr[i]>>m))
			{
			addlow(ql[i]&((1<<m)-1),qr[i]&((1<<m)-1));
			}
			else
			{
				addlow(ql[i]&((1<<m)-1),(1<<m)-1);
				addlow(0,qr[i]&((1<<m)-1));
				if ((qr[i]>>m)-(ql[i]>>m)>=2)
				{
					addlow(0,(1<<m)-1);
				}
			}
		}
		u=0;
		for (i=0;i<(1<<m);i++) 
		{
			u+=arrlow[i];
			if (u) arrlow[i]=1; else arrlow[i]=0;
			prelow[i+1]=prelow[i]+arrlow[i];
		}
		u=0;
		for (i=0;i<(1<<m);i++) 
		{
			u+=arrhigh[i];
			if (u) arrhigh[i]=1;else arrhigh[i]=0;
			prehigh[i+1]=prehigh[i]+arrhigh[i];
		}
		
		for (i=1;i<=n;i++) if (!(qv[i]&(1<<t)))
		{
			int u,v;
			if ((ql[i]>>m)==(qr[i]>>m))
			{
			u=checklow(ql[i]&((1<<m)-1),qr[i]&((1<<m)-1));
			v=checkhigh(ql[i]>>m,qr[i]>>m);
			if ((u)and(v)) fail();
			}
			else
			{
				
				u=checklow(ql[i]&((1<<m)-1),(1<<m)-1);
				v=checkhigh(ql[i]>>m,ql[i]>>m);
				if ((u)and(v)) fail();
				u=checklow(0,qr[i]&((1<<m)-1));
				v=checkhigh(qr[i]>>m,qr[i]>>m);
				if ((u)and(v)) fail();
				if ((qr[i]>>m)-(ql[i]>>m)>=2)
				{
					u=checklow(0,(1<<m)-1);
					v=checkhigh((ql[i]>>m)+1,(qr[i]>>m)-1);
					if ((u)and(v)) fail();
				}
			}
		}
		for (i=0;i<(1<<m);i++) reslow[i]+=(1<<t)*arrlow[i];
		for (i=0;i<(1<<m);i++) reshigh[i]+=(1<<t)*arrhigh[i];
	}
	cout<<"possible\n";
		for (i=0;i<(1<<m);i++) cout<<reslow[i]<<endl;
		for (i=0;i<(1<<m);i++) cout<<reshigh[i]<<endl;
}