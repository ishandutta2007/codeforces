#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const long long mod = 1e9 + 7;

int x, y, h;
long long rev[N];
long long fact[N];

long long Qpow(long long u, long long v){
	if(v == 0) return 1;
	if(v == 1) return u;

	long long f = Qpow(u, v >> 1);
	f = f * f % mod;
	return (f * Qpow(u, v % 2)) % mod;
}

long long nCk(int u, int v){
	return ((fact[u] * rev[u - v] % mod) * rev[v]) % mod;
}

long long calc(int n, int d, int lim = 0){
	if(d > n) return 0;

	if(lim == 0){
		return nCk(n - 1, d - 1);
	}

	long long m = n - 1LL * h * d;
	if(m < d) return 0;
	

	return nCk(m - 1, d - 1);
}

long long solve(int u, int v, int lim = 0){
	return (calc(x, u) * calc(y, v, lim)) % mod;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	fact[0] = rev[0] = 1;

	for(int i = 1; i < N; ++i){
		fact[i] = fact[i - 1] * i % mod;
		rev[i] = Qpow(fact[i], mod - 2);
	}

	cin >> x >> y >> h;

	if(x == 0){
		cout << (y > h);
		return 0;
	}

	if(y == 0){
		cout << 1;
		return 0;
	}

	long long tot = 0, ok = 0;

	for(int i = 1; i <= min(x, y); ++i){
		tot += solve(i, i) * 2 + solve(i, i + 1) + solve(i + 1, i);
		ok += solve(i, i, 1) * 2 + solve(i, i + 1, 1) + solve(i + 1, i, 1); 
		tot %= mod;
		ok %= mod;
	}




	cout << (ok * Qpow(tot, mod - 2)) % mod;

	return 0;
}