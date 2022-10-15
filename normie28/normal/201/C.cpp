
// Problem : C. Fragile Bridges
// Contest : Codeforces - Codeforces Round #127 (Div. 1)
// URL : https://codeforces.com/problemset/problem/201/C
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
ll A[100010];
ll B[2][100010];
ll C[2][100010];
 
int main () {
	int N;
	cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		if (i) {
			if (A[i - 1] > 1) {
				B[0][i] = B[0][i - 1] + A[i - 1] - (A[i - 1] & 1);
			}
			B[1][i] = 
				max(B[1][i - 1] + A[i - 1] - 1 + (A[i - 1] & 1), A[i - 1]);
			B[1][i] = max(B[1][i], B[0][i]);
		}
	}
	
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] > 1) {
			C[0][i] = C[0][i + 1] + A[i] - (A[i] & 1);
		}
		C[1][i] = max(C[1][i + 1] + A[i] - 1 + (A[i] & 1), A[i]);
		C[1][i] = max(C[1][i], C[0][i]);
	}
	
	ll ans = 0;
	
	for (int i = 0; i <= N; i++) {
		ans = max(ans, C[0][i] + B[1][i]);
		ans = max(ans, B[0][i] + C[1][i]);
	}
	
	cout << ans << endl;
}