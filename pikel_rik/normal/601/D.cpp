#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

struct node {
	int sz = 0;
	char c = '$';
	node* nxt[26] = {0};
	node (char c): sz(1), c(c) {}
};

int n, c[N], dp[N];
vector<int> g[N];
string s;
node *trie[N];

node* merge(node *x, node *y) {
	for (int i = 0; i < 26; i++) {
		if (x->nxt[i] && y->nxt[i]) {
			x->sz -= x->nxt[i]->sz;
			x->nxt[i] = merge(x->nxt[i], y->nxt[i]);
			x->sz += x->nxt[i]->sz;
		} else if (!x->nxt[i] && y->nxt[i]) {
			x->nxt[i] = y->nxt[i];
			x->sz += x->nxt[i]->sz;
		}
	}
	return x;
}

void dfs(int x, int p) {
	node *last[26] = {0};
	for (int i : g[x]) {
		if (i == p) continue;
		dfs(i, x);
		if (last[s[i] - 'a']) {
			trie[i] = merge(last[s[i] - 'a'], trie[i]);
		}
		last[s[i] - 'a'] = trie[i];
	}
	trie[x] = new node(s[x] - 'a');
	for (int i = 0; i < 26; i++) {
		if (last[i]) {
			trie[x]->nxt[i] = last[i];
			trie[x]->sz += trie[x]->nxt[i]->sz;
		}
	}
	dp[x] = trie[x]->sz;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];

	cin >> s; s = ' ' + s;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);

	int mx = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] + c[i] > mx) {
			mx = dp[i] + c[i];
			cnt = 1;
		} else if (dp[i] + c[i] == mx) {
			cnt++;
		}
	}

	cout << mx << '\n' << cnt << '\n';
	return 0;
}