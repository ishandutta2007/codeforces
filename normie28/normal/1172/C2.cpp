
// Problem : D. Boboniu and Jianghu
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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

const int mod = 998244353;
const int maxn = 3005;
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> w(n + 1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> w[i];
	int sumgood = 0, sumbad = 0;
	for(int i = 0; i < n; i++) {
		if(a[i]) sumgood += w[i];
		else sumbad += w[i];
	}
	int sum = sumgood + sumbad;
	function<int(int ,int)> power;
	power = [&](int num, int mul) {
		int res = 1;
		while(mul > 0) {
			if((mul & 1))
				res = 1ll * num * res % mod;
			num = 1ll * num * num % mod;
			mul = mul >> 1; 
		}
		return res;
	};
	vector<vector<int>> dp(m + 1,vector<int>(m + 1));
	dp[0][0] = 1;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m - i; j++) {
			if(dp[i][j] == 0) continue;
			int good = sumgood + i,bad = sumbad - j;
			dp[i + 1][j] = (dp[i + 1][j] + 1ll * good * power(good + bad, mod - 2) % mod * dp[i][j] % mod) % mod;
			dp[i][j + 1] = (dp[i][j + 1] + 1ll * bad * power(good + bad, mod - 2) % mod * dp[i][j] % mod) % mod;
		}
	int goodexp = 0,badexp = 0;
	for(int i = 0; i <= m; i++) {
		goodexp = 1ll * (goodexp + 1ll * dp[i][m - i] * i % mod) % mod;
		badexp = 1ll * (badexp + 1ll * dp[m - i][i] * i % mod) % mod;
	}
	for(int i = 0; i < n; i++) {
		int ans;
		if(a[i]) ans = 1ll * w[i] * (1ll + 1ll * goodexp * power(sumgood, mod - 2) % mod) % mod;
		else ans = 1ll * w[i] * ((1ll - 1ll * badexp * power(sumbad, mod - 2) % mod + mod) % mod) % mod;
		cout << ans << "\n";
	}
	return 0;
}