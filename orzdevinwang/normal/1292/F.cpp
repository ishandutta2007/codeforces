#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 64, mod = 1e9 + 7;

int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

map < ll, int > dp[N]; 

int n, a[N], m, ns;
ll e[N];
bool vis[N]; 

int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if(u != v) f[u] = v;
}

int solve(ll msk) {
	vi S;
	L(i, 1, m) if(msk >> i & 1) S.emplace_back(i);
	int x = sz(S);
	
	L(i, 1, x) dp[i].clear();
	L(i, 1, m) if(msk >> i & 1) dp[1][(1LL << i) | e[i]] += 1;
	L(i, 1, x - 1) {
		for(auto u : dp[i]) {
			ll M = u.first, rx = 0;
			for(const int &x : S) if(M >> x & 1) {
				if((e[x] & M) == e[x]) rx += 1;
				else (dp[i + 1][M | e[x]] += u.second) %= mod;
			} 
			rx -= i;
			assert(rx >= 0);
			if(rx) (dp[i + 1][M] += (ll) u.second * rx % mod) %= mod;
		}
	}
	
	int ns = 0;
	for(auto u : dp[x]) 
		(ns += u.second) %= mod;
	return (ll) ns * ifac[x - 1] % mod;
}

ll msk[N];
bool go[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	init(n);
	
	L(i, 1, n) cin >> a[i];
//	L(i, 1, n) a[i] = i;
	L(i, 1, n) vis[a[i]] = true, m = max(m, a[i]);
	
	L(i, 1, m) if(vis[i]) f[i] = i;
	L(i, 1, m) 
		L(j, 1, m) if(vis[i] && vis[j] && i != j) {
			int w = __gcd(i, j); 
			L(k, 1, w) if(w % k == 0 && vis[k] && k != i && k != j) 
				e[i] |= 1LL << j, merge(i, j), go[i] = true;
		}
	
	
	int ret = 1, cnt = 0;
	L(i, 1, m) if(go[i]) msk[find(i)] |= 1LL << i, ++cnt; 
	L(i, 1, m) if(msk[i]) ret = (ll) ret * solve(msk[i]) % mod, cnt -= 1; 
	
	cout << (ll) ret * fac[cnt] % mod << '\n';
	return 0;
}