#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
vector <vector <pair <int, int>>> g;
vector <vector <int>> ans;
vector <int> buf, h;
vector <bool> used;
void dfs(int v) {
	used[v] = true;
	for (auto x : g[v]) {
		int u = x.first, i = x.second;
		if (!used[u]) {
			h[u] = h[v] + 1;
			dfs(u);
			if (buf[u] != -1) {
				ans.push_back({ buf[u], i });
				buf[u] = -1;
			}
			else if (buf[v] != -1) {
				ans.push_back({ buf[v], i });
				buf[v] = -1;
			}
			else {
				buf[v] = i;
			}
		}
		else if (used[u] and h[u] > h[v]) {
			if (buf[v] != -1) {
				ans.push_back({ buf[v], i });
				buf[v] = -1;
			}
			else {
				buf[v] = i;
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int id = 1;
	map <pair <int, int>, int> ind;
	vector <vector <int>> edges;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x1 = (a + b) * d, y1 = c * b;
		int g1 = gcd(x1, y1);
		x1 /= g1, y1 /= g1;
		if (ind.find({ x1, y1 }) == ind.end()) {
			ind[{x1, y1}] = id++;
		}
		int x2 = a * d, y2 = (d + c) * b;
		int g2 = gcd(x2, y2);
		x2 /= g2, y2 /= g2;
		if (ind.find({ x2, y2 }) == ind.end()) {
			ind[{x2, y2}] = id++;
		}
		edges.push_back({ ind[{x1, y1}], ind[{x2, y2}], i });
	}
	g.resize(id);
	h.resize(id);
	buf.resize(id, -1);
	used.resize(id);
	for (auto& x : edges) {
		g[x[0]].push_back({ x[1], x[2] });
		g[x[1]].push_back({ x[0], x[2] });
	}
	for (int i = 1; i < id; ++i) {
		if (!used[i])
			dfs(i);
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x[0] + 1 << ' ' << x[1] + 1 << '\n';
	}
}