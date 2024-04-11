#include <iostream>
#include <algorithm>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
 
int A[300000][2];
ll dp[300001][3];
inline void Solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
	    scanf("%d %d", & A[i][0], & A[i][1]);
		dp[i+1][0] = dp[i+1][1] = dp[i+1][2] = (1LL << 60);
	}
	dp[1][0] = 0;
	dp[1][1] = A[0][1];
	dp[1][2] = A[0][1] << 1;
	for(int i=1;i<n;i++){
		if(A[i-1][0] != A[i][0] + 2){
			dp[i+1][2] = min(dp[i+1][2], dp[i][0] + 2 * A[i][1]);
		}
		if(A[i-1][0] != A[i][0] + 1){
			dp[i+1][1] = min(dp[i+1][1], dp[i][0] + A[i][1]);
			dp[i+1][2] = min(dp[i+1][2], dp[i][1] + 2 * A[i][1]);
		}
		if(A[i-1][0] != A[i][0]){
			dp[i+1][2] = min(dp[i+1][2], dp[i][2] + 2 * A[i][1]);
			dp[i+1][1] = min(dp[i+1][1], dp[i][1] + A[i][1]);
			dp[i+1][0] = min(dp[i+1][0], dp[i][0]);
		}
		if(A[i-1][0] != A[i][0] - 1){
			dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
			dp[i+1][1] = min(dp[i+1][1], dp[i][2] + A[i][1]);
		}
		if(A[i-1][0] != A[i][0] - 2){
			dp[i+1][0] = min(dp[i+1][0], dp[i][2]);
		}
	}
	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		Solve();
	}
}