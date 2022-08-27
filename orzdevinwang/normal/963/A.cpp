#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 9;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, a, b, k, ns;
char s[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> k;
	cin >> s;
	int pw = (n + 1) / k;
	b = (ll) b * qpow(a) % mod;
	// sum b^{i} 
	L(i, 0, k - 1) {
		int w = s[i] == '+' ? 1 : mod - 1;
		int xb = qpow(b, k);
		int xsum = 0;
		if(xb == 1) {
			xsum = pw;
		} else {
			xsum = (ll) (qpow(xb, pw) - 1) * qpow(xb - 1) % mod;
		}
//		cout << xsum << endl;
		(ns += (ll) w * qpow(b, i) % mod * xsum % mod) %= mod;
	}
	ns = (ll) ns * qpow(a, n) % mod;
	cout << ns << '\n';
	return 0;
}