#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int mod = 1e9 + 7;
int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int dp[5001][5001];
int A[5001], s[5001];
void sub(){
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	s[0] = 0;
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			dp[i + 1][j + 1] = dp[i + 1][j];
			if(j + 1 >= m && dp[i][j + 1 - m] + s[j + 1] - s[j + 1 - m] > dp[i + 1][j + 1]){
				dp[i + 1][j + 1] = dp[i][j + 1 - m] + s[j + 1] - s[j + 1 - m];
			}
		}
	}
	
	cout << dp[k][n] << endl;
}

int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}