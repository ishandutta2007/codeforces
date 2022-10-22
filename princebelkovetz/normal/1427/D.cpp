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
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;
void swp(vector <int>& a, vector <int> b) {
	reverse(b.begin(), b.end());
	vector <int> got;
	int n = a.size();
	for (auto x : b) {
		for (int i = n - x; i < n; ++i) {
			got.push_back(a[i]);
		}
		for (int i = 0; i < x; ++i)
			a.pop_back();
		n -= x;
	}
	a = got;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <int> ind(n + 1);
	for (int i = 0; i < n; ++i) {
		ind[a[i]] = i;
	}
	vector <vector <int>> ans;
	for (int i = 1; i <= n - 1; i += 2) {
		vector <int> b = { i - 1, ind[i] + 2 - i, n - ind[i] - 1 };
		ans.push_back(b);
		swp(a, b);
		for (int j = 0; j < n; ++j)
			ind[a[j]] = j;
		b = { ind[i + 1], ind[i] - ind[i + 1], 1, i - 1 };
		ans.push_back(b);
		swp(a, b);
		for (int j = 0; j < n; ++j)
			ind[a[j]] = j;
	}
	vector <vector <int>> nwans;
	for (auto x : ans) {
		int cnt = 0;
		for (auto y : x) cnt += bool(y);
		if (cnt > 1) {
			nwans.push_back({ cnt });
			for (auto y : x) 
				if(y)
					nwans.back().push_back(y);
		}
	}
	cout << nwans.size() << '\n';
	for (auto x : nwans) {
		for (auto y : x) cout << y << ' ';
		cout << '\n';
	}
	return 0;
}