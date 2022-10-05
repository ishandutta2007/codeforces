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

vector<int> find(const vector<int> &p, const vector<bool> &ok) {
	static vector<int> rtn;
	static vector<pair<char, int>> c;
	c.clear(), rtn.clear();

	for (int i = 0; i < p.size(); i++) c.push_back({ s[p[i]], i });
	if (c.empty()) return{};
	sort(c.begin(), c.end());
	if (c.size() == 1) return{ c[0].second };
	if (c[0].first != c[1].first) rtn.push_back(c[0].second);
	if (c[c.size() - 2].first != c[c.size() - 1].first) rtn.push_back(c.back().second);
	for (int i = 1; i + 1 < c.size(); i++)
		if (c[i].first != c[i - 1].first && c[i].first != c[i + 1].first) rtn.push_back(c[i].second);
	return rtn;
}

int check(char c) {
	vector<int> p;
	for (int i = 0; i < n; i++) if (s[i] == c) p.push_back(i);
	if (p.empty()) return 0;
	if (p.size() == 1) return 1;
	vector<bool> ok(p.size(), true);
	vector<int> rmv;
	vector<int> found(p.size(), 0);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p.size(); j++) p[j] = (p[j] - 1 + n) % n;
		rmv = find(p, ok);
		mx = max(mx, (int)rmv.size());
	}
	return mx;
}

int main() {
	fast;
	cin >> s;
	n = s.size();
	int tot = 0;
	for (char c = 'a'; c <= 'z'; c++) tot += check(c);
	cout.precision(10);
	cout << (double)tot / n << endl;
}