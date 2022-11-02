#include <bits/stdc++.h>
#define int long long

using namespace std;
int A[5001];

int dp[5001][5001];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector<int> in, out;
	for(int i = 0; i < n; i++){
		if(A[i]) in.push_back(i);
		if(!A[i]) out.push_back(i);
	}
	
	for(int i = 0; i <= in.size(); i++){
		for(int j = 0; j <= out.size(); j++){
			dp[i][j] = (1LL << 60);
		}
	}
	for(int j = 0; j <= out.size(); j++){
		dp[0][j] = 0;
	}
	for(int i = 0; i < in.size(); i++){
		for(int j = 0; j < out.size(); j++){
			dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j] + abs(in[i] - out[j]));
		}
	}
	cout << dp[in.size()][out.size()];
}