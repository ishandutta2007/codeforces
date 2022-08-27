#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 4096, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, c, a[N], dp[N][N], ns[N], Pw[N], iPw[N], cnt[N];
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
namespace zky1 {
	void Main() {
		Pw[0] = 0;
		L(i, 1, n) Pw[i] = (Pw[i - 1] * 2 + 1) % mod, iPw[i] = qpow(Pw[i]);
		dp[0][0] = 1;
		L(i, 1, n) {
			int V = 1, r = c - 1;
			R(j, i - 1, 0) {
				int fs = (r ? 0 : V);
				L(t, 1, i / c) 
					dp[i][t] = add(dp[i][t], (ll) dp[j][t - 1] * fs % mod);
				if(j && a[j] != a[i]) {
					if(cnt[a[j]]) V = (ll) V * iPw[cnt[a[j]]] % mod;
					else --r; 
					cnt[a[j]]++, V = (ll) V * Pw[cnt[a[j]]] % mod;
				} 
			}
			L(j, 1, c) cnt[j] = 0;
		}
		int V = 1, r = c;
		R(i, n, 0) {
			int fs = (qpow(2, n - i) + mod - (r ? 0 : V)) % mod;
			L(j, 0, i / c) ns[j] = add(ns[j], (ll) dp[i][j] * fs % mod);
			if(!i) break;
			if(cnt[a[i]]) V = (ll) V * iPw[cnt[a[i]]] % mod; 
			else --r;
			cnt[a[i]]++, V = (ll) V * Pw[cnt[a[i]]] % mod;
		}
		(ns[0] += mod - 1) %= mod;
		L(i, 0, n) cout << ns[i] << " ";
	} 
}
namespace zky2 {
	void Main() {
		L(i, 1, n) --a[i];
		dp[0][0] = 1;
		L(i, 1, n) {
			L(j, 0, i / c) R(msk, (1 << c) - 1, 0) 
				dp[j][msk | (1 << (a[i]))] = add(dp[j][msk], dp[j][msk | (1 << a[i])]);	
			L(j, 0, i / c) dp[j + 1][0] = add(dp[j + 1][0], dp[j][(1 << c) - 1]), dp[j][(1 << c) - 1] = 0;
		} 
		L(i, 0, n) {
			int sum = i == 0 ? mod - 1 : 0;
			L(j, 0, (1 << c) - 1) sum = add(sum, dp[i][j]);
			cout << sum << ' ';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	L(i, 1, n) cin >> a[i];
	if(c <= 12) zky2::Main();
	else zky1::Main(); 
	return 0;
}