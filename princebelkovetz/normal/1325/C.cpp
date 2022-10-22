#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mxN = 1e5 + 7;
vector <int> adj[mxN];


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	map <int, pair <int, int>> m;
	map <pair <int, int>, int> ok;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		m[i + 1] = { u, v };
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int used = 0;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() > 2) {
			for (int j = 0; j < adj[i].size(); ++j) {
				ok[{i, adj[i][j]}] = j;
				++used;
			}
			break;
		}
	}
	for (auto &x : m) {
		if (ok.find({ x.second.first, x.second.second }) == ok.end())
			swap(x.second.first, x.second.second);
		if (ok.find({ x.second.first, x.second.second }) == ok.end()) {
			cout << used << endl;
			++used;
		}
		else cout << ok[{x.second.first, x.second.second}] << endl;
	}

}