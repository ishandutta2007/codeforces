#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n;
char s[N];
int dp[N][8]; 
inline void Get(int n, int msk) {
	int up[3] = {s[n] - '0', s[n] - '0', s[n] - '0'};
	L(a, 0, 2) if(!(msk >> a & 1)) up[a] = 1;
	int ret = 0;
	L(a, 0, up[0]) 
		L(b, 0, up[1]) 
			L(c, 0, up[2]) {
				if((a ^ b) + (b ^ c) != (a ^ c))
					continue ;
				(ret += dp[n - 1][msk & ((a == up[0]) | ((b == up[1]) << 1) | ((c == up[2]) << 2))]) %= mod;
			}
	dp[n][msk] = ret;
//	cout << n << ' ' << msk << " : " << ret << endl; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);  
	cin >> (s + 1), n = strlen(s + 1);
	int prd = 0;
	L(i, 1, n) {
		prd = ((ll) prd * 2 % mod + s[i] - '0') % mod;
	}
	(prd += 1) %= mod;
	L(i, 0, 7) dp[0][i] = 1;
	reverse(s + 1, s + n + 1);
	L(i, 1, n) L(j, 0, 7) Get(i, j);
//	cout << dp[n][7] << '\n';
	int ns = ((ll) prd * prd % mod * prd % mod - (ll) dp[n][7] * 3 % mod + mod) % mod;
//	cout << dp[n][7] << ' ' << prd << endl;
	(ns += (ll) prd * prd % mod * 3 % mod) %= mod;
	(ns += mod - prd) %= mod;
	cout << ns << '\n';
	return 0;
}