
// Problem : E. Bash Plays with Functions
// Contest : Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/problemset/problem/757/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define For(i,__,___) for(i=__;i<=___;i++)
#define Rep(i,__,___) for(i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 1000005;
 
int dp[N][20], pri[N], pn, vis[N],i;
 
void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}
 
int main() {
	fio;
	for (i = 2; i < N; i++) {
		if (vis[i]) continue;
		pri[pn++] = i;
		if (1LL * i * i >= 1LL * N) continue;
		for (int j = i * i; j < N; j += i)
			vis[j] = 1;
	}
	for (i = 1; i < 20; i++) dp[0][i] = 2;
	for (i = 1; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 20; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	}
	int q;
	cin>>q;
	int r, n;
	while (q--) {
		cin>>r>>n;
		int res = 1;
		for (i = 0; i < pn && pri[i] * pri[i] <= n; i++) {
			if (n % pri[i] == 0) {
				int cnt = 0;
				while (n % pri[i] == 0) {
					cnt++;
					n /= pri[i];
				}
				res = 1LL * res * dp[r][cnt] % MOD;
			}
		}
		if (n != 1) res = 1LL * res * dp[r][1] % MOD;
		cout<<res<<endl;
	}
}