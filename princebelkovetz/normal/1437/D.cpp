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
const int mod = 1e9 + 7;
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
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a)
			cin >> x;
		vector <int> bb = { 1 };
		for (int i = 2; i < n; ++i) {
			if (a[i] > a[i - 1]) bb.back()++;
			else bb.push_back(1);
		}
		int cur = bb[0], next = 0;
		int ans = 1;
		for (int i = 1; i < bb.size(); ++i) {
			cur--; next += bb[i];
			if (!cur) {
				cur = next;
				next = 0;
				ans++;
			}
		}
		if (next) ans++;
		cout << ans << '\n';
	}
	return 0;
}