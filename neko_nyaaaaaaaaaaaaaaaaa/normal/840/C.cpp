#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, p;
int M = 1e9+7;
int ft[303];
int nCr[303][303];
int dp[303][303];
int a[303];

void init() {
      ft[0] = 1;
      for (int i = 1; i <= 300; i++) {
            ft[i] = (ft[i-1]*i) % M;
      }
      
	nCr[0][0] = 1;
	for (int i = 1; i <= 300; i++) {
		nCr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % M;
		}
	}
}

int solve() {
	dp[0][0] = 1;

	int sum = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (dp[i][j] == 0) continue;

			for (int g = 0; g <= min(a[i], sum - j); g++) {
				for (int b = 0; b <= min(a[i] - g, j); b++) {
					int r = a[i] - g - b;

					dp[i + 1][j - b + a[i] - b - g] += 
						dp[i][j] * nCr[j][b] % M * nCr[sum - j][g] % M * nCr[max(b + g - 1 + r, 0LL)][r] % M;

					dp[i + 1][j - b + a[i] - b - g] %= M;
				}
			}
		}

		sum += a[i];
	}

	return dp[n][0];
}

int is_sqr(int x) {
	int k = sqrtl(x);
	return k*k == x;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	cin >> n;

	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	vector<int> group(n);
	for (int i = 0; i < n; i++) {
		if (group[i]) continue;

		group[i] = ++p;
		for (int j = i+1; j < n; j++) {
			if (group[j]) continue;

			if (is_sqr(x[i]*x[j])) group[j] = group[i];
		}
	}

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[group[i]]++;
	}

      int ans = 1;

	p = 0;
	for (auto u: mp) {
		a[p++] = u.second;
		ans = (ans * ft[u.second]) % M;
	}
	n = p;

	ans = (ans * solve()) % M;
	
	cout << ans;

	return 0;
}