#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e15 + 7;
int mod = 998244353;
const int max_n = 2e5;
int n, m;
int ans;

int fact[max_n];

int bin_pow(int a, int b) {
	int ans = 1;
	while(b) {
		if (b & 1) ans = ans * a % mod;

		a = a *  a % mod;

		b >>= 1;
	}
	return ans;
}

int rev(int a) {
	return bin_pow(a, mod - 2);
}

void build() {
	fact[0] = 1;
	for(int i = 1;i < max_n;i++) fact[i] = i * fact[i - 1] % mod;
}

int Cnk(int n, int k) {
	if (n < k) return 0ll;
	return fact[n] * rev(fact[k]) % mod * rev(fact[n - k]) % mod;
}




void solve() {
	cin >> n >> m;
	if (n == 2) {
		cout << 0;
		return;
	}

	ans = 0;
	build();

	int num = Cnk(m - 1, n - 2) * bin_pow(2LL, n - 3) % mod;

	for(int i = 1;i <= m;i++) {
		int new_num = Cnk(i - 1, n - 2) * bin_pow(2, n - 3) % mod;
		ans += num - new_num;
	}

	ans %= mod;
	cout << (ans + mod) % mod;
}




signed main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    solve();
}