#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 12), inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, a[N][N], rk, pw[N];
struct fenwt {
	int a[N], n = N - 1;
	void init () {
		L(i, 1, n) if(i + (i & -i) <= n) a[i + (i & -i)] += a[i];
	}
	void add (int x, int  w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	int query (int x) {
		int ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	int get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		memset(a, 0, sizeof(a));
	}
} s, r;
int dp[N][N]; 
// n m  i 

bool vis[N], cvis[N]; 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	init (n * 2 + 4);
	L(i, 1, n) L(j, 1, n) cin >> a[i][j];
	L(i, 0, n) {
		dp[i][0] = fac[i];
		L(j, 1, i) dp[i][j] = ((ll) (i - j) * dp[i - 1][j - 1] + (ll) (j - 1) * dp[i - 1][j - 2] % mod) % mod;
	}
//	cout << dp[2][2] << ' ' << dp[1][1] << '\n';
	int ns = 0;
	L(i, 1, n) {
		memset(vis, true, sizeof(vis));
		memset(cvis, true, sizeof(cvis));
		s.clear(), r.clear();
		L(j, 1, n) s.add(j, 1);
		int ret = 0;
		if(i == 1) {
			L(j, 1, n) {
				int t = s.query(a[i][j]);
				(ret += (ll) (t - 1) * fac[n - j] % mod) %= mod;
				s.add(a[i][j], -1);
			}	
		}
		else {
			int cnt = n;
			L(j, 1, n) r.add(j, 1), cvis[j] = true; 
			L(j, 1, n) { 
				if(vis[a[i - 1][j]]) vis[a[i - 1][j]] = false, cnt -= 1, r.add(a[i - 1][j], -1);
				int t = s.query(a[i][j] - 1), ct = r.query(a[i][j] - 1);
				if(a[i - 1][j] < a[i][j] && cvis[a[i - 1][j]]) t -= 1; 
//				cout << t << " and " << ct << '\n';
				(ret += (ll) dp[n - j][cnt - 1] * ct % mod) %= mod;
				(ret += (ll) dp[n - j][cnt] * (t - ct) % mod) %= mod;
				// a_[i-1][j+1 ~ n] , a[i][j+1 ~ n] ;  
				s.add(a[i][j], -1), cvis[a[i][j]] -= 1;
				if(vis[a[i][j]]) vis[a[i][j]] = false, cnt -= 1, r.add(a[i][j], -1);
			}
		} 
//		cout << "ret = " << ret << '\n';
		ns = (ll) ns * dp[n][n] % mod; 
		(ns += ret) %= mod;
	}
	cout << ns << '\n';
	return 0;
}