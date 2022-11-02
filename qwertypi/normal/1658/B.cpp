#include <bits/stdc++.h>
#define int long long
// Pls don't give me expert
// Back to the origin in 2019...
 
using namespace std;
 
int mod = 998244353;
int fact[100001];
void solve(){
	int n;
	cin >> n;
	if(n % 2){
		cout << 0 << endl;
	}else{
		cout << (long long) (fact[n / 2] * fact[n / 2]) % mod << endl;
	}
}
 
int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 100000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}