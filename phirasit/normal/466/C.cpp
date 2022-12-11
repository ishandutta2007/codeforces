#include <stdio.h>

#define N 500010
#define LL long long

int dp[N], arr[N];
int n;

LL sum = 0;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if(sum%3) {
		printf("0\n");
		return 0;
	}
	sum /= 3;
	LL cnt = 0;
	dp[n] = 0;
	for(int i = n-1;i >= 0;i--) {
		cnt += arr[i];
		dp[i] = (i < n-1 ? dp[i+1] : 0); 
		if(cnt == sum) {
			dp[i]++;
		}
	}
	LL ans = 0;
	cnt = 0;
	for(int i = 0;i < n;i++) {
		cnt += arr[i];
		if(cnt == sum) {
			ans += dp[i+2];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}