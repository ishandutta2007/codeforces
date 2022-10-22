#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	map <char, int> zip;
	map <int, char> unzip;
	int cur = 0;
	for (auto i = '0'; i <= '9'; ++i)
		unzip[cur] = i, zip[i] = cur++;
	for (auto i = 'A'; i <= 'Z'; ++i) {
		unzip[cur] = i, zip[i] = cur++;
	}
	for (auto i = 'a'; i <= 'z'; ++i)
		unzip[cur] = i, zip[i] = cur++;
	int all = cur * cur;
	vector <vector <int>> g(all), rev(all);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int fst = zip[s[0]] * cur + zip[s[1]];
		int snd = zip[s[1]] * cur + zip[s[2]];
		g[fst].push_back(snd);
		rev[snd].push_back(fst);
	}
	int st = -1, end = -1;
	for (int i = 0; i < all; ++i) {
		int sz1 = g[i].size(), sz2 = rev[i].size();
		if (sz1 != sz2) {
			if (abs(sz1 - sz2) > 1) {
				cout << "NO\n";
				return 0;
			}
			if (sz1 - sz2 == 1) {
				if (st == -1) st = i;
				else {
					cout << "NO\n";
					return 0;
				}
			}
			if (sz1 - sz2 == -1) {
				if (end == -1) end = i;
				else {
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	if (st == -1) {
		for (int i = 0; i < cur * cur; ++i)
			if (g[i].size()) {
				st = i; break;
			}
		assert(st != -1);
	}
	vector <bool> used(n);
	vector <int> e(cur * cur), ans;
	vector <int> stack = { st };
	while (!stack.empty()) {
		int v = stack.back();
		if (e[v] == g[v].size()) {
			ans.push_back(v);
			stack.pop_back();
		}
		else {
			stack.push_back(g[v][e[v]]);
			e[v]++;
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() != n + 1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << unzip[ans[i] / cur];
		if (i == ans.size() - 1) cout << unzip[ans[i] % cur];
	}
	cout << '\n';
	return 0;
}