#include <stdio.h>
#include <algorithm>

#define N 100010

long long arr[N];
long long dp[N];
int n;

int main() {
	int mx = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int val;
		scanf("%d", &val);
		arr[val]++;
		if(val > mx) {
			mx = val;
		}
	}
	for(int i = 1;i <= mx;i++) {
		dp[i] = std::max(dp[i-1], dp[i-2] + arr[i] * i);
	}
	printf("%I64d\n", dp[mx]);
	return 0;
}