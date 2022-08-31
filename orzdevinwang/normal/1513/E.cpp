#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define mkp make_pair
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7, mod = 1e9 + 7;
int n, a[N], fac[N], inv[N], ifac[N], ns, buf;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
map<int, int> mp;

int rmain() {
	mp.clear();
	cin >> n, buf = 1;
	L(i, 1, n) cin >> a[i], mp[a[i]] ++, buf = (ll) buf * inv[mp[a[i]]] % mod;
	ll sum = 0; int mid = 0;
	L(i, 1, n) sum += a[i];
	if(sum % n) return cout << "0\n", 0;
	mid = sum / n;
	int cnt1 = 0, cnt2 = 0, ns = 0;
	L(i, 1, n) cnt1 += (a[i] < mid), cnt2 += (a[i] > mid);
	// cout << cnt1 << " " << cnt2 << "\n";
	if(cnt1 > cnt2) swap(cnt1, cnt2);
	if(cnt1 == 0) return cout << (ll) fac[n] * buf % mod << "\n", 0;
	if(cnt1 == 1) return cout << (ll) fac[n] * buf % mod << "\n", 0;
	// L(i, 1, cnt2 - 1) (ns += (ll) fac[i] * fac[cnt2 - i] % mod * fac[cnt1] % mod) %= mod;
	// L(i, 1, cnt1 - 1) (ns += (ll) fac[i] * fac[cnt1 - i] % mod * fac[cnt2] % mod) %= mod;
	if(cnt1 && cnt2) (ns += (ll) fac[cnt1] * fac[cnt2] % mod * 2 % mod) %= mod;
	else (ns += (ll) fac[cnt1] * fac[cnt2] % mod) %= mod;
	// cout << ns << "\n";
	ns = (ll) ns * buf % mod * fac[n] % mod * ifac[cnt1 + cnt2] % mod;
	cout << ns << "\n";
	return 0;
}
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(200000);
	rmain();
	return 0;
}