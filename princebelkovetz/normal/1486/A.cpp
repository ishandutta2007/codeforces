#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		bool really = true;
		for (int i = 1; i < n; ++i) {
			a[i] += (a[i - 1] - i + 1);
			if (a[i - 1] < i - 1) really = false;
			a[i - 1] = i - 1;
			if (a[i] <= a[i - 1]) really = false;
		}
		cout << (really ? "YES" : "NO") << '\n';
	}
	return 0;
}