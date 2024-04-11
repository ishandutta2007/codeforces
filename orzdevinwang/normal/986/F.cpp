#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7;

mt19937_64 orz(233);

namespace PR {
	const int testp[8] = {2, 3, 5, 7, 13, 19, 61, 233};
	ll Mul(ll x, ll y, ll mod) {
		ll sav = x * y - (ll) ((long double) x * y / mod + 0.1) * mod;
		return sav < 0 ? sav + mod : sav;
	}
	ll qpow(ll x, ll y, ll mod) {
		ll res = 1;
		for(; y; x = Mul(x, x, mod), y >>= 1) if(y & 1) res = Mul(res, x, mod);
		return res;
	}
	bool MR(ll x) {
		if(x <= 2) return x == 2;
		if(x <= testp[7]) {
			L(i, 2, sqrt(x)) if(x % i == 0) return 0;
			return 1;
		}
		int k, j; 
		ll a;
		for(a = x - 1, k = 0; ! (a & 1); k ++) a >>= 1;
		L(i, 0, 7) {
			ll v = qpow(testp[i], a, x);
			if(v == 1 || v == x - 1) continue;
			for(j = 0; j < k; j++) {
				v = Mul(v, v, x);
				if(v == x - 1) break;
			}
			if(j == k) return 0;
		}
		return 1;
	}
	int tot, total;
	ll seed, mul, f[N], ans[N];
	ll pr(ll x) {
		total = 0;
		seed = orz() % (x - 1) + 1, mul = 1; 
		ll val1 = seed, val2 = seed;
		while(1) {
			val1 = (Mul(val1, val1, x) + seed) % x;
			val2 = (Mul(val2, val2, x) + seed) % x;
			val2 = (Mul(val2, val2, x) + seed) % x;
			f[++total] = abs(val1 - val2);
			mul = Mul(mul, f[total], x);
			if(total == 127) {
				if(__gcd(mul, x) > 1) {
					L(i, 1, total) {
						ll sav = __gcd(f[i], x);
						if(sav > 1) return sav;
					}
					return x;
				}
				total = 0;
			}
		}
	}
	void esolve(ll x) {
		if(x < 2) return;
		if(MR(x)) return ans[++tot] = x, void();
		ll sav = pr(x);
		while(sav == x) sav = pr(x);
		esolve(x / sav), esolve(sav);
	}
	void solve(ll x) {
		tot = 0;
		L(i, 2, 100) while(x % i == 0) ans[++tot] = i, x /= i;
		esolve(x), sort(ans + 1, ans + tot + 1);
	}
} ;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) return x = 1, y = 0, void();
	ll t = a / b; exgcd(b, a % b, y, x), y -= t * x;
}

ll arr[N], tp, xn[N];
map < ll, vi > mp;
int n;

vector < pair < int, ll > > e[N];
ll dis[N];
bool vis[N];
void dij(int p) {
	priority_queue < pair < ll, int > > q;
	me(dis, 0x3f), me(vis, 0);
	dis[0] = 0, q.push(make_pair(0, 0));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto t : e[u]) {
			int v = t.first;
			ll w = t.second;
			if(dis[v] > dis[u] + w) 
				dis[v] = dis[u] + w, q.push(make_pair(-dis[v], v));
		}
	}
}
bool ns[N]; 

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		ll w;
		cin >> xn[i] >> w;
		if(w > 1) mp[w].emplace_back(i);
	}
	for(auto u : mp) {
		ll k = u.first;
		vi S = u.second;
		PR :: solve(k);
		tp = PR :: tot;
		L(i, 1, tp) arr[i] = PR :: ans[i];
		if(tp == 1) {
			for(auto u : S) 
				ns[u] = xn[u] % arr[1] == 0;
		} else if(tp == 2) {
			ll g = __gcd(arr[1], arr[2]);
			arr[1] /= g, arr[2] /= g;
			ll x = arr[1], y = arr[2], a, b;
			exgcd(x, y, a, b);
			if(b < 0) b += x, a -= y;
//			assert(b >= 0);
//			assert(a * x + b * y == 1); 
			for(auto u : S) {
				ll n = xn[u];
				if(n % g) continue;
				n /= g;
				__int128 A = a, B = b;
				A *= n, B *= n;
				__int128 C = B / x;
				if(A + C * y >= 0) ns[u] = true;
			}
		} else {
			L(i, 0, arr[1] - 1) e[i].clear();
			L(i, 2, tp) 
				L(j, 0, arr[1] - 1) 
					e[j].emplace_back(make_pair((j + arr[i]) % arr[1], arr[i]));
			dij(arr[1]);
			for(auto u : S) {
				ll n = xn[u];
				ns[u] = dis[n % arr[1]] <= n;
			}
		}
	}
	L(i, 1, n) {
		if(ns[i]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}