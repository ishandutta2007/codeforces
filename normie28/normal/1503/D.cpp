// Problem: D. Flip the Cards
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b,res;
int arr[200001],brr[200001],sw[200001];
int ind[400001],done[400001];
void fail()
{
	cout<<-1;
	exit(0);
}
void solve(int l, int r)
{
//	cout<<"new iteration "<<l<<' '<<r<<endl;
	if (l>r) return;
	int cnt0=0,cnt1=0,ln,rn;
	vector<int> top,bot;
	bot.push_back(ind[r]);
	while((top.size())or(bot.size()))
	{
		if (bot.size())
		{
			ln=l;
			sort(bot.begin(),bot.end(),[](int a, int b){return (arr[a]<arr[b]);});
			for (int i=1;i<bot.size();i++) if (brr[bot[i-1]]<brr[bot[i]]) fail();
			for (auto g : bot) 
			{
		//		cout<<"proc "<<g<<endl;
				ln=max(ln,arr[g]);
				done[arr[g]]=1;
				done[brr[g]]=1;
				if (sw[g]) cnt1++; else cnt0++;
			}
			for (int i=ln;i>=l;i--) if (!done[i])
			{
				if (ind[i]>0) fail();
				else top.push_back(-ind[i]);
			}
			l=ln;
			bot.clear();
		}
		else
		{
			rn=r;
			sort(top.begin(),top.end(),[](int a, int b){return (arr[a]<arr[b]);});
			for (int i=1;i<top.size();i++) if (brr[top[i-1]]<brr[top[i]]) fail();
			for (auto g : top) 
			{
			//	cout<<"proc "<<g<<endl;
				rn=min(rn,brr[g]);
				done[arr[g]]=1;
				done[brr[g]]=1;
				if (sw[g]) cnt0++; else cnt1++;
			}
			for (int i=rn;i<=r;i++) if (!done[i])
			{
				if (ind[i]<0) fail();
				else bot.push_back(ind[i]);
			}
			r=rn;
			top.clear();
		}
	}
	res+=min(cnt0,cnt1);
	solve(l+1,r-1);
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i]>>brr[i];
		if (arr[i]>brr[i])
		{
			sw[i]=1;
			swap(arr[i],brr[i]);
		}
		ind[arr[i]]=-i;
		ind[brr[i]]=i;
	}
	solve(1,2*n);
	cout<<res;
}