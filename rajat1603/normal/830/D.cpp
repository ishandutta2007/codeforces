#include "bits/stdc++.h"
using namespace std;
const int N = 405;
const int mod = 1e9 + 7;
int n;
int dp[2][N];
void calc(){
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i = 2 ; i <= n ; ++i){
		bool row = !(i & 1);
		dp[!row][0] = 1;
		for(int j = 1 ; j <= n ; ++j){
		    int res = 0;
			for(int k = 0 ; k <= j ; ++k){
				res = (res + 1LL * dp[row][k] * dp[row][j - k]) % mod;
			}
			for(int k = 1 ; k <= j ; ++k){
				res = (res + ((2LL * dp[row][k + 1] * k * (k + 1LL)) % mod) * dp[row][j - k] + 1LL * dp[row][k - 1] * dp[row][j - k] + ((2LL * dp[row][k] * k) % mod) * ((2LL * dp[row][j - k] + 1LL * dp[row][j + 1 - k] * (j + 1LL - k)) % mod)) % mod;
			}
			dp[!row][j] = res;
		}
	}
}
int main(){
	cin >> n;
	calc();
	cout << dp[n & 1][1] << endl;
}