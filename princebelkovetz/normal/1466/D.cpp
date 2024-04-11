#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
vector <int> a;
bool cmp(int c, int b) {
	return a[c] < a[b];
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	int rnd = 0;
	while (testcases-- > 0) {
		int n; cin >> n;
		a.resize(0);
		a.resize(n);
		vector <vector <int>> g(n);
		for (auto& x : a) cin >> x;
		for (int i = 0, u, v; i < n - 1; ++i) {
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (auto& x : g)
			sort(x.begin(), x.end(), cmp);
		int sum = 0;
		for (auto x : a) sum += x;
		multiset <pair <int, int>> cnt;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() > 1)
				cnt.insert({ a[i], i });
		}
		vector <int> cur(n);
		vector <int> ans = { sum };
		for (int i = 0; i < n - 2; ++i) {
			auto it = cnt.end();
			it--;
			sum += it->first;
			cur[it->second]++;
			ans.push_back(sum);
			if (cur[it->second] == g[it->second].size() - 1) {
				cnt.erase(it);
			}
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}