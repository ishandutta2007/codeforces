#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 998244353;

int pm(int a, int b){
	if(b == 0) return 1;
	return pm(a * a % p, b / 2) * (b % 2 ? a : 1) % p;
}

int mi(int a){
	return pm(a, p - 2);
}

int fact[1000001];
void solve(){
	fact[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		fact[i] = (fact[i - 1] * i) % p;
	}
	int n; cin >> n; 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += i * fact[n] % p * mi(fact[n - i + 1]) % p * (n - i);
		ans %= p;
	}
	ans = (ans + 1) % p;
	cout << ans << endl;
}
// 3 -> 3
// 4 -> 56
// 3 * (4! / 2!) + 2 * 4! / 3! * 2 + 1 * 4! / 4! * 3 + (1)
int32_t main(){
	int t = 1; 
	// cin >> t;
	while(t--){
		solve();
	}
}