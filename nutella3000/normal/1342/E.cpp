#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int mod = 998244353;

int fact[200001], i_fact[200001];

int mul(int a, int b) {
	return a * b % mod;
}

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a <= -mod) a += mod;
	return a;
}

int binpow(int a, int b) {
	int res = 1;
	while(b > 0) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1; 
	}
	return res;
}

int inverse(int a) {
	return binpow(a, mod - 2);
}

void precalc() {
	fact[0] = 1;
	i_fact[0] = 1;
	for(int i = 1;i <= 200000;i++) {
		fact[i] = mul(fact[i - 1], i);
		i_fact[i] = inverse(fact[i]);
	}
}

int cnk(int n, int k) {
	return mul(fact[n], mul(i_fact[k], i_fact[n - k]));
}

int f(int k, int n, int c) {
	return add(binpow(c, n), -binpow(c - k, n));
}


void solve() {
	precalc();

	int n, k;
	cin >> n >> k;
	if (k > n) {
		cout << 0;
		return;
	}

	int c = n - k;

	int res = 0;
	for(int i = 1;i <= c;i++) {
		int coef = -1;
		if (i & 1) coef = 1;
		res = add(res, coef * mul(cnk(c, i), f(i, n, c)));
	}

	res = mul(res, cnk(n, k));

	if (k != 0) res = mul(res, 2);
	if (res < 0) res += mod;
	cout << res;
}






signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}