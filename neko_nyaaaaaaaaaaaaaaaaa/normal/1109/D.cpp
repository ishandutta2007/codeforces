#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7;
int modpow(int n, int k, int MOD);

int ft[2000006];

void init() {
    ft[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
		ft[i] = (ft[i-1] * i) % M;
    }
}

int nCr(int n, int m) {
    int p = ft[n];
    int q = (ft[m] * ft[n-m]) % M;

    int res = p*modpow(q, M-2, M);
    return res % M;
}

int sb(int n, int k) {
	return nCr(n-1, k-1);
}

int solve(int n, int m, int k) {
    int part = sb(m, k-1);
    int pick = (nCr(n-2, k-2) * ft[k-2]) % M;
    int path = (part*pick) % M;

	int wi = modpow(m, n-k, M);
    int cayley;
    if (n-k-1 < 0) {
		cayley = 1;
    } else {
		cayley = k*modpow(n, n-k-1, M);
    }
    cayley %= M;
    int out = (wi * cayley) % M;

    return (out*path) % M;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

    int n, m; cin >> n >> m;
    int ans = 0;

    for (int i = 2; i <= n; i++) {
		if (i-1 > m) break;
		ans += solve(n, m, i);
		ans %= M;
    }
    cout << ans;

 	return 0;
}

int modpow(int n, int k, int MOD) {
	int ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}