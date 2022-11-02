#include <bits/stdc++.h>
#define mod 998244353
typedef long long ll;
#define int long long
using namespace std;

int h[200000];
int dp[2001][4001];
ll powmod(ll a, int b){
	ll res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= mod;
		}
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	int same = 0;
	for(int i = 0; i < n; i++){
		if(h[i] == h[(i + 1) % n]){
			same++;
		}
	}
	ll ans = powmod(k, same);
	int diff = n - same;
	dp[0][2000] = 1;
	for(int i = 0; i < diff; i++){
		dp[i + 1][0] = dp[i][0] * (k - 2) + dp[i][1];
		for(int j = 1; j < 4000; j++){
			dp[i + 1][j] = dp[i][j - 1] + dp[i][j] * (k - 2) + dp[i][j + 1];
		}
		dp[i + 1][4000] = dp[i][4000] * (k - 2) + dp[i][3999];
		for(int j = 0; j <= 4000; j++){
			dp[i + 1][j] %= mod;
		}
	}
	ll ans2 = 0;
	for(int i = 2001; i <= 4000; i++){
		ans2 += dp[diff][i];
		ans2 %= mod;
	}
	cout << (ans * ans2) % mod << endl;
}