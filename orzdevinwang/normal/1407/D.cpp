#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int n, m, s[N], dp[N], atot, a[N], btot, b[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
	memset(dp, 0x3f, sizeof(dp));
	a[++atot] = 1, b[++btot] = 1, dp[1] = 0;
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		while(atot && s[i] >= s[a[atot]]) {
			if(s[i] != s[a[atot]]) dp[i] = min(dp[i], dp[a[atot - 1]] + 1);
			--atot;
		}
		while(btot && s[i] <= s[b[btot]]) {
			if(s[i] != s[b[btot]]) dp[i] = min(dp[i], dp[b[btot - 1]] + 1);
			--btot;
		}
		a[++atot] = i, b[++btot] = i;
	}
	printf("%d\n", dp[n]);
	return 0;
}