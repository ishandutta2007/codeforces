#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
const ll inf = 1e18;
ll n, x, y;
struct mat {
	ll f[2][2];
	mat (ll w = 0) {
		L(i, 0, 1) L(j, 0, 1) f[i][j] = i == j ? w : -inf;
	}
	void mark(ll w) {
		f[0][0] = 0, f[0][1] = w, f[1][0] = 0, f[1][1] = -inf;
	}
} ;
mat operator * (mat a, mat b) {
	mat ret;
	L(i, 0, 1) L(j, 0, 1) ret.f[i][j] = max(a.f[i][0] + b.f[0][j], a.f[i][1] + b.f[1][j]);
	return ret;
}
mat pw(mat u, int k) {
	mat ret(0);
	for(; k; k >>= 1, u = u * u) if(k & 1) ret = ret * u;
	return ret;
}
mat slv(int n, int m, int r, mat a, mat b) {
	mat ret(0);
	int v = 0;
	L(i, 0, n - 1) ret = ret * (v < r ? a : b), (v += m) %= n;
	return ret;
}
int calc(int n, int x, int y) {
	if(__gcd(x, y) > 1) {
		int g = __gcd(x, y), r = n % g; 
		return calc(n / g, x / g, y / g) * (g - r) + calc(n / g + 1, x / g, y / g) * r;
	}
	mat a, b;
	a.mark(n / (x + y) + 1), b.mark(n / (x + y));
	mat ret = slv(x + y, x, n % (x + y), a, b);
	return max(ret.f[0][0], ret.f[1][1]);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> x >> y;
	cout << calc(n, x, y) << "\n";
	return 0;
}