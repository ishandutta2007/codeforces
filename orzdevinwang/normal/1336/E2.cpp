#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size()) 
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = 64, mod = 998244353, inv2 = (mod + 1) / 2;
int n, m, ct, l, cnt[N], ns[M], all = 1;
int fac[M], ifac[M], inv[M];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
ll a[N], f[M], o[M];
void dfs(int x, ll now) {
	if(x == l + 1) return ++cnt[__builtin_popcountll(now)], void();
	dfs(x + 1, now), dfs(x + 1, now ^ o[x]);
}
void ins (ll x) {
	R(i, m - 1, 0) if(x >> i & 1) {
		if(!f[i]) return f[i] = x, void();
		x ^= f[i];
	}
	all = (ll) all * 2 % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i], ins(a[i]);
	L(i, 0, m - 1) if(f[i]) o[++ct] = f[i];
	if(m == 0) ns[0] = 1;  
	else if(ct * 2 <= m) l = ct, dfs(1, 0), copy(cnt, cnt + m + 1, ns);
	else {
		init(m + 1), memset(o, 0, sizeof(o));
		L(i, 1, m - ct) all = (ll) all * inv2 % mod;
		R(i, m - 1, 0) R(j, i - 1, 0) f[i] = min(f[i], f[i] ^ f[j]);
		L(i, 0, m - 1) if(!f[i]) {
			++l, o[l] = (1LL << i);
			L(j, 0, m - 1) if(f[j] >> i & 1) o[l] |= (1LL << j);
		}
		dfs(1, 0);
		L(a, 0, m) {
			L(t, 0, m) {
				int sum = 0;
				L(i, 0, t) {
					if(i & 1) (sum += mod - (ll) C(t, i) * C(m - t, a - i) % mod) %= mod;
					else (sum += (ll) C(t, i) * C(m - t, a - i) % mod) %= mod;
				}
				(ns[a] += (ll) sum * cnt[t] % mod) %= mod;
			}
		}
	}
	L(i, 0, m) cout << (ll) ns[i] * all % mod << " ";
	cout << "\n";
	return 0;
}