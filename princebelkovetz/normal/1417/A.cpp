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
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;


signed main() {
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int mn = 1e6, ind = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] < mn)
				mn = a[i], ind = i;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i == ind) continue;
			ans += (k - a[i]) / mn;
		}
		cout << ans << '\n';
	}
	return 0;
}