#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[101][101];
int A[100];

int _mex[100][100];

int mex(int l, int r){
	set<int> S;
	for(int i = l; i <= r; i++){
		S.insert(A[i]);
	}
	for(int i = 0; i <= 100; i++){
		if(S.find(i) == S.end()){
			_mex[l][r] = i;
			return 0;
		}
	}
	return 0;
}

int sub(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			mex(i, j);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		dp[i][i] = _mex[i][i] + 1;
	}
	for(int d = 0; d < n; d++){
		for(int i = 0; i <= n - 1 - d; i++){
			for(int j = i; j < i + d; j++){
				dp[i][i + d] = max(dp[i][i + d], dp[i][j] + _mex[j + 1][i + d] + 1);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}