#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, mod = 1e9 + 7;
int n, ns;
ll a[N], w[N][40], cnt[N][40], top[N];
vi e[N];
void dfs (int x, int fa) {
	++top[x], w[x][top[x]] = a[x], cnt[x][top[x]] = 1;
	int tp = 0;
	L(i, 1, top[x]) {
		w[x][i] = __gcd(w[x][i], a[x]);
		if(!tp || w[x][i] != w[x][tp]) ++tp, w[x][tp] = w[x][i], cnt[x][tp] = cnt[x][i];
		else cnt[x][tp] += cnt[x][i];
	}
	top[x] = tp;
	L(i, 1, top[x]) (ns += (ll) w[x][i] % mod * cnt[x][i] % mod) %= mod;
	for (const int &v : e[x]) if(v != fa) {
		top[v] = top[x];
		L(i, 1, top[x]) w[v][i] = w[x][i], cnt[v][i] = cnt[x][i];
		dfs (v, x);
	}
} 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1, 0);
	cout << ns << '\n';
	return 0;
}