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
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;
vector<string> s, ans;
unordered_map<int, int> m[9];

void work(string &t) {
	ll val = 0;
	unordered_set<int> ill;
	for (int i = 0; i < t.size(); i++) {
		val = 0;
		for (int j = i; j < t.size(); j++) {
			val = (val * hs + t[j]) % md;
			if (ill.find(val) == ill.end()) ill.insert(val), m[j - i][val]++;
		}
	}
}

string check(string &t) {
	ll val[9] = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j + i < t.size(); j++) {
			val[j] = (val[j] * hs + t[j + i]) % md;
			if (m[i][val[j]] == 1) return t.substr(j, i + 1);
		}
	}
	return "";
}

int main() {
	fast;
	cin >> n;
	s.resize(n), ans.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i], work(s[i]);
	for (int i = 0; i < n; i++)
		ans[i] = check(s[i]);
	for (auto &i : ans)
		cout << i << endl;
}