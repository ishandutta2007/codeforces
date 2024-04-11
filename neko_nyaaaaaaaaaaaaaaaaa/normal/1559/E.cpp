#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int mobius[MAX + 1];

void init() {
	for (int i = 1; i <= MAX; i++) {
		mobius[i] = 1;
	}

	bitset<MAX + 1> pr;
	for (int i = 2; i <= MAX; i++) {
		if (!pr[i]) {
			for (int j = i; j <= MAX; j += i) {
				mobius[j] *= -1;
				pr[j] = 1;
			}

			for (long long j = 1LL*i*i; j <= MAX; j += 1LL*i*i) {
				mobius[j] = 0;
			}
		}
	}
}

#define int long long
const int M = 998244353;

int get(int n, int m, vector<pair<int, int>> a, int g) {
	m /= g;
	vector<int> dp(m+1); dp[0] = 1;

	for (auto [l, r]: a) {
		l = (l+g-1)/g; r /= g;
		if (l > r) return 0; 

		vector<int> nxt(m+1);
		for (int i = 0; i <= m; i++) {
			int L = i+l, R = i+r+1;
			if (L <= m) {
				nxt[L] = (nxt[L] + dp[i]) % M;
			}
			if (R <= m) {
				nxt[R] = (nxt[R] - dp[i]) % M;
			}
		}

		for (int i = 1; i <= m; i++) {
			nxt[i] = (nxt[i] + nxt[i-1]) % M;
		}

		swap(nxt, dp);
	}

	int ans = 0;
	for (int i: dp) ans += i;
	return ans % M; 
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int n, m; cin >> n >> m;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (mobius[i] == 0) continue;

		ans = (ans + mobius[i]*get(n, m, a, i)) % M;
	}
	if (ans < 0) ans += M;
	cout << ans << '\n';

	return 0;
}