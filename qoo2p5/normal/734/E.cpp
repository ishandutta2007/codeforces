#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

const int N = (int) 2e5 + 123;

int n;
int color[N];
vector<int> g[N];

pair<int, int> farest(int v, int from = -1) {
	pair<int, int> res = {0, v};
	
	for (int u : g[v]) {
		if (u == from) {
			continue;
		}
		
		pair<int, int> q = farest(u, v);
		q.first += (color[u] != color[v]);
		res = max(res, q);
	}
	
	return res;
}

void run() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> color[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int u = farest(0).second;
	pair<int, int> q = farest(u);
	int len = q.first;
	cout << ((len + 1) / 2) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	run();
	
	return 0;
}