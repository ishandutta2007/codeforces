#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k;
vector<int> v[101010];
set<int> q[101010];

int z[101010];
vector<int> p;
int c[101010];

vector<int> fix(vector<int> w) {
	vector<int> g;
	int r = w.size();
	for (auto x : w) {
		g.push_back(x);
		while (r > 3) {
			int s = g.size();
			if (s <= 2) break;
			if (q[g[s-1]].count(g[s-3])) {
				int b = g.back();
				g.pop_back();
				g.pop_back();
				g.push_back(b);
				r--;
			} else break;
		}
	}
	return g;
}

void dfs(int s, int e) {
	c[s] = 3-c[e];
	if (z[s] == 2) return;
	if (z[s] == 1) {
		vector<int> w;
		while (true) {
			w.push_back(p.back());
			p.pop_back();
			if (w.back() == s) break;
		}
		w = fix(w);
		if (w.size() <= k) {
			cout << "2\n";
			cout << w.size() << "\n";
			for (auto x : w) cout << x << " ";
			cout << "\n";
		} else {
			cout << "1\n";
			for (int i = 0; i < (k+1)/2; i++) {
				cout << w[2*i] << " ";
			}
			cout << "\n";
		}
		exit(0);
		return;
	}
	z[s] = 1;
	p.push_back(s);
	for (auto u : v[s]) {
		if (u == e) continue;
		dfs(u,s);
	}
	z[s] = 2;
	p.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		q[a].insert(b);
		q[b].insert(a);
	}
	c[0] = 1;
	dfs(1,0);
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) v1.push_back(i);
		else v2.push_back(i);
	}
	if (v2.size() >= (k+1)/2) swap(v1,v2);
	cout << "1\n";
	for (int i = 0; i < (k+1)/2; i++) {
		cout << v1[i] << " ";
	}
	cout << "\n";
}