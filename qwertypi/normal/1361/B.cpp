#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int n, p;
int A[1000001];
 
 
constexpr int mod = 1e9 + 7;
 
int bp(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}
 
 
inline int pw(int a, int p, int b){
	if(p == 1) return a;
	if(a == 0) return 0; // oh no, I think it is constant factor problem...
	while(b != 0 && abs(a) <= n){
		a *= p;
		b--;
	}
	return a;
}
 
int t;
void solve(){
	cin >> n >> p;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	if(p == 1){
		cout << n % 2 << endl;
		return;
	}
	int d = 0, _p = 1000013;
	int p_inv = bp(p, mod - 2);
	int ans = 0, _pw = bp(p, _p);
	for(int i = n - 1; i >= 0; i--){
		d = pw(d, p, _p - A[i]);
		_pw = (_pw * bp(p_inv, _p - A[i])) % mod;
		_p = A[i];
		if(abs(d - 1) < abs(d + 1)){
			d--;
			ans -= _pw;
		}else{
			d++;
			ans += _pw;
		}
	}
	// ensure ans is positive. Otherwise, it is impossible to determine the positiveness of ans since ans can be negative mod 1e9 + 7 even it is positive.
	cout << (ans % mod + mod) % mod << endl;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
}