#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 17;
int fact[N], mfact[N];
int bpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return a * (bpow(a, b - 1)) % mod;
	int t = bpow(a, b / 2);
	return t * t % mod;
}
int getc(int n, int k) {
	int res = 1;
	res = res * fact[n] % mod;
	res = res * mfact[k] % mod;
	res = res * mfact[n - k] % mod;
	return res;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = fact[i - 1] * i % mod;
	mfact[N - 1] = bpow(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) 
		mfact[i] = mfact[i + 1] * (i + 1) % mod;
	int n; cin >> n;
	vector <int> a(2 * n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	int cc = getc(2 * n, n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
		sum1 += a[i];
	for (int i = n; i < 2 * n; ++i)
		sum2 += a[i];
	int ans = sum2 - sum1 + mod;
	ans %= mod;
	ans = ans * cc % mod;
	cout << ans << '\n';

	return 0;
}