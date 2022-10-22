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
		int n, t; cin >> n >> t;
		vector <int> a(n), ans(n);
		for (auto& x : a) cin >> x;
		map <int, vector <int>> mp;
		for (int i = 0; i < n; ++i) {
			mp[a[i]].push_back(i);
		}
		for (auto x : mp) {
			if (x.first > t / 2) break;
			if (mp.find(t - x.first) == mp.end())
				continue;
			int num = x.first;
			if (num == t - num) {
				for (int i = 0; i < x.second.size() / 2; ++i)
					ans[x.second[i]] = 1;
			}
			else {
				for (auto y : mp[t - x.first])
					ans[y] = 1;
			}
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}