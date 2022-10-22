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
		int n; cin >> n;
		vector <int> a(n), last(n + 1, -1), diff(n + 1, -1);
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			diff[a[i]] = max(diff[a[i]], i - last[a[i]]);
			last[a[i]] = i;
		}
		for (int i = 0; i <= n; ++i)
			diff[i] = max(diff[i], n - last[i]);
		//for (auto x : diff) cout << x << ' ';
		int cur = n + 1;
		vector <int> ans(n, -1);
		for (int i = 1; i <= n; ++i) {
			if (diff[i] < cur) {
				for (int j = diff[i] - 1; j < cur - 1; ++j) {
					ans[j] = i;
				}
				cur = diff[i];
			}
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}