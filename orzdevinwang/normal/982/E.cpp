#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7; 
ll n, m, x, y, vx, vy, d1[3], d2[3];
void exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= x * (a / b); 
}
ll Mul(ll a, ll b, ll mod) { ll x = a * b - (ll) ((long double) a * b / mod + 0.2) * mod; return x < 0 ? x + mod : x; }
ll crt(ll *a, ll *b, int n) { 
	ll a0 = 1, b0 = 0;
	L(i, 1, n) {
		ll g = __gcd(a0, a[i]), c0, c1, md = a[i] / g;
		if((b[i] - b0) % g) return -1;
		exgcd(a0, a[i], c0, c1), b0 += a0 * Mul((c0 + md) % md, ((b[i] - b0) / g % md + md) % md, md), a0 *= md;
	}
	return b0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y >> vx >> vy;
	if((x == 0 || x == n) && (y == 0 || y == m)) return cout << x << " " << y << "\n", 0;
	if(vx == 0 && vy == 0) return cout << "-1\n", 0;
	if(vx == 0) {
		if(x == n || x == 0) cout << x << " " << (vy == -1 ? 0 : m) << "\n";
		else cout << "-1\n";
		return 0;
	}
	if(vy == 0) {
		if(y == m || y == 0) cout << (vx == -1 ? 0 : n) << " " << y << "\n";
		else cout << "-1\n";
		return 0;
	}
	if(vx == -1) x = n - x;
	if(vy == -1) y = m - y;
	d1[1] = n, d2[1] = n - x;
	d1[2] = m, d2[2] = m - y;
	ll ns = crt(d1, d2, 2);
	if(ns == -1) return cout << "-1\n", 0;
	x = (ns + x) % (n * 2), y = (ns + y) % (m * 2);
	if(vx == -1) x = n - x;
	if(vy == -1) y = m - y;
	cout << x << " " << y << "\n";
	return 0;
}