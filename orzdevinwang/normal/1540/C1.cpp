#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 120, M = N * N, mod = 1e9 + 7;
int n, q, l[N], r[N], b[N], qb[N];
mt19937_64 orz(time(0) ^ clock());
int rad(int l, int r) {
	return orz() % (r - l + 1) + l;
}
int dp[2][M], pr[M];
void calc() {
	int x, op = 0, mx = n * 100, mn = 0;
	cin >> x;
	dp[0][0] = 1;
	L(i, 1, n) {
		mn += qb[i] + x;
		op ^= 1, memset(dp[op], 0, sizeof(dp[op]));
		L(j, 0, mx) pr[j] = dp[op ^ 1][j];
		L(j, 1, mx) (pr[j] += pr[j - 1]) %= mod;
		L(j, max(mn, 0), mx) dp[op][j] = (pr[j] - (j - r[i] <= 0 ? 0 : pr[j - r[i] - 1]) + mod) % mod;
	}
	int ns = 0;
	L(i, 0, mx) (ns += dp[op][i]) %= mod;
	cout << ns << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> r[i];
	L(i, 1, n - 1) cin >> b[i], qb[i + 1] = b[i] + qb[i];
	cin >> q;
	while(q--) calc();
	return 0;
}