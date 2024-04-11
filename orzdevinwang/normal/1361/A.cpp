#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7;
int qpow (int x, int y = mod - 2) {
	int ret = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) ret = (ll) ret * x % mod;
	return ret;
}
int n, m, w[N], f[N], real;
struct node {
	int val, x;
} h[N];
vi e[N];
bool us[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	L(i, 1, n) cin >> w[i], h[i].val = w[i], h[i].x = i;
	sort(h + 1, h + n + 1, [&] (node x, node y) {
		return x.val < y.val;
	}) ;
	L(i, 1, n) {
		for(int x : e[i]) 
			us[w[x]] = true;
		int k = 1;
		while (us[k]) ++ k;
		if(w[i] != k) return cout << -1 << "\n", 0;
		for(int x : e[i]) 
			us[w[x]] = false;
	}
	L(i, 1, n) cout << h[i].x << " ";
	return 0;
}