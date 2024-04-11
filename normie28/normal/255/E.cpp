
// Problem : E. Furlo and Rublo and Game
// Contest : Codeforces - Codeforces Round #156 (Div. 2)
// URL : https://codeforces.com/problemset/problem/255/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 1000100;
const double EPS = 1e-9;
int dp[N][10];
int cnt(int l,int r,int val){
	return dp[r][val]-dp[l-1][val];
}
ll a;
int main(){
	fio;
	dp[0][0] = dp[1][0] = 1;
 
	for(int i = 2; i < N; ++i) {
		ll l = pow(i, 0.25);
		while(l*l*l*l<i) l++;
		ll r = pow(i, 0.5)+EPS;
		while(r*r>i)r--;
		int g=0;
		if(r>=l)
			while(cnt(l,r,g))
				g++;
		for(int j=0;j<10;j++)
			dp[i][j] = dp[i-1][j];
		dp[i][g]++;
	}
 
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		cin>>a;
		ll l = pow(a, 0.25);
		while(l*l*l*l<a) l++;
		ll r = pow(a, 0.5)+EPS;
		while(r*r>a)r--;
		int g=0;
		if(r>=l)
			while(cnt(l,r,g))
				g++;	
		ans ^= g;
	}
 
	if(!ans) cout << "Rublo";
	else cout << "Furlo";
 
}