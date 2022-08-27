//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 8e5 + 7, mod = 1e9 + 7;
int qpow (int x, ll y) {
	int ret = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) 
		if(y & 1) ret = (ll) ret * x % mod;
	return ret;
}
int n, m, k, r, c, ax, bx, ay, by;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n >> m >> k >> r >> c;
	cin >> ax >> ay >> bx >> by;
	if(ax == bx && ay == by) 
		cout << qpow (k, (ll) n * m) << '\n';
	else 
		cout << qpow (k, (ll) n * m - (ll) r * c) << '\n';
	return 0;
}