#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
bool check(vector <int> a) {
	int n = a.size();
	for (int i = 1; i < n; ++i) {
		int x = min(a[i], a[i - 1]);
		a[i] -= x; a[i - 1] -= x;
		if (a[i - 1]) return false;
	}
	return a.back() == 0;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n), b, c;
		for (auto& x : a) cin >> x;
		b = a, c = a;
		vector <int> pref(n, -1), suf(n, -1);
		pref[0] = a[0];
		suf[n - 1] = a[n - 1];
		for (int i = 1; i < n; ++i) {
			int x = min(b[i], b[i - 1]);
			b[i] -= x, b[i - 1] -= x;
			if (b[i - 1]) break;
			pref[i] = b[i];
		}
		for (int i = n - 2; i >= 0; --i) {
			int x = min(c[i], c[i + 1]);
			c[i] -= x, c[i + 1] -= x;
			if (c[i + 1]) break;
			suf[i] = c[i];
		}
		
		bool able = false;
		if (check(a)) able = true;
		for (int i = 1; i < n - 2; ++i) {
			if (pref[i - 1] != -1 and suf[i + 2] != -1) {
				int l = a[i + 1], r = a[i];
				if (check({ pref[i - 1], l, r, suf[i + 2] })) able = true;
			}
		}
		swap(a[0], a[1]);
		if (check(a)) able = true;
		swap(a[0], a[1]);
		swap(a[n - 2], a[n - 1]);
		if (check(a)) able = true;
		swap(a[n - 2], a[n - 1]);
		cout << (able ? "YES" : "NO") << '\n';
	}
	return 0;
}