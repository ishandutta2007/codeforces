#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-13;
string rev(string s) {
	string t = "";
	for (auto x : s) {
		if (x == '0') t += '1';
		else t += '0';
	}
	return t;
}
signed main() {
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; string a, b;
		cin >> n >> a >> b;
		vector <int> ans;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] == b[i]) continue;
			if (a[0] != a[i]) {
				ans.push_back(1);
				if (a[0] == '0') a[0] = '1';
				else a[0] = '0';
			}
			string t = a.substr(0, i + 1);
			reverse(t.begin(), t.end());
			t = rev(t);
			a = t + a.substr(i + 1, n - i - 1);
			ans.push_back(i + 1);
		}
		cout << ans.size() << ' ';
		for (auto x : ans) cout << x << ' ';
		cout << endl;
	}
	return 0;
}