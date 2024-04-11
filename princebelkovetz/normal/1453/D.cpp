#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases;
	cin >> testcases;
	while (testcases --> 0) {
		int n; cin >> n;
		if (n & 1) {
			cout << "-1\n";
			continue;
		}
		vector <int> ans;
		while (n) {
			int cur = 4;
			ans.push_back(1);
			n -= 2;
			while (cur <= n) {
				ans.push_back(0);
				n -= cur;
				cur *= 2;
			}
		}
		if (ans.size() <= 2000) {
			cout << ans.size() << '\n';
			for (auto x : ans) cout << x << ' ';
			cout << '\n';
		}
		else cout << "-1\n";
	}
}