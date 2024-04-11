#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, m, top, h[N], f[N], siz[N], cnt[N];
ll c[N], w[N];
vi e[N];
void Main () {
	top = 0;
	cin >> n >> m;
	L(i, 1, n) cin >> c[i], f[i] = 0;
	siz[0] = n;
	L(t, 1, m)  {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	L(i, 1, n) {
		vi S;
		for (const int &v : e[i]) cnt[f[v]] += 1, S.push_back(f[v]);
		for (const int &v : e[i]) {
			if(!h[f[v]]) h[f[v]] = ++top, siz[f[v]] -= cnt[f[v]], siz[top] = cnt[f[v]];
			f[v] = h[f[v]];
		}
		for (const int &v : S) cnt[v] = h[v] = 0;
	}
	L(i, 1, n) w[f[i]] += c[i];
	ll ret = 0;
	L(i, 1, top) ret = __gcd (ret, w[i]);
	cout << ret << '\n';
	L(i, 0, top) w[i] = 0, siz[i] = 0, cnt[i] = 0;
	L(i, 1, n) e[i].clear ();
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}