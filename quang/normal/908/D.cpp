#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int MOD = 1000000007;

inline int add(int u, int v) {
	u += v;
	if (u >= MOD) {
		u -= MOD;
	}
	return u;
}

inline int sub(int u, int v) {
	u -= v;
	if (u < 0) {
		u += MOD;
	}
	return u;
}

inline int mul(int u, int v) {
	return (long long)u * v % MOD;
}

inline int power(int u, int v) {
	int res = 1;
	while (v) {
		if (v & 1) {
			res = mul(res, u);
		}
		u = mul(u, u);
		v >>= 1;
	}
	return res;
}

inline int rev(int u) {
	return power(u, MOD - 2);
}

int k, pa, pb;
int A, B;
int dp[N][N];

int main() {
	scanf("%d %d %d", &k, &pa, &pb);
	int res = 0;
	int foo = rev((pa + pb) % MOD);
	A = mul(pa, foo);
	B = mul(pb, foo);
	dp[1][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < k; j++) {
			if (i < k) {
				dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], A));
			}
			int s = i + j;
			if (s >= k) {
				if (i == k) {
					continue;
				}
				int ans = mul(s, B);
				ans = mul(ans, dp[i][j]);
				res = add(res, ans);
			} else {
				dp[i][i + j] = add(dp[i][i + j], mul(dp[i][j], B));
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int foo = sub(1, A);
		int ans1 = add(A, mul(k + i, foo));
		int ans2 = mul(foo, foo);
		int ans = mul(ans1, rev(ans2));
		ans = mul(ans, B);
		ans = mul(ans, dp[k][i]);
		res = add(res, ans);
	}
	cout << res << endl;
	// cout << "1/16 " << rev(16) << endl;
	// cout << "1/4 " << rev(4) << endl;
	// cout << "1/2 " << rev(2) << endl;
	return 0;
}