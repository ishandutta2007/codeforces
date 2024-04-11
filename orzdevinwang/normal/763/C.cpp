#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
#define int long long 
using namespace std;
const int N = 5e5 + 7;
int mod, pr;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, a[N], sum, all;
int arr[N];
signed main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> mod >> n;
	L(i, 1, n - 1) 
		(pr += (ll) i * i % mod) %= mod;
	L(i, 1, n) 
		cin >> a[i], (sum += a[i]) %= mod, (all += (ll) a[i] * a[i] % mod) %= mod; 
	sort(a + 1, a + n + 1);
	if(n == 1) {
		cout << a[1] << ' ' << 0 << endl;
		return 0;
	}
	if(n == 2) {
		cout << a[1] << ' ' << (a[2] + mod - a[1]) % mod << endl;
		return 0;
	}
	if (n == mod) {
		cout << 0 << ' ' << 1 << '\n';
		return 0;
	}
	L(i, 1, n) {
		int ret = 0;
		int d = (ll) (sum + mod - (ll) n * a[i] % mod) * 2 % mod * qpow (n) % mod * qpow (n - 1) % mod; // sha bi corner case!
		ret = ((ll) n * a[i] % mod * a[i] % mod + (ll) a[i] * d % mod * n % mod * (n - 1) % mod + (ll) pr * d % mod * d % mod) % mod;
		if(ret == all) {
			L(o, 1, n) arr[o] = (a[i] + (ll) d * (o - 1) % mod) % mod;
			sort(arr + 1, arr + n + 1);
			bool ok = true;
			L(o, 1, n) if(arr[o] != a[o]) ok = false;
			if(ok) {
				cout << a[i] << ' ' << d << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}