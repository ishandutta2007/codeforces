#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];

struct DSU {
	int root[N];
	int getRoot(int u) {
		return root[u] ? root[u] = getRoot(root[u]) : u;
	}
	bool unite(int u, int v) {
		u = getRoot(u);
		v = getRoot(v);
		if (u == v) return 0;
		root[u] = v;
		return 1;
	}
} dsu;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string u; cin >> u;
		for (char v : u) {
			a[i] |= (1 << v - 'a');
		}
	}	
	int num = n;
	for (int i = 0; i < 26; i++) {
		vector<int> ls;
		for (int j = 1; j <= n; j++) if (a[j] >> i & 1) ls.push_back(j);
		if (ls.empty()) continue;
		for (int j = 1; j < ls.size(); j++) {
			num -= dsu.unite(ls[0], ls[j]);
		}
	}
	cout << num << endl;
	return 0;
}