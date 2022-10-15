
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
const int maxn=160+5,mod=51123987;
bool _1; 
int n,res;
string s;
int nxt[maxn][5];
int dp[maxn][55][55][55]; 
 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
bool _2;
int main(){
    fio;
    cin>>n>>s; 
    s=" "+s;
	nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
	for(int i=n;i>=1;--i){
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][2]=nxt[i+1][2];
		if(s[i]=='a')nxt[i][0]=i;
		if(s[i]=='b')nxt[i][1]=i;
		if(s[i]=='c')nxt[i][2]=i;
	}
	
	dp[1][0][0][0]=1;
	int S=(n+2)/3;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=S;++j)
			for(int k=0;k<=S;++k)
				for(int l=0;l<=S;++l){
					if(j+k+l==n && abs(j-k)<=1 && abs(j-l)<=1 && abs(k-l)<=1){
						add(res,dp[i][j][k][l]);
					}
					add(dp[nxt[i][0]][j+1][k][l],dp[i][j][k][l]);
					add(dp[nxt[i][1]][j][k+1][l],dp[i][j][k][l]);
					add(dp[nxt[i][2]][j][k][l+1],dp[i][j][k][l]);
				}
	cout<<res;
}