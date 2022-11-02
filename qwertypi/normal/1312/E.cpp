#include <bits/stdc++.h>

using namespace std;
int A[500];
int dp[500][500]; // best formable [i : j]
int dp2[500];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		dp[i][i] = A[i];
	}
	for(int d = 1; d < n; d++){
		for(int x = 0; x < n - d; x++){
			int y = x + d;
			for(int z = x; z < y; z++){
				if(dp[x][z] != 0 && dp[x][z] == dp[z + 1][y]){
					dp[x][y] = dp[x][z] + 1;
					break;
				}
			}
		}
	}
	dp2[0] = 1;
	for(int i = 1; i < n; i++){
	    dp2[i] = (1 << 30);
	}
	for(int i = 1; i < n; i++){
	    if(dp[0][i]){
	        dp2[i] = 1;
	    }
	    for(int j = 0; j < i; j++){
	        if(dp[j + 1][i]){
	            dp2[i] = min(dp2[i], dp2[j] + 1);
	        }
	    }
	}
	
	cout << dp2[n - 1];
}