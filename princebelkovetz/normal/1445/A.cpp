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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, x; cin >> n >> x;
		vector <int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		bool c = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] + b[i] > x) c = false;
		}
		cout << (c ? "Yes" : "No");
		cout << '\n';
	}

	return 0;
}