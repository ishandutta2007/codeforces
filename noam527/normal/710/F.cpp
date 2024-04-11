#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, t, p[300003];
string temp;
map<int, set<int>> m;

int h(string &s) {
	ll val = 0;
	for (auto &i : s) val = (val * hs + i) % md;
	return val;
}

void add(string &s) {
	m[s.size()].insert(h(s));
}

void remove(string &s) {
	m[s.size()].erase(h(s));
	if (m[s.size()].size() == 0) m.erase(s.size());
}

int query(string &s) {
	int rtn = 0;
	for (auto i = m.begin(); i != m.end() && i->first <= s.size(); i++) {
		int val = 0;
		for (int j = 0; j < i->first; j++)
			val = (val * hs + s[j]) % md;
		if (i->second.find(val) != i->second.end()) rtn++;
		for (int j = i->first; j < s.size(); j++) {
			val = (((val * hs + s[j]) - (ll)p[i->first] * s[j - i->first]) % md + md);
			if (val > md) val -= md;
			if (i->second.find(val) != i->second.end()) rtn++;
		}
	}
	return rtn;
}

int main() {
	fast;
	p[0] = 1;
	for (int i = 1; i < 300003; i++) p[i] = (p[i - 1] * hs) % md;

	cin >> n;
	while (n--) {
		cin >> t >> temp;
		if (t == 1) add(temp);
		if (t == 2) remove(temp);
		if (t == 3) {
			cout << query(temp) << endl, flush;
		}
	}
}