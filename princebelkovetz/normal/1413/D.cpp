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
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <pair <int, int>> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		string s; cin >> s;
		if (s == "+")
			a[i].first = 1;
		else {
			int x; cin >> x;
			a[i].first = 0;
			a[i].second = x;
		}
	}
	bool c = true;
	stack <int> ok;
	vector <int> ans;
	for (int i = 2 * n - 1; i >= 0; --i) {
		if (a[i].first and ok.empty()) {
			c = false;
			break;
		}
		if (a[i].first) {
			ans.push_back(ok.top());
			ok.pop();
		}
		else {
			ok.push(a[i].second);
		}
	}
	reverse(ans.begin(), ans.end());
	if (!c) {
		cout << "NO\n";
		return 0;
	}
	set <int> mn;
	int cur = 0;
	for (auto x : a) {
		if (x.first) {
			mn.insert(ans[cur++]);
		}
		else {
			auto it = mn.begin();
			if (*it != x.second) {
				cout << "NO\n";
				return 0;
			}
			mn.erase(it);
		}
	}
	cout << "YES\n";
	for (auto x : ans) cout << x << ' ';
	cout << '\n';
	return 0;
}