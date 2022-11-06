#include <bits/stdc++.h>
using namespace std;

int arr[100001], memo[100001];

int dp(int n) {
	if (n == 0) return 1;
	if (memo[n] != -1) return memo[n];
	if (arr[n] > arr[n - 1]) memo[n] = dp(n - 1) + 1;
	else memo[n] = 1;
	return memo[n];
}

int main() {
	memset(memo, -1, sizeof(memo));
	int n, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		m = max(m, dp(i));
	}
	printf("%d\n", m);
}