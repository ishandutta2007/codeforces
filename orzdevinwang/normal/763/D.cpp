#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
mt19937_64 orz(time(0) ^ clock());
int getP () {
	int u = orz() % 1000000000 + 11; 
	while (1) {
		bool ok = true;
		L(i, 2, sqrt (u)) if(u % i == 0) {
			ok = false;
			break ;
		}
		if(ok) return u;
		u = orz() % 1000000000 + 11; 
	}
}
const int hash_cnt = 5, hash_mod[hash_cnt] = {998244353, 1019260817, 1000000007, 1000000009, getP()}, hash_G = 19491001; // rem
const int hash_N = 3e5 + 7;
int hash_pw[hash_N][hash_cnt], hash_ipw[hash_N][hash_cnt];
void hash_init () {
	L(i, 0, hash_cnt - 1) 
		hash_ipw[1][i] = qpow (hash_G, hash_mod[i] - 2, hash_mod[i]), 
		hash_pw[1][i] = hash_G % hash_mod[i], hash_pw[0][i] = hash_ipw[0][i] = 1;
	L(i, 2, hash_N - 1) L(j, 0, hash_cnt - 1) {
		hash_pw[i][j] = (ll) hash_pw[i - 1][j] * hash_pw[1][j] % hash_mod[j];	
		hash_ipw[i][j] = (ll) hash_ipw[i - 1][j] * hash_ipw[1][j] % hash_mod[j];
	}
}
struct hint {
	int a[hash_cnt];
	hint (ll x = 0) {
		L(i, 0, hash_cnt - 1) a[i] = x % hash_mod[i];
	}
	friend hint operator + (const hint &a, const hint &b) {
		hint ret ;
		L(i, 0, hash_cnt - 1) ret.a[i] = (a.a[i] + b.a[i]) % hash_mod[i];
		return ret;
	}
	friend hint operator - (const hint &a, const hint &b) {
		hint ret ;
		L(i, 0, hash_cnt - 1) ret.a[i] = (a.a[i] + hash_mod[i] - b.a[i]) % hash_mod[i];
		return ret;
	}
	friend hint operator * (const hint &a, const hint &b) {
		hint ret ;
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a.a[i] * b.a[i] % hash_mod[i];
		return ret;
	}
	friend hint operator * (const hint &a, int b) {
		hint ret ;
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a.a[i] * b % hash_mod[i];
		return ret;
	}
	hint mulk (int x) {
		hint ret;
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a[i] * hash_pw[x][i] % hash_mod[i];
		return ret;
	}
	hint divk (int x) {
		hint ret;
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a[i] * hash_ipw[x][i] % hash_mod[i];
		return ret;
	}
	friend hint operator / (const hint &a, const hint &b) {
		hint ret ;
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a.a[i] * qpow(b.a[i], hash_mod[i] - 2, hash_mod[i]) % hash_mod[i];
		return ret;
	}
	friend bool operator == (hint a, hint b) {
		L(i, 0, hash_cnt - 1) if(a.a[i] != b.a[i]) return false;
		return true;
	}
	friend bool operator < (hint a, hint b) {
		L(i, 0, hash_cnt - 1) if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
		return false;
	}
	friend bool operator != (hint a, hint b) {
		L(i, 0, hash_cnt - 1) if(a.a[i] != b.a[i]) return true;
		return false;
	}
};

const int N = 3e5 + 7;
int n, m;
vi e[N];
int siz[N], rt, rtm;
hint has[N]; 
void findrt(int x, int fa) {
	siz[x] = 1;
	int maxn = 0;
	for (const int &v : e[x]) if(v != fa) findrt(v, x), siz[x] += siz[v], maxn = max(maxn, siz[v]);
	maxn = max(maxn, n - siz[x]);
	if(maxn < rtm) rtm = maxn, rt = x;
}
int ns, fns, ret;
map < hint, int > mp;
void dfs(int x, int fa) {
	has[x] = hint (1), siz[x] = 1;
	for (const int &v : e[x]) if(v != fa) dfs(v, x);
	vector < pair < hint, int > > vc;
	for (const int &v : e[x]) if(v != fa) vc.push_back({has[v], siz[v]});
	sort(vc.begin(), vc.end());
	for (auto u : vc) has[x] = has[x] + u.first.mulk(siz[x]), siz[x] += u.second + 1;
	if(!mp[has[x]]) ret += 1;
	mp[has[x]] += 1;
}
void dfs2 (int x, int fa) {
	mp[has[x]] -= 1;
	int o = mp[has[x]];
	if(o) ret += 1;
	if(ns < ret) ns = ret, fns = x;
	for (const int &v : e[x]) if(v != fa) dfs2 (v, x);
	if(o) ret -= 1;
	mp[has[x]] += 1;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	hash_init();
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rtm = 1e9, findrt (1, 0), dfs (rt, 0);
	dfs2 (rt, 0);
//	cout << "ns = " << ns << '\n';
	cout << fns << '\n';
	return 0;
}