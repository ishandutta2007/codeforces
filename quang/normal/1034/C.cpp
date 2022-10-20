#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD = 1000000007;

inline int add(int u, int v) {
	u += v;
	if (u >= MOD) {
		u -= MOD;
	}
	return u;
}

int n;
int a[N];
int p[N];
long long sum = 0;
long long tot[N];
int cnt[N];
int dp[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", p + i);
	}
	for (int i = n; i >= 1; i--) {
		tot[i] += a[i];
		tot[p[i]] += tot[i];
		long long foo = __gcd(sum, tot[i]);
		long long x = sum / foo;
		if (x <= n) {
			cnt[x]++;
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = i + i; j <= n; j += i) {
			cnt[j] += cnt[i];
		}
	}
	for (int i = n; i > 0; i--) {
		if (cnt[i] == i) {	
			dp[i] = 1;
			for (int j = i + i; j <= n; j += i) {
				dp[i] = add(dp[i], dp[j]);
			}
		}
	}
	cout << dp[1] << endl;
	return 0;
}