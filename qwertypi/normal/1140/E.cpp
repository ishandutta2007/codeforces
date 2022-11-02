#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
int A[200002];


int n, k;
	
int bp(int a, int b){
	if(b == 0) return 1;
	return bp(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod;
}

int mi(int a){
	return bp(a, mod - 2);
}

int dp[200002][3];

int query(int l, int r, int c){
	if(c == 0) return 1;
	if(l == k + 1 && r == k + 1){
		return k * bp(k - 1, c - 1) % mod;
	}else if(l == k + 1 || r == k + 1){
		return bp(k - 1, c);
	}else if(l == r){
		return dp[c + 1][0];
	}else{
		return dp[c + 1][1];
	}
}

int32_t main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n - 2; i++){
		if(A[i] == A[i + 2] && A[i] != -1){
			cout << 0 << endl;
			return 0;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++){
		dp[i + 1][0] = (dp[i][1] + dp[i][2] * (k - 2)) % mod;
		dp[i + 1][1] = (dp[i][0] + dp[i][2] * (k - 2)) % mod;
		dp[i + 1][2] = (dp[i][0] + dp[i][1] + dp[i][2] * (k - 3)) % mod;
	}

	int ans = 1;
	vector<int> a;
	a.push_back(k + 1);
	for(int i = 0; i < n; i += 2){
		a.push_back(A[i]);
	}
	a.push_back(k + 1);
	int _p = a[0], cnt0 = 0;
	for(int i = 1; i < (int) a.size(); i++){
		if(a[i] == -1) cnt0++;
		else{
			ans = (ans * query(_p, a[i], cnt0)) % mod;
			_p = a[i];
			cnt0 = 0;
		}
	}
	a.clear();
	a.push_back(k + 1);
	for(int i = 1; i < n; i += 2){
		a.push_back(A[i]);
	}
	a.push_back(k + 1);
	_p = a[0], cnt0 = 0;
	for(int i = 1; i < (int) a.size(); i++){
		if(a[i] == -1) cnt0++;
		else{
			ans = (ans * query(_p, a[i], cnt0)) % mod;
			_p = a[i];
			cnt0 = 0;
		}
	}
	cout << ans << endl;
}