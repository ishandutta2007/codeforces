//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const LL Mod = 998244353;
LL dp[100][100],
   pd[100][100],
   w[100],
   r[100],
   a[100],
   sum[2];
int n, m;

LL Pow(LL x, LL y) {
	LL ans = 1,
	   an = x;
	while (y) {
		if (y & 1LL)
			ans = (ans * an) % Mod;
		an = an * an % Mod;
		y >>= 1;
	}
	return ans;
}

LL Div(LL x, LL y) {
	return x * Pow(y, Mod - 2) % Mod;
}

LL gp(LL x, LL y) {
	return Div(x, x + y);
}

LL bp(LL x, LL y) {
	return Div(y, x + y);
}

void gsolve(int id) {
	memset(pd, 0, sizeof pd);
	pd[0][0] = 1;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= i; j++) {
			pd[i][j] %= Mod;
			if (!pd[i][j])
				continue;
			r[id] = (r[id] + ((w[id] + j) * pd[i][j] % Mod) * dp[i][m - i]) % Mod;
			LL p = gp(w[id] + j, sum[1] - w[id] + i - j);
			pd[i + 1][j + 1] += pd[i][j] * p;
			pd[i + 1][j] += pd[i][j] * (1 - p);
		}
	r[id] += Mod;
	r[id] %= Mod;
}

void bsolve(int id) {
	memset(pd, 0, sizeof pd);
	pd[0][0] = 1;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= i; j++) {
			pd[i][j] %= Mod;
			if (!pd[i][j])
				continue;
			r[id] = (r[id] + ((w[id] - j) * pd[i][j] % Mod) * dp[m - i][i]) % Mod;
			LL p = gp(w[id] - j, sum[0] - w[id] - i + j);
			pd[i + 1][j + 1] += pd[i][j] * p;
			pd[i + 1][j] += pd[i][j] * (1 - p);
		}
	r[id] += Mod;
	r[id] %= Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		sum[a[i]] += w[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++) {
			dp[i][j] %= Mod;
			if (!dp[i][j]) continue;
			dp[i + 1][j] += dp[i][j] * gp(sum[1] + i, sum[0] - j);
			dp[i][j + 1] += dp[i][j] * bp(sum[1] + i, sum[0] - j);
		}
	for (int i = 0; i < n; i++) {
		if (a[i])
			gsolve(i);
		else
			bsolve(i);
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << '\n';
	return 0;
}