#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m;
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
int s[N];
int t[N];
int cnt[N], ns;
template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;

fenwt < N > fw;
void Main () {
	cin >> n >> m;
	L(i, 1, n) {
		cin >> s[i];
		cnt[s[i]] += 1;
		fw.add(s[i], 1);
	}
	L(i, 1, m) {
		cin >> t[i];
	}
	int cur = 1;
	L(i, 1, N - 7) 
		cur = (ll) cur * ifac[cnt[i]] % mod;
	L(i, 1, m) {
		if(i <= n) {
			int ret = fw.query(t[i] - 1);
//			L(j, 1, t[i] - 1) if(cnt[j]) 
//				(ret += cnt[j]) %= mod;
			(ns += (ll) ret * cur % mod * fac[n - i] % mod) %= mod;
		} else {
			(ns += 1) %= mod;
			break ;
		}
		if(!cnt[t[i]]) {
			break;
		}
		cur = (ll) cur * cnt[t[i]] % mod;
		cnt[t[i]] -= 1; 
		fw.add(t[i], -1);
	}
	cout << ns << '\n';
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init (N - 7);
	Main ();
	return 0;
}