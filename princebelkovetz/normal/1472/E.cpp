#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <cassert>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <vector <int>> a(n, vector <int>(3));
		int f = 0;
		for (auto& x : a) {
			cin >> x[0] >> x[1];
			if (x[0] > x[1]) swap(x[0], x[1]);
			x[2] = f++;
		}
		sort(a.begin(), a.end());
		int last = -1;
		set <pair <int, int>> ok;
		vector <int> ans(n), buf;
		for (int i = 0; i < n; ++i) {
			if (last == i){
				for (auto x : buf)
					ok.insert({ a[x][1], a[x][2] });
				buf.resize(0);
			}
			buf.push_back(i);
			if (i != n - 1 and a[i][0] != a[i + 1][0]) {
				last = i + 1;
			}
			if (ok.empty() or ok.begin()->first >= a[i][1])
				ans[a[i][2]] = -1;
			else
				ans[a[i][2]] = ok.begin()->second + 1;
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}