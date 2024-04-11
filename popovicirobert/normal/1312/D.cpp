#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 2e5;

int fact[MAXN + 1], invfact[MAXN + 1];

inline int lgput(int a, int b) {
	int ans = 1;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}

inline void prec() {
	fact[0] = invfact[0] = 1;
	for(int i = 1; i <= MAXN; i++) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		invfact[i] = lgput(fact[i], MOD - 2);
	}
}

inline int comb(int n, int k) {
	if(n < k || k < 0) return 0;
	return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}

int main() {
#ifdef HOME
	ifstream cin("A.in");
	ofstream cout("A.out");
#endif
	int i, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	if(m == 2) {
		cout << 0;
		return 0;
	}
	prec();
	// comb(m, n - 1) * (n - 2) * (2 ^ (n - 3))
	int ans = (1LL * comb(m, n - 1) * (n - 2)) % MOD;
	for(i = 0; i < n - 3; i++) {
		ans = (1LL * ans * 2) % MOD;
	}
	cout << ans;
	
	return 0;
}