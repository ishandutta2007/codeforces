#include <bits/stdc++.h>
using namespace std;

int n;
int len[305];
int dp[100005];

int c[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 100000; i++) {
		dp[i] =	1000000000; 
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &len[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		if (len[i] < 100000) {
			dp[len[i]] = min(dp[len[i]], c[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int x = __gcd(len[i], len[j]);
			if (x < 100000) {
				dp[x] = min(dp[x], c[i] + c[j]);
			}
		}
	}
	for (int i = 50000; i >= 1; i--) {
		for (int j = 0; j < n; j++) {
			int x = __gcd(i, len[j]);
			dp[x] = min(dp[x], dp[i] + c[j]);
		}
	}
	if (dp[1] == 1000000000) {
		printf("-1\n");
	} else {
		printf("%d\n",dp[1]);
	}
}