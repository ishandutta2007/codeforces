#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 1e9 + 7;
int fact[200001];
int powmod(int a, int b){
	if(b == 0) return 1;
	if(b % 2 == 1) return powmod(a * a % p, b / 2) * a % p;
	return powmod(a * a % p, b / 2);
}

int modinv(int a){
	return powmod(a, p - 2);
}

int C(int n, int r){
	return fact[n] * modinv(fact[n - r]) % p * modinv(fact[r]) % p;
}

void solve(){
	int n, k;
	cin >> n >> k;
	if(k == 0){
		cout << 1 << endl;
		return ;
	}
	int f_w = (n % 2 == 0), f_r = powmod(2, n), f_d = (n % 2 == 1);
	for(int i = 0; i < n; i += 2){
		f_d = (f_d + C(n, i)) % p;
	}
	// cout << f_w << ' ' << f_r << ' ' << f_d << endl;
	int a = f_w * powmod(f_r, k - 1) % p;
	int f = f_d * modinv(f_r) % p;
	int b = (1 - powmod(f, k)) * modinv(1 - f) % p;
	int c = powmod(f_d, k) % p;
	// cout << f << ' ' << a << ' ' << b << ' ' << c << endl;
	int ans = a * b % p + c % p;
	ans = (ans % p + p) % p;
	cout << ans << endl;
}

int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = (fact[i - 1] * i) % p;
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}