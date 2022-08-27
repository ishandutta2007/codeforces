// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 44;
int n, m, dp[N][N], a[N], b[N];
struct Matrix { ll f[N][N]; } G;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res; memset(res.f, 0x3f, sizeof(res.f));
	L(i, 0, n) L(j, 0, n) L(k, 0, n) res.f[i][j] = min(res.f[i][j], aa.f[i][k] + bb.f[k][j]);
	return res;
}
Matrix operator ^ (Matrix aa, int bb) {
	Matrix res; memset(res.f, 0x3f, sizeof(res.f)); L(i, 0, n) res.f[i][i] = 0;
	for(; bb; bb >>= 1, aa = aa * aa) if(bb & 1) res = res * aa;
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) scanf("%d", &b[i]);
	L(kk, 0, n) {
		memset(dp, 0x3f, sizeof(dp));
		dp[0][kk] = 0;
		L(i, 1, n) {
			L(j, 0, 2 * n) {
				if(j > 0) dp[i][j] = min(dp[i - 1][j - 1] + a[i], dp[i][j]);
				if(j < 2 * n) dp[i][j] = min(dp[i - 1][j + 1] + b[i], dp[i][j]);
			}
		} 
		L(j, 0, n) G.f[kk][j] = dp[n][j];
	}
	Matrix res = (G ^ m);
	printf("%lld\n", res.f[0][0]);
	return 0;
}