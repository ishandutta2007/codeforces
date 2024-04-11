#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define ll long long
#define me(f, x) memset(f, x, sizeof(f)) 
using namespace std;
const int N = 1e6 + 7, M = 20, mod = 998244353;
int d, n, m, q, l[N], p[N];
int tk[M][M], fi[M], en[M], mit = 1;
int c1[M][M], c2[M], c3[M];
void make(int x) {
	L(i, 1, m) L(j, i + 1, m) 
		if(p[i] <= x && x <= p[j]) 
			tk[i][j] = (ll) tk[i][j] * min(min(abs(x - p[i]), abs(x - p[j])), d + 1) % mod;
	L(i, 1, m) 
		if(x < p[i]) fi[i] = (ll) fi[i] * min(abs(x - p[i]), d + 1) % mod;
		else en[i] = (ll) en[i] * min(abs(x - p[i]), d + 1) % mod;
}
int dp[M];
int slv() {
	me(dp, 0);
	int ns = mit;
	L(i, 1, m) {
		dp[i] = fi[i];
		L(j, 1, i - 1) (dp[i] += (ll) tk[j][i] * dp[j] % mod) %= mod;
		dp[i] = mod - dp[i], (ns += (ll) dp[i] * en[i] % mod) %= mod;
	}
	return ns;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> d >> n >> m;
	L(i, 1, n) cin >> l[i];
	L(i, 1, m) cin >> p[i];
	sort(p + 1, p + m + 1);
	L(i, 1, m) L(j, i + 1, m) tk[i][j] = 1;
	L(i, 1, m) fi[i] = en[i] = 1;
	L(i, 1, n + 1) mit = (ll) mit * (d + 1) % mod;
	L(i, 1, n) make(l[i]);
	L(i, 1, m) L(j, i + 1, m) c1[i][j] = tk[i][j];
	L(i, 1, m) c2[i] = fi[i], c3[i] = en[i];
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		L(i, 1, m) L(j, i, m) tk[i][j] = c1[i][j];
		L(i, 1, m) fi[i] = c2[i], en[i] = c3[i];
		make(x), cout << slv() << '\n';
	}
	return 0; 
}