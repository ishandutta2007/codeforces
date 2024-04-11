#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		set <int> ok = { a.begin(), a.end() };
		if (*ok.begin() < 0) {
			cout << "no\n";
			continue;
		}
		while (a.size() <= 300) {
			bool c = true;
			for (int i = 0; i < a.size() and c; ++i) {
				for (int j = i + 1; j < a.size() and c; ++j) {
					if (ok.find(abs(a[i] - a[j])) == ok.end()) {
						a.push_back(abs(a[i] - a[j]));
						ok.insert(abs(a[i] - a[j]));
						c = false;
					}
				}
			}
			if (c) break;
		}
		cout << "yes\n";
		cout << a.size() << '\n';
		for (auto x : a) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}