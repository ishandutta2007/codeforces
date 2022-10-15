#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[1222333];
vector<int> w[1222333];
int del[1222333];
int inc[1222333];

void dfs(int s) {
	if (s == n+1) return;
	if (del[s]) {
		dfs(s+1);
	} else {
		del[s] = 1;
		for (auto x : v[s]) {
			del[x] = 1;
		}
		dfs(s+1);
		bool ready = false;
		for (auto x : w[s]) {
			if (inc[x]) ready = true;
		}
		if (!ready) inc[s] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		w[b].push_back(a);
	}
	dfs(1);
	vector<int> r;
	for (int i = 1; i <= n; i++) {
		if (inc[i]) r.push_back(i);
	}
	cout << r.size() << "\n";
	for (auto x : r) cout << x << " ";
	cout << "\n";
}