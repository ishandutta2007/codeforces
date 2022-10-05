#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
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

int n, m, a, b, c;
pair<ll, ll> best = { 0, 1 };
vector<vector<pair<int, int>>> g;
vector<int> w;

int main() {
	fast;
	cout.precision(10);
	cin >> n >> m;
	if (m == 0) return cout << 0 << endl, 0;
	g.resize(n), w.resize(n);
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		--a, --b;
		g[a].push_back({ b, c }), g[b].push_back({ a, c });
	}
	for (int i = 0; i < n; i++) {
		for (auto &j : g[i]) {
			if (best.first * j.second < best.second * (w[j.first] + w[i]))
				best = { w[j.first] + w[i], j.second };
		}
	}
	cout << (ldb)best.first / best.second << endl;
}