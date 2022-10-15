// Problem: E. Vabank
// Contest: Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1483/problem/E
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
ll limit,balance,iter;
ll ask(ll x)
{
	iter++;
	if (limit==-1)
	{
		cout<<"? "<<x<<endl;
		string s;
		cin>>s;
		if (s=="Lucky!")
		{
			balance+=x;
			return 1;
		}
		else if (s=="Fraudster!")
		{
			balance-=x;
			return -1;
		}
		else
		{
			assert(0);
		}
	}
	else 
	{
		if (iter>105)
		{
			cout<<"FAILED: testcase "<<limit<<" took "<<iter<<" queries"<<endl;
			exit(0);
		}
		if (x<=limit) {balance+=x; return 1;}
		else if (x>limit)
		{
			balance-=x;
			if (balance<0) {cout<<"Can't pay after "<<iter<<" queries"<<endl; exit(0);}
			return -1;
        }
	}
}
void answer(ll x)
{
	if (limit==-1)
	{
		cout<<"! "<<x<<endl;
	}
	else
	{
	if (x==limit) 
	{
		if (iter>105)
		{
			cout<<"FAILED: testcase "<<limit<<" took "<<iter<<" queries"<<endl;
			exit(0);
		}
		if (iter>100) cout<<"NOTE: testcase "<<limit<<" took "<<iter<<" queries"<<endl;
	}
	else  {cout<<"Wrong answer after "<<iter<<" queries"; exit(0);}
	}
}
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
	//	if ((t1%100000)==0) cout<<"Finished "<<t1<<" testcases "<<endl;
	//	a=rand();
	//	b=rand();
	//	u=rand();
	//	v=rand();
	//	limit=(a<<45)+(b<<30)+(u<<15)+v;
	//	limit%=100000000000000;
	//	limit++;
	//	if ((t1%100000)==0) cout<<"limit= "<<limit<<endl;
      	balance=1;
  	    iter=0;
		limit=-1; // Toggle this when submitting
		ll l,r,mid;
		l=0;
		r=1;
		while(r<=1e14)
		{
			if (ask(r)==1)
			{
				l=r;
				r*=2;
			}
			else break;
		}
		r=min(r,1e14+1);
		while(r-l>1)
		{
	//		cout<<l<<' '<<r<<endl;
			if (r-l<=10)
			{
			mid=(l+r)/2;
			if (balance<mid) ask(l);
			else
			{
				if (ask(mid)==1) l=mid;
				else r=mid;
			}
			}
			else
			{
				ld g=ld(balance)/r;
				if (g<1) mid=l;
				else
				{
					g=min(g,ld(4));
					g=pow(g,0.4);
					g/=4;
		//			cout<<g<<endl;
					mid=floor(g*(r-l))+l;
		//			cout<<mid<<endl;
				}
				if (ask(mid)==1) l=mid;
				else r=mid;
			}
		}
		answer(l);
	}
}