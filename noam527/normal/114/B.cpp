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
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string t1, t2;
int n, m, mx;
vector<int> hashed, ans;
vector<string> a;
unordered_map<int, unordered_set<int>> s;

int pleasehash(string &tohash) {
	ll val = 0;
	for (int i = 0; i < tohash.size(); i++)
		val = (val * hs + tohash[i]) % md;
	return val;
}

void dfs(int at, vector<int> &took) {
	if (at == n) {
		for (int i = 0; i < took.size(); i++)
			for (int j = i + 1; j < took.size(); j++)
				if (s[took[i]].find(took[j]) != s[took[i]].end()) return;
		if (took.size() > mx) {
			mx = took.size();
			ans = took;
		}
		return;
	}
	dfs(at + 1, took);
	took.push_back(hashed[at]);
	dfs(at + 1, took);
	took.pop_back();
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		hashed.push_back(pleasehash(a[i]));
	}
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		s[pleasehash(t1)].insert(pleasehash(t2));
		s[pleasehash(t2)].insert(pleasehash(t1));
	}
	vector<int> stupidvector;
	dfs(0, stupidvector);
	cout << mx << endl;
	vector<string> finalans;
	for (int i = 0, p = 0; i < n && p < mx; i++) {
		if (hashed[i] == ans[p]) finalans.push_back(a[i]), p++;
	}
	sort(finalans.begin(), finalans.end());
	for (auto &i : finalans) cout << i << endl;
}