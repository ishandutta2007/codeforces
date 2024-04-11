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

const int maxl = 70;
const LL Mod = 1e9 + 7;
LL inv[maxl * 2];
LL dp[2][maxl + 10][maxl + 10],
   ps[2][maxl + 10][maxl + 10];
LL N, K;

LL Pow(LL x, LL y) {
	LL ans = 1,
	   an = x;
	while (y) {
		if (y & 1)
			ans = (ans * an) % Mod;
		y >>= 1;
		an = (an * an) % Mod;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 100; i++)
		inv[i] = Pow(i, Mod - 2);
	cin >> N >> K;
	int cur = 0,
		prv = 1;
	for (int i = 0; i < maxl; i++)
		dp[cur][i][i] = 1;
	for (int i = 0; i < maxl; i++)
		for (int j = 0; j < maxl; j++)
			ps[cur][i + 1][j] = ps[cur][i][j] + dp[cur][i][j];
	for (int c = 0; c < K; c++) {
		swap(prv, cur);
		for (int i = 0; i <= maxl; i++)
			fill(ps[cur][i], ps[cur][i] + maxl, 0LL);
		for (int i = 0; i < maxl; i++) {
			LL coop = inv[i + 1];
			for (int j = 0; j <= i; j++) {
				dp[cur][i][j] = coop * (ps[prv][i + 1][j] - ps[prv][j][j]) % Mod;
				ps[cur][i + 1][j] = (ps[cur][i][j] + dp[cur][i][j]) % Mod;
			}
		}
	}
	LL ans = 1;
	for (LL fact = 2; fact * fact <= N; fact++) {
		int cnt = 0;
		while (N % fact == 0)
			N /= fact, cnt++;
		LL sum = 0;
		LL tmp = 1;
		for (int i = 0; i <= cnt; i++) {
			sum += dp[cur][cnt][i] * tmp;
			tmp = (tmp * fact) % Mod;
		}
		sum %= Mod;
		ans = (ans * sum) % Mod;
	}
	if (N > 1)
		ans = ans * ((dp[cur][1][1] * (N % Mod) + dp[cur][1][0]) % Mod) % Mod;
	cout << (ans + Mod) % Mod << endl;
	return 0;
}