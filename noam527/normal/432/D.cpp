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
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
int n;
vector<int> prefix, val;
vector<vector<int>> g;

// just builds the prefix function
void kmp() {
	int q = prefix[0] = 0;
	for (int i = 1; i < n; i++) {
		while (q && s[q] != s[i]) q = prefix[q - 1];
		if (s[q] == s[i]) q++;
		prefix[i] = q;
	}
}
int dfs(int v, int prev = -1) {
	val[v] = 1;
	for (auto &i : g[v])
		if (i != prev)
			val[v] += dfs(i, v);
	return val[v];
}

int main() {
	cin >> s;
	n = s.size();
	prefix.resize(n), g.resize(n), val.resize(n, -1);
	kmp();
	
	for (int i = 0; i < n; i++)
		if (prefix[i]) {
			g[i].push_back(prefix[i] - 1);
			g[prefix[i] - 1].push_back(i);
		}
	for (int i = 0; i < n; i++)
		if (val[i] == -1) dfs(i);

	int q = prefix[n - 1];
	vector<pair<int, int>> ans;
	while (q) {
		ans.push_back({ q, val[q - 1] });
		q = prefix[q - 1];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() + 1 << endl;
	for (auto &i : ans) cout << i.first << " " << i.second << endl;
	cout << n << " 1\n";
}