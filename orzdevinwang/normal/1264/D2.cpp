#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int fac[N], ifac[N], inv[N], pw[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = pw[0] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod, pw[i] = (ll) pw[i - 1] * 2 % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, pre1[N], pre2[N], all, now, ns;
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> (s + 1), n = strlen(s + 1), init(n + 3);
	int x = 0, y = 0, a = 0, b = 0;
	L(i, 1, n) y += (s[i] == '?'), b += (s[i] == ')'), all += (s[i] == '?');
	L(i, 0, all) pre1[i] = C(all, i), pre2[i] = C(all - 1, i);
	L(i, 1, all) (pre1[i] += pre1[i - 1]) %= mod, (pre2[i] += pre2[i - 1]) %= mod;
	L(i, 1, n) {
		y -= (s[i] == '?'), b -= (s[i] == ')');
		int sum = 0;
		if(s[i] != ')') {
			if(s[i] != '?' && y + b - a > 0) (ns += pre1[min(y + b - a - 1, all)]) %= mod;
			if(s[i] == '?' && y + b - a > 0) (ns += pre2[min(y + b - a - 1, all)]) %= mod;
		}
		x += (s[i] == '?'), a += (s[i] == '(');
	}
	cout << ns << "\n";
	return 0;
}