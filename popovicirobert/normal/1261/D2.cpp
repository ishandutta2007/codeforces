#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

const int MOD = 998244353;

inline int lgput(int a, int b) {
	int ans = 1;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
	int i, n, k;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	
	vector <int> h(n);
	for(i = 0; i < n; i++) {
		cin >> h[i];
	}
	
	int x = 0;
	for(i = 0; i < n; i++) {
		if(h[i] != h[(i + 1) % n]) {
			x++;
		}
	}
	
	vector <int> pws(n + 1, 1), fact(n + 1, 1), invfact(n + 1);
	for(i = 1; i <= n; i++) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		pws[i] = (1LL * pws[i - 1] * (k - 2)) % MOD;
	}
	
	invfact[n] = lgput(fact[n], MOD - 2);
	for(i = n - 1; i >= 0; i--) {
		invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
	}
	
	auto comb = [&](int n, int k) -> int {
		if(n < k) return 0;
		return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
	};
	
	int ans = 0;
	for(int c = 0; c <= x - 1; c++) {
		int cur = (1LL * comb(x, c) * pws[c]) % MOD;
		//cerr << cur << "\n";
		if((x - c) % 2 == 1) {
			cur = (1LL * cur * lgput(2, x - c - 1)) % MOD;
		}
		else {
			cur = (1LL * cur * (lgput(2, x - c - 1) - (1LL * comb(x - c, (x - c) / 2) * lgput(2, MOD - 2) % MOD) + MOD)) % MOD;
		}
		ans = (ans + cur) % MOD;
	}
	
	ans = (1LL * ans * lgput(k, n - x)) % MOD;
	cout << ans;
	
	return 0;
}