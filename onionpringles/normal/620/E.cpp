#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int B = 524288;

ll tr[2 * B];
int modified[2 * B];
ll mod_val[2 * B];
ll mask[60];
vector<int> adj[400000];
int c[400000];
int le[400000];
int re[400000];
int clk = 0;

void dfs(int i, int p) {
	le[i] = clk++;
	for (auto &x : adj[i]) {
		if (p == x) continue;
		dfs(x, i);
	}
	re[i] = clk - 1;
}

void push(int nd) {
	if (!modified[nd]) return;
	tr[nd] = mod_val[nd];
	modified[nd] = 0;
	if (nd >= B) return;
	modified[2 * nd] = modified[2 * nd + 1] = 1;
	mod_val[2 * nd] = mod_val[2 * nd + 1] = tr[nd];
	return;
}

void upd(int nd, int ndl, int ndr, int l, int r, int clr) {
	if (ndl > r || l > ndr) return;
	else if (l <= ndl && ndr <= r) {
		modified[nd] = 1;
		mod_val[nd] = mask[clr];
		int cur = nd / 2;
		while (cur > 0) {
			push(2 * cur);
			push(2 * cur + 1);
			tr[cur] = tr[2 * cur] | tr[2 * cur + 1];
			cur /= 2;
		}
		return;
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		upd(2 * nd, ndl, mid, l, r, clr);
		upd(2 * nd + 1, mid + 1, ndr, l, r, clr);
	}
}

ll get(int nd, int ndl, int ndr, int l, int r) {
	if (ndl > r || l > ndr) return 0;
	else if (l <= ndl && ndr <= r) {
		push(nd);
		return tr[nd];
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		ll a1 = get(2 * nd, ndl, mid, l, r);
		ll a2 = get(2 * nd + 1, mid + 1, ndr, l, r);
		return a1 | a2;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	mask[0] = 1;
	for (int i = 1; i < 60; i++) {
		mask[i] = mask[i - 1] << 1;
	}
	int n, m; nii(n, m);
	for (int i = 0; i < n; i++) {
		int cl; ni(cl);
		c[i] = cl - 1;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		nii(u, v);
		u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		tr[B + le[i]] = mask[c[i]];
	}
	for (int i = B - 1; i > 0; i--) {
		tr[i] = tr[2 * i] | tr[2 * i + 1];
	}
	for (int i = 0; i < m; i++) {
		int t;
		ni(t);
		if (t == 1) {
			int v, c;
			nii(v, c);
			v--; c--;
			upd(1, 0, B - 1, le[v], re[v], c);
		}
		else {
			int v;
			ni(v); v--;
			ll val = get(1, 0, B - 1, le[v], re[v]);
			int cnt = 0;
			while (val) {
				cnt++;
				val -= val&(-val);
			}
			printf("%d\n", cnt);
		}
	}
}