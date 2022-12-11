#include <iostream>
#include <algorithm>

#define N 15

using namespace std;

int sum[1 << N];
int arr[1 << N];
int dp[1 << N];
int n;

int main() {
	cin >> n;
	n++;
	for(int i = 2;i < (1 << n);i++) {
		cin >> arr[i];
	}
	for(int i = (1 << n) - 1;i >= 1;i--) {
		if(2 * i >= (1 << n)) {
			dp[i] = 0;
		}else {
			dp[i] = max(dp[2*i] + arr[2*i], dp[2*i+1] + arr[2*i+1]);
		}
	}
	int mx = dp[1];
	int ans = 0;
	sum[1] = 0;
	for(int i = 2;i < (1 << n);i++) {
		sum[i] = sum[i / 2] + arr[i];
		int val = mx - dp[i] - sum[i];
		if(val > 0) {
			ans += val;
			sum[i] +=val;
		}
	}	
	cout << ans << endl; 
	return 0;
}