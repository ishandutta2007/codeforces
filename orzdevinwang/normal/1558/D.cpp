#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 4e5 + 7, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, m, x[N], y[N];
int vis[N], sz[N];
void add (int x, int w) {
	for(; x; x -= x & -x) sz[x] += w;
}
int pn;
int query (int x) {
	int now = 0;
	R(i, 18, 0) if(now + (1 << i) <= pn) {
		int r = min(pn - (now + (1 << i)) + 1, 1 << i) - sz[now + (1 << i)];
		if(x >= r) x -= r;
		else now += 1 << i;
	}
	return now;
}
int a[N], mp[N];
void Main () {
	priority_queue < int > q;
	cin >> n >> m, pn = n;
	L(i, 1, m) 
		cin >> x[i] >> y[i], y[i] = x[i] - y[i];
	x[m + 1] = n + 1;
	R(i, m, 1) {
		pn = query (x[i + 1] - x[i] - 1);
		while (!q.empty() && q.top() > pn) add(q.top(), -1), q.pop();
		a[i] = query (y[i]), q.push (a[i]), mp[a[i]] = x[i], add (a[i], 1);
	}
	int cnt = n * 2 - 1;
	L(i, 1, m) cnt -= mp[a[i]] > mp[a[i] + 1];
	L(i, 1, m) mp[a[i]] = 0;
	cout << C(cnt, n) << "\n";
	while (!q.empty()) add(q.top(), -1), q.pop();
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init (4e5);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}