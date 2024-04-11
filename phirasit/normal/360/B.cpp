#include <stdio.h>
#include <algorithm>

#define LL long long
#define N 2010

using namespace std;

int dp[N];

LL arr[N];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	LL mn = 0, mx = 0;
	for(int i = 0;i < n;i++) {
		scanf("%I64d", &arr[i]);
		if(i == 0) {
			mn = mx = arr[i];
		}
		if(arr[i] > mx) {
			mx = arr[i];
		}
		if(arr[i] < mn) {
			mn = arr[i];
		}
	}
	LL a = 0, b = mx - mn;
	while(a < b) {
		LL mid = (a + b) / 2;
		for(int i = 0;i < n;i++) {
			dp[i] = i;
			for(int j = 0;j < i;j++) {
				if(abs(arr[i] - arr[j]) <= mid * (LL) (i - j)) {
					if(dp[j] + i - j - 1 < dp[i]) {
						dp[i] = dp[j] + i - j - 1;
					}
				}
			}
		}
		int mn = dp[n-1];
		for(int i = 0;i < n;i++) {
			if(dp[i] + n - i - 1 < mn) {
				mn = dp[i] + n - i - 1;
			}
		}
		if(mn <= k) {
			b = mid;
		}else {
			a = mid + 1;
		}
	}
	printf("%I64d\n", a);
	return 0;
}