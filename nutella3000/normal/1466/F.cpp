#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 4;
const int max_n = 5e5 + 7;
const int mod = 1e9 + 7;

vector<int> res2;
int par[max_n];
int sz[max_n];
bool good[max_n];

int dp[max_n][2];

int sum(int a, int b) {
	int res = a + b;
	if (res >= mod) res -= mod;
	return res;
}
int mul(int a, int b) {
	return a * b % mod;
}

int _get(int v) {
	int p = v;
	while(v != par[v]) v = par[v];
	while(p != v) {
		int t = par[p];
		par[p] = v;
		p = t;
	}
	return v;
}

void merge(int a, int b) {
	a = _get(a), b = _get(b);
	par[a] = b;
	sz[b] += sz[a];
	good[b] = (good[a] | good[b]);
}

int binpow(int a, int b) {
	int res = 1;
	for(;b > 0;b /= 2, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}

void solve() {
	for(int i = 0;i < max_n;i++) {
		par[i] = i;
		sz[i] = 1;
	}

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);

	for(int i = 0;i < n;i++) {
		int k;
		cin >> k;
		for(int j = 0;j < k;j++) {
			int v;
			cin >> v;
			edge[i].emplace_back(--v);
		}
	}

	int res = 1;

	for(int i = 0;i < n;i++) {
		if (sz(edge[i]) == 1) {
			int v = edge[i][0];
			if (good[_get(v)]) continue;
			good[_get(v)] = true;
			res = res * 2 % mod;
			res2.emplace_back(i + 1);
			continue;
		}

		int v1 = _get(edge[i][0]), v2 = _get(edge[i][1]);
		if (v1 == v2) continue;
		if (good[v1] && good[v2]) continue;
		res = res * 2 % mod;

		res2.emplace_back(i + 1);
		merge(v1, v2);
	}


	cout << res << " " << sz(res2) << endl;
	sort(all(res2));
	for(int i : res2)
		cout << i << " ";
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}