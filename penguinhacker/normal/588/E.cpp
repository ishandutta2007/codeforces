#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Node {
	int a[10];
	Node() {memset(a, 0x3f, sizeof(a));}
	void add(int x) {
		int i;
		for (i = 0; i < 10; ++i) {
			if (x < a[i]) {
				break;
			}
		}
		for (int j = 9; j > i; --j) {
			swap(a[i], a[j]);
		}
		if (i < 10) {
			a[i] = x;
		}
	}

	int& operator[] (int x) {
		return a[x];
	}
};
Node combine(Node a, Node b) {
	Node res;
	for (int i = 0, j = 0; i + j < 10;) {
		if (a[i] <= b[j]) {
			res[i + j] = a[i];
			++i;
		}
		else {
			res[i + j] = b[j];
			++j;
		}
	}
	return res;
}

int n, m, q;
int dep[100000], anc[100000][17];
Node lift[100000][17];
vector<int> adj[100000];

/*vector<int> combine(vector<int> a, vector<int> b) {
	vector<int> c(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	sort(c.begin(), c.end());
	c.resize(min((int)c.size(), 10));
	return c;
}*/

void dfs(int u = 0, int p = -1) {
	anc[u][0] = p;
	for (int i = 1; i < 17; ++i) {
		if (anc[u][i - 1] == -1) {
			anc[u][i] = -1;
			lift[u][i] = lift[u][i - 1];
		}
		else {
			anc[u][i] = anc[anc[u][i - 1]][i - 1];
			lift[u][i] = combine(lift[u][i - 1], lift[anc[u][i - 1]][i - 1]);
		}
	}
	for (int v : adj[u]) {
		if (v != p) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}

int lca(int a, int b) {
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	for (int i = 16; ~i; --i) {
		if (dep[b] - (1 << i) >= dep[a]) {
			b = anc[b][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = 16; ~i; --i) {
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

Node getPath(int a, int l) {
	Node res;
	for (int i = 16; ~i; --i) {
		if (dep[a] - (1 << i) >= dep[l]) {
			res = combine(res, lift[a][i]);
			a = anc[a][i];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c, --c;
		//lift[c][0].push_back(i + 1);
		lift[c][0].add(i + 1);
	}
	/*for (int i = 0; i < n; ++i) {
		sort(lift[i][0].begin(), lift[i][0].end());
	}*/
	dfs();
	for (int i = 0; i < q; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		int l = lca(a, b);
		Node res = combine(getPath(a, l), getPath(b, l));
		//ans = combine(ans, lift[l][0]);
		//ans.resize(min((int)ans.size(), c));
		//cout << ans.size() << " ";
		res = combine(res, lift[l][0]);
		vector<int> ans;
		for (int i = 0; i < min(c, 10); ++i) {
			if (res[i] > 1000000) {
				break;
			}
			ans.push_back(res[i]);
		}
		cout << ans.size() << " ";
		for (int i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}