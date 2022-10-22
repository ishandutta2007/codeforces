#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

using namespace std;
int mul(int a, int b, int m) {
	return (a * b) % m;
}
int fastpow(int a, int b, int m) {
	if (!b) return 1ll;
	if (b % 2 == 1) return mul(fastpow(a, b - 1, m), a, m);
	int t = fastpow(a, b / 2, m);
	return mul(t, t, m);
}
const int m = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int x, n, ans = 1; cin >> x >> n;
	vector <int> prime;
	int ok = x;
	for (int i = 2; i * i <= ok; ++i) {
		if (x % i == 0) prime.push_back(i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) prime.push_back(x);
	//for (auto x: prime)cout << x << " ";
	//cout << endl;
	for (int i = 0; i < prime.size(); ++i) {
		int cur = 1;
		while (cur <= n / prime[i]) {
			cur *= prime[i];
			ans = mul(ans, fastpow(prime[i], n / cur, m), m);
		}
	}
	cout << ans << endl;
	return 0;
}