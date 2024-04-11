#include <bits/stdc++.h>
 
using namespace std;
 
int A[4010];
vector<int> B;

bool dp[4010][2001];
void sub(){
	B.clear();
	int n;
	cin >> n;
	for(int i = 0; i <= n * 2; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = false;
		}
	}
	for(int i = 0; i < n * 2; i++){
		cin >> A[i];
	}
	
	int curMax = 0;
	int cnt = 0;
	for(int i = 0; i < n * 2; i++){
		if(A[i] > curMax){
			B.push_back(cnt);
			cnt = 0;
			curMax = A[i];
		}
		cnt++;
	}
	B.push_back(cnt);
	
	dp[0][0] = true;
	for(int i = 0; i < B.size(); i++){
		for(int j = 0; j <= n - B[i]; j++){
			dp[i + 1][j + B[i]] |= dp[i][j];
		}
		
		for(int j = 0; j <= n; j++){
			dp[i + 1][j] |= dp[i][j];
		}
	}
	
	cout << (dp[(int) B.size()][n] ? "YES" : "NO") << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}