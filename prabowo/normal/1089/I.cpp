#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 405;

ll mod;
vector<vector<ll>> t = vector<vector<ll>>(MX, vector<ll>(MX));

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}
int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		rep(j,i+1,n) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
		rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	rep(i,0,n) rep(j,0,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
	return n;
}



ll fact[405];

int main() {
	int tc;
	scanf("%d%lld", &tc, &mod);
	fact[0] = 1;
	for (int i = 1; i < MX; ++i) {
		fact[i] = (long long) fact[i - 1] * i % mod;
	}

	for (int i = 0; i < MX; ++i) t[i][1] = fact[i], t[i][i] = 1;

	for (int i = 2; i < MX; ++i) {
		for (int j = 2; j < i; ++j) {
			ll &res = t[i][j];
			res = 0;
			for (int m = 0; m <= i - j; ++m) {
				res += (long long) fact[m + 1] * t[i - m - 1][j - 1] % mod;
				res %= mod;
			}
		}
	}
	matInv(t);

	// rep(i, 0, MX) {
	// 	rep(j, 0, MX) printf("%lld ", t[i][j]);
	// 	printf("\n");	
	// }


	rep(i, 0, MX) rep(j, 0, MX) {
		ll &res = t[i][j];
		res %= mod;
		res = -res;
		if (i & 1) res += 2; else res -= 2;
		res += mod;
		res %= mod;
		if (res < 0) res += mod;
	}

	while (tc--) {
		int x; scanf("%d", &x);
		if (x == 2) printf("2\n");
		else printf("%lld\n", t[x][1]);
	}

}