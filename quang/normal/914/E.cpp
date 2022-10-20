#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 20;

int n;
vector<int> a[N];
int val[N];
char s[N];
long long res[N];
int dead[N];
int cnt[(1 << M) + 1];
int num[(1 << M) + 1];
int child[N];

void add(int u, int p, int mask, int x) {
	mask ^= (1 << val[u]);
	cnt[mask] += x;
	for (int v : a[u]) {
		if (dead[v] || v == p) {
			continue;
		}
		add(v, u, mask, x);
	}
}

pair<long long, int> dfs(int u, int p, int mask, int mask2) {
	child[u] = 1;
	mask ^= (1 << val[u]);
	long long ans = cnt[mask];
	int ans2 = (num[mask ^ mask2] <= 1); 
	for (int i = 0; i < M; i++) {
		ans += cnt[mask ^ (1 << i)];
	}
	for (int v : a[u]) {
		if (dead[v] || v == p) {
			continue;
		}
		pair<long long, int> foo = dfs(v, u, mask, mask2);
		ans += foo.first;
		ans2 += foo.second;
		child[u] += child[v];
	}
	res[u] += ans + ans2;
	return make_pair(ans, ans2);
}

int findCentroid(int u, int p, int &sz) {
	child[u] = 1;
	int f = 0;
	for (int v : a[u]) {
		if (dead[v] || v == p) {
			continue;
		}
		int foo = findCentroid(v, u, sz);
		if (foo) {
			return foo;
		}
		f |= ((child[v] * 2) > sz);
		child[u] += child[v];
	}
	f |= (((sz - child[u]) * 2) > sz);
	if (f) return 0;
	return u;
}

void go(int u, int sz) {
	u = findCentroid(u, 0, sz);
	dead[u] = 1;
	for (int v : a[u]) {
		if (dead[v]) {
			continue;
		}
		add(v, u, 1 << val[u], 1);
	}
	long long ans = 0;
	for (int v : a[u]) {
		if (dead[v]) {
			continue;
		}
		add(v, u, 1 << val[u], -1);
		pair<long long, int> foo = dfs(v, u, 0, 1 << val[u]);
		ans += foo.first;
		res[u] += foo.second;
		add(v, u, 1 << val[u], 1);	
	}
	for (int v : a[u]) {
		if (dead[v]) {
			continue;
		}
		add(v, u, 1 << val[u], -1);
	}
	assert(ans % 2 == 0);
	res[u] += ans / 2 + 1;
	// cout << "centroid " << u << " " << ans << endl;
	// for (int i = 1; i <= n; i++) {
	// 	cout << res[i] << " ";
	// }
	// cout << endl;
	for (int v : a[u]) {
		if (!dead[v]) {
			go(v, child[v]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	num[0] = 0;
	for (int i = 1; i < (1 << M); i++) {
		num[i] = num[i - (i & -i)] + 1;
	}
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		val[i] = (s[i] - 'a');
	}
	go(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", res[i]);
	}
	return 0;
}