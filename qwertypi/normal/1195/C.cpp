#include <iostream>

using namespace std;
long long dp[100001][2];
int A[100000], B[100000];
int main(){
	dp[0][0] = dp[0][1] = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + A[i-1]);
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + B[i-1]);
	}
	cout << max(dp[n][0], dp[n][1]);
	return 0;
}