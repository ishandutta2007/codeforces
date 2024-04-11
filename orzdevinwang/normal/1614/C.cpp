#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int n, m, f[N], Msk; 
void Main () {
	Msk = 0;
	cin >> n >> m;
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		Msk |= x;
	}
	int o = 1, ns = 0;
	L(i, 1, n - 1) o = (ll) o * 2 % mod;
	L(i, 0, 29) if(Msk >> i & 1) 
		(ns += (ll) o * (1 << i) % mod)  %= mod;
	cout << ns << '\n';
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}