#include <bits/stdc++.h>
#define int long long

using namespace std;

char A[5000];
int mod = 1e9 + 7;
int dp[5001][5001]; // n k
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int _p = ' ', c = 0;
	vector<int> a;
	for(int i = 0; i < n; i++){
		if(A[i] == 'f'){
			c++;
		}else{
			a.push_back(c);
			c = 0;
		}
		_p = A[i];
	}
	if(_p == 'f'){
		cout << 0 << endl;
		return;
	}
	dp[0][0] = 1;
	for(int i = 0; i < a.size(); i++){
		int s = 0;
		for(int j = n - a[i]; j >= 0; j--){
			s += dp[i][j];
			s %= mod;
			dp[i + 1][j + a[i]] += s;
			dp[i + 1][j + a[i]] %= mod;
		}
	}
	int ans = 0;
	for(int j = 0; j <= n; j++){
		ans += dp[a.size()][j];
	} // what am I doing
	ans %= mod;
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}