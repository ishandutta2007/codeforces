#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
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
const int hash_cnt = 3, hash_mod[hash_cnt] = {998244353, 1019260817, getP()}, hash_G = 19491001; // rem
const int hash_N = 5e5 + 7;
int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
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
const int N = 1 << 19;
int n, h[N], las[N], su[N], fa[N], mp[N << 1], len[N];
char s[N];
int to[20][N];
hint up[20][N];
void upd (int x) {
	len[x] = len[fa[x] + 1] + 1;
	to[0][x] = fa[x] + 1, up[0][x] = hint (s[fa[x]]);
	L(i, 1, 19) up[i][x] = up[i - 1][x] + up[i - 1][to[i - 1][x]].mulk(1 << (i - 1)), to[i][x] = to[i - 1][to[i - 1][x]];
}
bool check (int x, int y) { // Is x < y ? 
//	cout << x << ' ' << y << '\n';
	R(i, 19, 0) if((1 << i) <= min(len[x], len[y]) && up[i][x] == up[i][y]) x = to[i][x], y = to[i][y];
	if(!len[y]) return false;
	if(!len[x]) return true;
	return up[0][x] < up[0][y];
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1), n = strlen(s + 1);
	hash_init();
	mp[N] = n + 1, su[n + 1] = N;
	R(i, n, 1) {
		su[i] = su[i + 1] + (s[i] == '(' ? -1 : 1), fa[i] = i, upd (i);
		if(s[i] == '(' && mp[su[i]] && check(mp[su[i]], i)) fa[i] = fa[mp[su[i]]], upd (i);
		mp[su[i]] = i;
	}
	for (int u = fa[1]; u && u <= n; u = fa[u + 1]) cout << s[u];
	return 0;
}