#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n), b(n), c(n), d(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		for (auto& x : c) cin >> x;
		d[0] = a[0];
		for (int i = 1; i < n - 1; ++i) {
			if (a[i] == d[i - 1]) d[i] = b[i];
			else if (b[i] == d[i - 1]) d[i] = c[i];
			else if (c[i] == d[i - 1]) d[i] = a[i];
			else d[i] = a[i];
		}
		set <int> ok = { d[n - 2], d[0] };
		if (ok.find(a[n - 1]) == ok.end()) d[n - 1] = a[n - 1];
		else if (ok.find(b[n - 1]) == ok.end()) d[n - 1] = b[n - 1];
		else if (ok.find(c[n - 1]) == ok.end()) d[n - 1] = c[n - 1];
		for (auto x : d) cout << x << ' ';
		cout << '\n';
	}
}