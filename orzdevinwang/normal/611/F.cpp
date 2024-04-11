#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7, M = 15, mod = 1e9 + 7;
int n, k, w[N], c[N], d[N];

int inv[M], ifac[M];

int cnt[M], mx[M], mn[M], ns;
int lcnt[M], lmx[M], lmn[M], pre[M], suf[M];
int dp[N][M], tim[N];
char s[10];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, k = 2;
	inv[1] = ifac[0] = ifac[1] = 1;
	L(i, 2, k + 2) 
		inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod, 
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	
	L(i, 1, k) cin >> w[i];
	cin >> (s + 1);
	L(i, 1, n) {
		if(s[i] == 'U') c[i] = 1, d[i] = 1;
		if(s[i] == 'D') c[i] = 1, d[i] = -1;
		if(s[i] == 'L') c[i] = 2, d[i] = 1;
		if(s[i] == 'R') c[i] = 2, d[i] = -1;
	}
	ns = 1;
	L(i, 1, k) ns = (ll) ns * w[i] % mod;
	L(i, 1, n) {
		cnt[c[i]] += d[i];
		mx[c[i]] = max(mx[c[i]], cnt[c[i]]);
		mn[c[i]] = min(mn[c[i]], cnt[c[i]]);
		int ret = 1;
		L(j, 1, k) {
			int g = w[j] - mx[j] + mn[j];
			if(g > 0) ret = (ll) ret * g % mod;
			else return cout << ns << "\n", 0;
		}
		(ns += ret) %= mod;
	}
	L(i, 1, k) lcnt[i] = cnt[i];
	L(i, 1, n) {
		cnt[c[i]] += d[i];
		mx[c[i]] = max(mx[c[i]], cnt[c[i]]);
		mn[c[i]] = min(mn[c[i]], cnt[c[i]]);
		tim[i] = 1e9 + 7;
		int ret = 1;
		L(j, 1, k) {
			int g = w[j] - mx[j] + mn[j];
			if(g > 0) ret = (ll) ret * g % mod;
			else return cout << ns << '\n', 0;
			if(lcnt[j]) tim[i] = min(tim[i], g / abs (lcnt[j]));
		}
		if(tim[i] == 1e9 + 7) 
			return cout << -1 << '\n', 0;
		(ns += ret) %= mod;
	}
	int pns = ns;
	L(t, 1, k + 1) L(i, 1, n) {
		cnt[c[i]] += d[i];
		mx[c[i]] = max(mx[c[i]], cnt[c[i]]);
		mn[c[i]] = min(mn[c[i]], cnt[c[i]]);
		int ret = 1;
		L(j, 1, k) {
			int g = w[j] - mx[j] + mn[j];
			if(g > 0) ret = (ll) ret * g % mod;
			else return cout << ns << '\n', 0;
		}
		dp[i][t] = (dp[i][t - 1] + ret) % mod; 
		(ns += ret) %= mod;
	}
	ns = pns;
	L(i, 1, n) {
		L(a, 0, k + 1) pre[a] = suf[a] = tim[i] - a;
		L(a, 1, k + 1) pre[a] = (ll) pre[a - 1] * pre[a] % mod;
		R(a, k, 0) suf[a] = (ll) suf[a + 1] * suf[a] % mod;
		L(a, 0, k + 1) {
			int now = 1;
			now = (ll) ifac[a] * ifac[k + 1 - a] % mod * dp[i][a] % mod;
			if((k + 1 - a) & 1) now = mod - now;
			if(a > 0) now = (ll) now * pre[a - 1] % mod;
			if(a < k + 1) now = (ll) now * suf[a + 1] % mod; 
			(ns += now) %= mod;
		}
	} 
	cout << ns << "\n";
	return 0;
}