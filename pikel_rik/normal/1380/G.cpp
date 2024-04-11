#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

long long modexp(long long x, long long n, long long m = mod) {
    x %= m;
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % m;
        x = x * x % m;
        n /= 2;
    }
    return ans;
}

long long modinv(long long x, long long m = mod) {
    return modexp(x, m - 2);
}

int n, c[N];
ll pref[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = c[i] + pref[i - 1];
	}

	int n_inv = modinv(n);
	for (int k = 1; k <= n; k++) {
		int partition_size = (n - k) / k, inc = (n - k) % k;
		ll ans = pref[inc] * (partition_size + 1) % mod;
		for (int i = inc + k, j = partition_size; j > 0; i += k, j--) {
			ans = (ans + (pref[i] - pref[i - k]) * j) % mod;
		}
		cout << ans * n_inv % mod << ' ';
	}
	cout << '\n';
	return 0;
}