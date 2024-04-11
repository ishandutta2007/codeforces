//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define smin(x, y) x = min(x, y)

const int maxn = 1e3 + 10;
bool mark[maxn],
	 kram[maxn];
int h[maxn],
	a[maxn],
	b[maxn],
	st[maxn],
	en[maxn],
	n, tim;
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
	st[u] = tim++;
	for (auto v : adj[u])
		if (v ^ p) {
			h[v] = h[u] + 1;
			dfs(v, u);
		}
	en[u] = tim++;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		adj[i].clear();
	fill(mark, mark + n, false);
	fill(kram, kram + n, false);
	fill(h, h + n, 0);
	tim = 0;
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int k1, k2;
	cin >> k1;
	for (int i = 0; i < k1; i++)
		cin >> a[i], mark[--a[i]] = true;
	cin >> k2;
	for (int i = 0; i < k2; i++)
		cin >> b[i], kram[--b[i]] = true;
	dfs(a[0]);
	cout << "A " << a[0] + 1 << endl;
	int a0, b0;
	cin >> a0, a0--;
	cout << "B " << b[0] + 1 << endl;
	cin >> b0, b0--;
	if (mark[b0])
		cout << "C " << b0 + 1 << endl;
	else {
		int u = -1;
		for (int i = 0; i < n; i++)
			if (mark[i] and st[i] < st[b0] and st[b0] < en[i] and (u == -1 or h[i] > h[u]))
				u = i;
		int t;
		if (u == a[0])
			t = a0;
		else {
			cout << "A " << u + 1 << endl;
			cin >> t, t--;
		}
		if (kram[t])
			cout << "C " << u + 1 << endl;
		else
			cout << "C " << -1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}