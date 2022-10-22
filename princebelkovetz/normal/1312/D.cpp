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
int bpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return (a * bpow(a, b - 1)) % mod;
	int t = bpow(a, b / 2);
	return (t * t) % mod;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n, m; cin >> n >> m;
	if (n <= 2) {
		cout << "0\n";
		return 0;
	}
	vector <int> fact(m + 1);
	fact[0] = 1;
	for (int i = 1; i <= m; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int ans = fact[m];
	ans = (ans * bpow(fact[n - 1], mod - 2)) % mod;
	ans = (ans * bpow(fact[m - n + 1], mod - 2)) % mod;
	ans = (ans * bpow(2, n - 3)) % mod;
	cout << (ans * (n - 2)) % mod << '\n';

	return 0;
}