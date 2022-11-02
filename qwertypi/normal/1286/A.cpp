#include <bits/stdc++.h>
#define inf (1 << 30)
using namespace std;

int A[101];
int dp[101][2][101][101];
int cnt[2];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i++){
		cnt[i % 2]++;
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= n; k++){
				dp[i][0][j][k] = dp[i][1][j][k] = inf;
			}
		}
	}
	
	dp[0][0][cnt[0]][cnt[1]] = dp[0][1][cnt[0]][cnt[1]] = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == 0 || A[i] % 2 == 0){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					dp[i + 1][0][j][k] = min(dp[i + 1][0][j][k], dp[i][0][j + 1][k]);
					dp[i + 1][0][j][k] = min(dp[i + 1][0][j][k], dp[i][1][j + 1][k] + 1);
				}
			}
		}
		
		if(A[i] == 0 || A[i] % 2 == 1){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					dp[i + 1][1][j][k] = min(dp[i + 1][1][j][k], dp[i][0][j][k + 1] + 1);
					dp[i + 1][1][j][k] = min(dp[i + 1][1][j][k], dp[i][1][j][k + 1]);
				}
			}
		}
	}
	
	cout << min(dp[n][0][0][0], dp[n][1][0][0]) << endl;
}