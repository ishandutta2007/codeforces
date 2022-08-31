#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 307;
const int mod = 1e4 + 7;
int n, m, maxn, g[N];
char s[N];
struct Matix {
	int f[N][N];
	void clear() {
		L(i, 1, maxn) L(j, 1, maxn) f[i][j] = 0;
	}
	void start() {
		clear(); L(i, 1, maxn) f[i][i] = 1;
	}
} G;
Matix operator * (Matix aa, Matix bb) {
	Matix res; res.clear();
	L(i, 1, maxn) L(j, i, maxn) L(k, i, j) (res.f[i][j] += 1ll * aa.f[i][k] * bb.f[k][j]) %= mod;
	return res;
}
Matix operator ^ (Matix aa, int bb) {
	Matix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int dp[N][N][N], cnt[N];
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	scanf("%d", &m);
	int len = (m + n + 1) / 2; maxn = n + (n + 3) / 2;

	dp[1][n][0] = 1;
	R(Len, n, 1) L(l, 1, n - Len + 1) {
		int r = l + Len - 1;
		if(s[l] ^ s[r]) {
			R(k, n - 1, 1) dp[l][r][k] = dp[l][r][k - 1];
			dp[l][r][0] = 0;
			L(k, 0, n - 1) (dp[l + 1][r][k] += dp[l][r][k]) %= mod, (dp[l][r - 1][k] += dp[l][r][k]) %= mod;
		}
		else if(r - l + 1 > 2) L(k, 0, n - 1) (dp[l + 1][r - 1][k] += dp[l][r][k]) %= mod;
	}
	L(l, 1, n) L(r, l, min(l + 1, n)) if(s[l] == s[r]) L(k, 0, n - 1) (cnt[k] += dp[l][r][k]) %= mod;
	L(i, 1, n - 1) G.f[i][i + 1] = 1;
	L(i, 2, n) G.f[i][i] = 24; 
	L(i, n + 1, maxn - 1) G.f[i][i] = 25, G.f[i][i + 1] = 1;
	G.f[maxn][maxn] = 26;
	L(i, 0, n - 1) G.f[i + 1][maxn - (n + 1 - i) / 2] = cnt[i];
//	cout << "len = " << len + 1 << endl;
	int res = (G ^ (len + 1)).f[1][maxn];
//	L(i, 1, maxn) L(j, 1, maxn) if(G.f[i][j] && i ^ j) cout << i << " " << j << " : " << G.f[i][j] << endl;
	if(!((n + m) & 1)) printf("%d\n", res);
	else {
		L(l, 1, n) L(k, 0, n - 1) (cnt[k] += mod - dp[l][l][k]) %= mod;
		L(i, 0, n - 1) G.f[i + 1][maxn - (n + 1 - i) / 2] = cnt[i];
		G.f[maxn][maxn] = 0;
		printf("%d\n", (res + mod -  (G ^ (len + 1)).f[1][maxn]) % mod);
	}
//	 if((n + m) & 1) {
//	 	dp[0][1][n] = 1;
//	 	L(now, 1, len) {
//	 		g[now] = 1ll * g[now - 1] * 26 % mod;
//	 		L(l, 1, n) L(r, l, n) {
//	 			if(s[l] == s[r]) {
//	 				if(l == r || (l + 1 == r && now ^ len)) (g[now] += dp[now - 1][l][r]) %= mod; 
//	 				(dp[now][l][r] += 25ll * dp[now - 1][l][r] % mod) %= mod;
//	 				if(r - l + 1 > 2) (dp[now][l + 1][r - 1] += dp[now - 1][l][r]) %= mod; 
//	 			}
//	 			else {
//	 				(dp[now][l][r] += 24ll * dp[now - 1][l][r] % mod) %= mod;
//	 				if(l ^ r) (dp[now][l + 1][r] += dp[now - 1][l][r]) %= mod, (dp[now][l][r - 1] += dp[now - 1][l][r]) %= mod;
//	 			}
//	 		}
//	 	}
//	 }
//	 else {
//	 	dp[0][1][n] = 1;
//	 	L(now, 1, len) {
//	 		g[now] = 1ll * g[now - 1] * 26 % mod;
//	 		L(l, 1, n) L(r, l, n) {
//	 			if(s[l] == s[r]) {
//	 				if(r - l + 1 <= 2) (g[now] += dp[now - 1][l][r]) %= mod; 
//	 				(dp[now][l][r] += 25ll * dp[now - 1][l][r] % mod) %= mod;
//	 				if(r - l + 1 > 2) (dp[now][l + 1][r - 1] += dp[now - 1][l][r]) %= mod; 
//	 			}
//	 			else {
//	 				(dp[now][l][r] += 24ll * dp[now - 1][l][r] % mod) %= mod;
//	 				if(l ^ r) (dp[now][l + 1][r] += dp[now - 1][l][r]) %= mod, (dp[now][l][r - 1] += dp[now - 1][l][r]) %= mod;
//	 			}
//	 		}
//	 	}
//	 }
//	 printf("%d\n", g[len]);
	return 0;
}
/*
abab
4
*/