#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 500005;
const int MOD = 1e9 + 7;

int binPow(ll b, int p) {ll res = 1; while(p) {if (p & 1) res = res * b % MOD; b = b * b % MOD; p >>= 1;} return res;}

int n, m;
int p[mxN], r[mxN];
bool f[mxN];
vector<int> ans;

int find(int i) {return i == p[i] ? i : p[i] = find(p[i]);}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v || (f[u] && f[v])) return 0;
	if (r[u] < r[v]) swap(u, v);
	p[v] = u;
	r[u] += r[u] == r[v];
	f[u] |= f[v];
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	iota(p, p + m, 0);
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		if (k == 1) {
			int x; cin >> x, --x;
			x = find(x);
			if (!f[x]) {
				f[x] = 1;
				ans.push_back(i);
			}
		}
		else if (k == 2) {
			int x, y; cin >> x >> y, --x, --y;
			if (merge(x, y)) ans.push_back(i);
		}
	}
	cout << binPow(2, ans.size()) << " " << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
	return 0;
}