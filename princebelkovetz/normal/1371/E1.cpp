#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, p, m = 0; cin >> n >> p;
	set <int> ans;
	vector <int> a(n);
	for (auto& x : a) {
		cin >> x;
		m = max(m, x);
	}
	for (int i = max(0ll, m - n + 1); i < m; ++i) {
		int cur = 1, ind = i;
		vector <int> ok(m + n + 2);
		for (int j = 0; j < n; ++j) ok[a[j]]++;
		for (int j = 1; j <= m + n + 1; ++j) ok[j] += ok[j - 1];
		//for (auto x : ok) cout << x << " ";
		//cout << endl;
		for (int j = 0; j < n; ++j) {
			//debug(ind);
			cur *= (ok[ind] - j);
			cur %= p;
			++ind;
		}
		//debug(cur);
		if (cur != 0) {
			ans.insert(i);
		}
	}
	cout << ans.size() << endl;
	for (auto i = ans.begin(); i != ans.end(); ++i) cout << *i << " ";
	
	return 0;
}