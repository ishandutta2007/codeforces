
// Problem : C. Knights
// Contest : Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL : https://codeforces.com/contest/1067/problem/C
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
#define dx 2
#define dy 2
//---------END-------//

const ll Mod = 1e9 + 7;
const ll N = 151;
ll dp[2][2][N][N][N];
ll pr[2][2][N][N][N];
ll res = 0;
 
void add(ll &a, ll b) {
	if (b < 0)
		b += Mod;
	a = (a + b) % Mod;
}
 
int main() {
    fio;
	ll n, m;
	cin >> n >> m;
	for (ll c = 1; c <= m; c++) {
		for (ll u = 1; u <= n; u++)
			for (ll d = u; d <= n; d++) {
				add(dp[1][1][c][u][d], pr[1][1][c - 1][u][d]);
				add(dp[1][1][c][u][d], (d - u + 2) * (d - u + 1) / 2);
					
				add(dp[0][1][c][u][d], (d + 1) * d / 2 - u * (u - 1) / 2);
				add(dp[0][1][c][u][d], pr[0][1][c - 1][1][d] - pr[0][1][c - 1][1][u - 1] - pr[0][1][c - 1][u + 1][d]);
				add(dp[0][1][c][u][d], pr[1][1][c - 1][u + 1][d]);
				
				add(dp[1][0][c][u][d], (n - u + 2) * (n - u + 1) / 2 - (n - d + 1) * (n - d) / 2);
				add(dp[1][0][c][u][d], pr[1][0][c - 1][u][n] - pr[1][0][c - 1][u][d - 1] - pr[1][0][c - 1][d + 1][n]);
				add(dp[1][0][c][u][d], pr[1][1][c - 1][u][d - 1]);
				
				add(dp[0][0][c][u][d], (n + 1) * n / 2 - u * (u - 1) / 2 - (n - d + 1) * (n - d) / 2);
				add(dp[0][0][c][u][d], pr[0][0][c - 1][1][n] - pr[0][0][c - 1][1][d - 1] - pr[0][0][c - 1][u + 1][n] + pr[0][0][c - 1][u + 1][d - 1]);
				add(dp[0][0][c][u][d], pr[0][1][c - 1][1][d - 1] - pr[0][1][c - 1][1][u - 1] - pr[0][1][c - 1][u + 1][d - 1]);
				add(dp[0][0][c][u][d], pr[1][0][c - 1][u + 1][n] - pr[1][0][c - 1][u + 1][d - 1] - pr[1][0][c - 1][d + 1][n]);
				add(dp[0][0][c][u][d], pr[1][1][c - 1][u + 1][d - 1]);
			}
		for (ll s = 0; s < 4; s++)
			for (ll len = 0; len < n; len++) 
				for (ll u = 1; u + len <= n; u++) {
					add(pr[s / 2][s % 2][c][u][u + len], pr[s / 2][s % 2][c][u][u + len - 1]);
					add(pr[s / 2][s % 2][c][u][u + len], pr[s / 2][s % 2][c][u + 1][u + len]);
					add(pr[s / 2][s % 2][c][u][u + len], -pr[s / 2][s % 2][c][u + 1][u + len - 1]);
					add(pr[s / 2][s % 2][c][u][u + len], dp[s / 2][s % 2][c][u][u + len]);
				}		
		res = (res + (n + 1) * n / 2) % Mod;
		for (ll u = 1; u <= n; u++)
			for (ll d = u; d <= n; d++)
				res = (res + dp[0][0][c - 1][u][d]) % Mod;
	}
	cout << res << endl;
}