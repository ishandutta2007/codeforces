#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 2e3 + 7;
const int M = 2e4 + 7;
const int mod = 1073741824;
bool Prime[N];
int tot, P[N >> 2], mu[N];
void xxs() {
	mu[1] = 1;
	L(i, 2, 2e3)  {
		if(!Prime[i]) P[++tot] = i, mu[i] = -1;
		for(int j = 1; P[j] * i <= 2e3 && j <= tot; j++) {
			Prime[P[j] * i] = 1;
			if(i % P[j] == 0) {
				mu[P[j] * i] = 0;
				break;
			}
			mu[P[j] * i] = -mu[i];
		}
	}
} 
vector<int> ve[N];
unordered_map<int, bool> mp[N];
int T, Max, A, B, C, ans, p[N];
int sA[M], sB[M], sC[M], cnt, deg[N];
int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }
ll lcm(int x, int y) { return 1ll * x / gcd(x, y) * y; }
int ta, tb, tc, sum;
void dh(int a, int b, int c) {
	(sum += 1ll * p[a / ta] * p[b / tb] % mod * p[c / tc] % mod) %= mod;
}
void get(int a, int b, int c) {
	sum = 0;
	if(a == b && b == c) dh(A, B, C);
	else if(a == b || b == c || c == a) dh(A, B, C), dh(C, A, B), dh(B, C, A);
	else dh(A, B, C), dh(A, C, B), dh(B, A, C), dh(B, C, A), dh(C, A, B), dh(C, B, A);
	(ans += (mu[a] * mu[b] * mu[c] * sum % mod + mod) % mod) %= mod;
}
int vis[N];
void js() {
	L(i, 1, cnt) {
		int &u = sA[i], &v = sB[i];
		if(deg[u] > deg[v]) swap(u, v);
		else if(deg[u] == deg[v] && u > v) swap(u, v);
		ve[u].push_back(i);
	}
	L(i, 1, Max) {
		for(int j : ve[i]) vis[sB[j]] = sC[j];
		for(int j : ve[i]) for(int k : ve[sB[j]]) 
			if(vis[sB[k]]) ta = vis[sB[k]], tb = sC[j], tc = sC[k], get(i, sB[j], sB[k]);
		for(int j : ve[i]) vis[sB[j]] = 0;
	}
}
void getans(int x) {
	for(int l = 1, r; l <= x; l = r + 1) {
		r = (x / (x / l));
		(p[x] += 1ll * (r - l + 1) * (x / l) % mod) %= mod;
	}
}
int main() {
	xxs();
	L(i, 1, 2e3) getans(i);
	scanf("%d%d%d", &A, &B, &C);
	ans = cnt = 0;
	Max = max(max(A, B), C);
	R(i, Max, 1) for(int j = i; j <= Max; j += i) {
			if(!mu[j]) continue;
			for(int k = j; k <= 1ll * Max * i / j; k += i) {
				if(!mu[k]) continue;
				if(!mp[j][k]) ++cnt, sA[cnt] = j, sB[cnt] = k, sC[cnt] = j / i * k, deg[j] ++, deg[k] ++, mp[j][k] = 1;
			}
		}
	js();
	L(i, 1, Max) ve[i].clear(), mp[i].clear(), deg[i] = 0;
	printf("%d\n", (ans + mod) % mod);
	return 0;
}