#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
int fact[600001];
const int mod = 1e9 + 7;

int pm(int a, int b, int p){
	if(b == 0) return 1;
	return pm(a * a % p, b / 2, p) * (b % 2 ? a : 1) % p;
}

int mi(int a, int p){
	return pm(a, p - 2, p);
}

int C(int n, int r){
	if(n < r) return 0;
	return fact[n] * mi(fact[n - r], mod) % mod * mi(fact[r], mod) % mod;
}

void solve(){
	int n;
	cin >> n;
	fact[0] = 1;
	for(int i = 1; i <= 600000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	for(int i = 0; i < n + 1; i++){
		cin >> A[i];
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans += C(A[i] + i, i + 1);
		ans %= mod;
	}
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}