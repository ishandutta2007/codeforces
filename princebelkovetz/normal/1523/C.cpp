#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> st = { };
		vector <vector <int>> ans, st2;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			if (!i) {
				ans.push_back({ 1 });
				st.push_back(1);
				st2.push_back({ 1 });
				continue;
			}
			if (x == 1) {
				ans.push_back(ans.back());
				ans.back().push_back(1);
				st.push_back(1);
				st2.push_back(ans.back());
			}
			else {
				while (st.back() != x - 1) {
					st.pop_back();
					st2.pop_back();
				}
				st.pop_back();
				vector <int> add = st2.back();
				add.pop_back();
				add.push_back(x);
				st2.pop_back();
				st.push_back(x);
				st2.push_back(add);
				ans.push_back(add);
			}
		}
		for (auto& x : ans) {
			cout << x[0];
			for (int i = 1; i < x.size(); ++i) {
				cout << "." << x[i];
			}
			cout << '\n';
		}
	}
}