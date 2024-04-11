#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 150002;
vector<int> g[N], ng[N];
int p[N], c[N], d[N], mc[N][27], ms[N], np[N], nc[N][27], ns[N];
int wr = 0;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q, v, cc;
	cin >> n >> q;
	char ch;
	for (int i = 1; i < n; i++) {
		cin >> v >> ch;
		v--;
		cc = (ch == '?' ? 26 : ch - 'a');
		p[i] = v;
		c[i] = cc;
		g[v].push_back(i);
	}
	for (int i = 1; i < n; i++) {
		if (p[i] == 0 || g[p[i]].size() > 1)
			np[i] = p[i];
		else {
			np[i] = np[p[i]];
			rep(j, 26)
				nc[i][j] = nc[p[i]][j];
		}
		nc[i][c[i]]++;
		if (g[i].size() != 1)
			ng[np[i]].push_back(i);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (g[i].size() == 1)
			ns[i] = ns[g[i][0]];
		else
			ns[i] = i;
	}
	int fl = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (g[i].empty())
			continue;
		d[i] = d[g[i][0]] + 1;
		if (g[i].size() > 1 && d[g[i][0]] != d[g[i][1]]) {
			fl = 1;
			break;
		}
		for (int u : g[i])
			rep(j, 26)
				mc[i][j] = max(mc[i][j], mc[u][j] + (c[u] == j ? 1 : 0));
		rep(j, 26)
			ms[i] += mc[i][j];
		if (ms[i] > d[i])
			wr++;
	}
	if (fl) {
		rep(i, q)
			cout << "Fou\n";
		return 0;
	}
	rep(z, q) {
		cin >> v >> ch;
		v--;
		cc = (ch == '?' ? 26 : ch - 'a');
		int oc = c[v];
		c[v] = cc;
		v = ns[v];
		nc[v][oc]--;
		nc[v][cc]++;
		// cout << v << ' ' << nc[v][0] << '\n';
		while (v > 0) {
			v = np[v];
			if (ms[v] > d[v])
				wr--;
			if (oc < 26) {
				ms[v] -= mc[v][oc];
				mc[v][oc] = max(mc[ng[v][0]][oc] + nc[ng[v][0]][oc], (ng[v].size() == 1 ? 0 : mc[ng[v][1]][oc] + nc[ng[v][1]][oc]));
				ms[v] += mc[v][oc];
			}
			if (cc < 26) {
				ms[v] -= mc[v][cc];
				mc[v][cc] = max(mc[ng[v][0]][cc] + nc[ng[v][0]][cc], (ng[v].size() == 1 ? 0 : mc[ng[v][1]][cc] + nc[ng[v][1]][cc]));
				ms[v] += mc[v][cc];
			}
			if (ms[v] > d[v])
				wr++;
			// cout << v << ' ' << mc[v][0] << ' ' << ng[v][1] << '\n';
		}
		if (wr > 0) {
			cout << "Fou\n";
			continue;
		}
		ll res = 0;
		rep(i, 26)
			res += (d[0] - ms[0] + mc[0][i]) * (i + 1);
		cout << "Shi " << res << '\n';
	}
}