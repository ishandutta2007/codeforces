#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int m; cin >> m;
	
	int K = 0;
	map<int,int> id;
	auto get_id = [&](int x) {
		if (!id.count(x)) id[x] = K++;
		return id[x];
	};
	
	vector<vector<int>> a(m);
	for (int i = 0; i < m; i++) {
		int n; cin >> n;
		a[i].resize(n);
		for (int &x: a[i]) {
			cin >> x;
			x = get_id(x);
		}
	}

	vector<int> s(m+1);
	for (int i = 0; i < m; i++) {
		s[i+1] = s[i] + size(a[i]);
	}

	auto I = [&](int i, int j) { return s[i] + j; };

	vector<vector<int>> occ(K);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < ssize(a[i]); j++) {
			occ[a[i][j]].push_back(I(i,j));
		}
	}

	vector<vector<int>> adj(s[m]);
	for (const auto &v: occ) {
		if (size(v) % 2 != 0) {
			cout << "NO" << '\n';
			return 0;
		}
		for (int i = 0; i < ssize(v); i += 2) {
			adj[v[i]].push_back(v[i+1]);
			adj[v[i+1]].push_back(v[i]);
		}
	}
	for (int i = 0; i < s[m]; i += 2) {
		adj[i].push_back(i+1);
		adj[i+1].push_back(i);
	}

	string res(s[m], '?');
	for (int i = 0; i < s[m]; i++) if (res[i] == '?') {
		int x = i, y = adj[i][0];
		char c = 'L';
		do {
			res[x] = c;
			c ^= 'L' ^ 'R';
			y ^= adj[x][0] ^ adj[x][1];
			swap(x,y);
		} while (x != i);
	}

	cout << "YES" << '\n';
	for (int i = 0; i < m; i++) {
		cout << res.substr(s[i], size(a[i])) << '\n';
	}
}