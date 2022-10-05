#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
string s;

set<int> p[2];

vector<vector<int>> ans;

int main() {
	fast;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		p[s[i] - '0'].insert(i + 1);
	set<int>::iterator it[2];
	while (p[0].size() || p[1].size()) {
//		for (const auto &i : p[0]) cout << i << " "; cout << endl;
//		for (const auto &i : p[1]) cout << i << " "; cout << endl;
		if (!p[0].size()) finish(-1);
		if (p[1].size()) {
			if (*p[1].begin() < *p[0].begin()) finish(-1);
		}
		else {
			for (const auto &i : p[0]) ans.push_back(vector<int>(1, i));
			break;
		}
		ans.push_back(vector<int>());
		it[0] = p[0].begin(), it[1] = p[1].begin();
		int x = 0;
		while (it[x] != p[x].end()) {
			ans.back().push_back(*it[x]);
			it[1 ^ x] = p[1 ^ x].upper_bound(*it[x]);
			p[x].erase(it[x]);
			x ^= 1;
		}
		if (s[ans.back()[0] - 1] == '1' || s[ans.back().back() - 1] == '1') finish(-1);
	}
	cout << ans.size() << endl;
	for (const auto &i : ans) {
		cout << i.size() << " ";
		for (const auto &j : i) cout << j << " "; cout << endl;
	}
}