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
#include <fstream>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;



int n;
map<string, set<string>> m;

bool check(string s, string t) {
	if (t.size() < s.size()) return true;
	int p = 1;
	while (p <= t.size() && p <= s.size() && t[t.size() - p] == s[s.size() - p]) p++;
	if (p > s.size()) return false;
	return true;
}

set<string> comp(set<string> &a) {
	set<string> rtn;
	bool good = true;
	for (auto &i : a) {
		good = true;
		for (auto &j : a) {
			if (i != j)
				good = good && check(i, j);
		}
		if (good) rtn.insert(i);
	}
	return rtn;
}

int main() {
	fast;
	cin >> n;
	int p;
	string s, t;
	for (int i = 0; i < n; i++) {
		cin >> s >> p;
		while (p--) cin >> t, m[s].insert(t);
	}
	for (auto &i : m) i.second = comp(i.second);
	
	cout << m.size() << endl;
	for (auto &i : m) {
		cout << i.first << " " << i.second.size() << " ";
		for (auto &j : i.second) cout << j << " "; cout << endl;
	}
}