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

int n, k, a[N];
ll pre[N], suf[N];
map < ll, pair < int, int > > mp;
void Main() {
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	pre[0] = 0, suf[n + 1] = 0;
	L(i, 1, n) pre[i] = pre[i - 1] + a[i];
	R(i, n, 1) suf[i] = suf[i + 1] + a[i];
	ll mid = pre[n] / 2;
	mp.clear();
	L(i, 1, n - 1) if(pre[i] <= mid) mp[pre[i]].first += 1;
	L(i, 2, n) if(suf[i] <= mid) mp[suf[i]].second += 1;
	int ns = 1;
	for(auto u : mp) {
		int s = 0;
//		cout << u.first << " : " << u.second.first << ' ' << u.second.second << '\n';
		if(u.first * 2 == pre[n]) {
			s = qpow(2, u.second.first);
		} else {
			s = C(u.second.first + u.second.second, u.second.second);
		}
		ns = (ll) ns * s % mod;
	}
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(100007);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}