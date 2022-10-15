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
#define int long long
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b,x[3],len;
int dp[10001][3];
int cnt[21];
int get(int x, int y)
{
	if (x>50) 
	{
		x-=51;
		x%=len;
		x+=51;
	}
	return dp[x][y];
}
int arr[300001];
signed main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
	cin>>n>>x[0]>>x[1]>>x[2];
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	for (i=1;i<=100;i++)
	{
		cnt[dp[max(0,i-x[0])][0]]++;
		cnt[dp[max(0,i-x[1])][1]]++;
		cnt[dp[max(0,i-x[2])][2]]++;
		for (j=0;j<3;j++) if (!cnt[j]) break;
		dp[i][0]=j;
		cnt[dp[max(0,i-x[0])][0]]--;
		cnt[dp[max(0,i-x[1])][1]]--;
		cnt[dp[max(0,i-x[2])][2]]--;
		
		
		cnt[dp[max(0,i-x[0])][0]]++;
	//	cnt[dp[max(0,i-x[1])][1]]++;
		cnt[dp[max(0,i-x[2])][2]]++;
		for (j=0;j<3;j++) if (!cnt[j]) break;
		dp[i][1]=j;
		cnt[dp[max(0,i-x[0])][0]]--;
	//	cnt[dp[max(0,i-x[1])][1]]--;
		cnt[dp[max(0,i-x[2])][2]]--;
		
		
		cnt[dp[max(0,i-x[0])][0]]++;
		cnt[dp[max(0,i-x[1])][1]]++;
	//	cnt[dp[max(0,i-x[2])][2]]++;
		for (j=0;j<3;j++) if (!cnt[j]) break;
		dp[i][2]=j;
		cnt[dp[max(0,i-x[0])][0]]--;
		cnt[dp[max(0,i-x[1])][1]]--;
	//	cnt[dp[max(0,i-x[2])][2]]--;
	//	cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl; 
	}
	for (len=1;len<=10;len++)
	{
		a=1;
		for (i=1;50+len+i<=100;i++) if (dp[50+i][0]!=dp[50+len+i][0]) a=0;
		if (a) break;
	}
	//cout<<len<<endl;
	u=0;
	for (i=1;i<=n;i++) {cin>>arr[i]; u^=get(arr[i],0);}
	int res=0;
	if (u==0) res=0;
	else
	{
		for (i=1;i<=n;i++) for (j=0;j<3;j++)
		{
			if ((get(arr[i],0)^get(max(0,arr[i]-x[j]),j))==u) res++;
		}
	}
	cout<<res<<endl;
	}
}