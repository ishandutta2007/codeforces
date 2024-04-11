#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 120, M = N * N, mod = 1e9 + 7;
int n, q, l[N], r[N], b[N], qb[N], L, R, sum;
mt19937_64 orz(time(0) ^ clock());
int rad(int l, int r) {
	return orz() % (r - l + 1) + l;
}
int dp[2][M], pr[M];
map < int, int > mp;
void calc() {
	int x, op = 0, mn = 0;
	cin >> x, x = min(x, R), x = max(x, L);
	if(mp.count(x)) return cout << mp[x] << '\n', void();
	memset(dp, 0, sizeof(dp)), dp[0][0] = 1;
	L(i, 1, n) {
		mn += qb[i] + x;
		op ^= 1, memset(dp[op], 0, sizeof(dp[op]));
		L(j, 0, i * 100) pr[j] = dp[op ^ 1][j];
		L(j, 1, i * 100) (pr[j] += pr[j - 1]) %= mod;
		L(j, max(mn, 0), i * 100) dp[op][j] = (pr[j] - (j - r[i] <= 0 ? 0 : pr[j - r[i] - 1]) + mod) % mod;
	}
	int ns = 0;
	L(i, 0, n * 100) (ns += dp[op][i]) %= mod;
	cout << ns << '\n';
	mp[x] = ns;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> r[i];
	L(i, 1, n - 1) cin >> b[i], qb[i + 1] = b[i] + qb[i];
	L(i, 2, n) sum += qb[i], L = min(L, - sum / i - 2);
	R = L + 104;
	cin >> q;
	while(q--) calc();
	return 0;
}