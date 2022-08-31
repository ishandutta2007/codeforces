#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e6 + 7;
int n;
ll ra, rb, rc, d, a[N], suma[N], sumb[N]; // suma : all || sumb : two's, boss -1
ll qz[N], dp[N], ans; // from 1 to start.
int main() {
	scanf("%d%lld%lld%lld%lld", &n, &ra, &rb, &rc, &d);
	L(i, 1, n) {
		scanf("%d", &a[i]);
		suma[i] = ra * a[i] + rc;
		sumb[i] = min(ra * (a[i] + 1), rb) + ra;
		qz[i] = qz[i - 1] + sumb[i];
	}
	dp[1] = suma[1], dp[2] = min(suma[1] + suma[2] + d, d * 3 + sumb[1] + sumb[2]);
	L(i, 3, n) 
		dp[i] = min(dp[i - 2] + d * 4 + sumb[i] + sumb[i - 1], dp[i - 1] + d + suma[i]);
	ans = dp[n];
	L(i, 1, n - 1) ans = min(ans, dp[i] + ((n - i) * 2 - 1) * d + min(d * 2 + sumb[n], suma[n]) + qz[n - 1] - qz[i]);
	printf("%lld\n", ans);
	return 0;
}