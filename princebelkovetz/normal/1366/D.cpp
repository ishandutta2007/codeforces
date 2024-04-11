#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
int prime[10000005];
void solve() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i <= 1e7 + 5; ++i) {
		if (prime[i]) continue;
		prime[i] = 1;
		for (int j = i * i; j <= 1e7 + 5; j += i) {
			if (prime[j]) continue;
			prime[j] = i;
		}
	}
	int n; cin >> n;
	vector <int> a(n); vector <pair <int, int>> ans(n);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		while (!(cur % prime[a[i]]) and prime[a[i]] != 1) cur /= prime[a[i]];
		if (cur == 1 or prime[a[i]] == 1) ans[i] = { -1, -1 };
		else ans[i] = { cur, prime[a[i]] };
	}
	for (int i = 0; i < n; ++i) cout << ans[i].first << " "; cout << endl;
	for (int i = 0; i < n; ++i) cout << ans[i].second << " ";




}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;
	while (t--) {
		solve();
	}
	return 0;
}