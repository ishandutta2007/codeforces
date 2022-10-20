#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007, N = 100010, M = 71, MX = 20;

int last[M];
vector<int> p;
int dp[2][1 << 20];
int cnt[M], n;
int pw[N];

inline int mul(int u, int v) {
	return (long long) u * v % MOD;
}

inline int add(int u, int v) {
	u += v;
	if (u >= MOD) {
		u -= MOD;
	}
	return u;
}

int getMask(int u) {
	int res = 0;
	while (u > 1) {
		int x = last[u];
		while (u % p[x] == 0) {
			u /= p[x];
			res ^= (1 << x);
		}		
	}
	return res;
}

int main() {	
	memset(last, -1, sizeof last);
	for (int i = 2; i < M; i++) {
		if (last[i] < 0) {
			for (int j = i; j < M; j += i) {
				last[j] = p.size();
			}
			p.push_back(i);
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int u;
		scanf("%d", &u);
		cnt[u]++;
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = add(pw[i - 1], pw[i - 1]);
	}
	dp[0][0] = 1;
	int cur = 0;
	for (int i = 1; i < M; i++) {
		if (cnt[i] == 0) {
			continue;
		}
		for (int j = 0; j < (1 << MX); j++) {		
			dp[cur ^ 1][j] = 0;
		}
		int curMask = getMask(i);
		// cout << "curMask " << i << " " << curMask << endl;
		for (int j = 0; j < (1 << MX); j++) {
			dp[cur ^ 1][j] = add(dp[cur ^ 1][j], mul(dp[cur][j], pw[cnt[i] - 1]));
			dp[cur ^ 1][j ^ curMask] = add(dp[cur ^ 1][j ^ curMask], mul(dp[cur][j], pw[cnt[i] - 1]));
		}
		// for (int j = 0; j < (1 << MX); j++) {
		// 	cout << i << " " << j << " " << dp[cur ^ 1][j] << endl;
		// }
		// cout << endl;
		cur ^= 1;
	}
	printf("%d\n", (dp[cur][0] + MOD - 1) % MOD);
	return 0;
}