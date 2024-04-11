#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

mt19937_64 orz(time(0) ^ clock());
int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
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
const int hash_cnt = 2, hash_mod[hash_cnt] = {1019260817, getP()}, 
	hash_G = 19491001; // rem
const int hash_N = 2e5 + 7;
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
		L(i, 0, hash_cnt - 1) ret.a[i] = (ll) a.a[i] * 
			qpow(b.a[i], hash_mod[i] - 2, hash_mod[i]) % hash_mod[i];
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

struct RMQ {
	int a[N], mn[20][N], lg[N];
	void init (int n) {
		L(i, 2, n) lg[i] = lg[i >> 1] + 1;
		L(i, 1, n) mn[0][i] = i;
		L(i, 1, 19)
			L(j, 1, n - (1 << i) + 1) 
				mn[i][j] = a[mn[i - 1][j]] < a[mn[i - 1][j + (1 << (i - 1))]] 
					? mn[i - 1][j] : mn[i - 1][j + (1 << (i - 1))];
	}
	int queryp (int l, int r) {
		int p = lg[r - l + 1];
		return a[mn[p][l]] > a[mn[p][r - (1 << p) + 1]] ? mn[p][r - (1 << p) + 1] : mn[p][l];
	}
	int query (int l, int r) { 
		return a[queryp (l, r)]; 
	}
} ;


struct SA {
	RMQ a;
	int n, m, cnt[N], ord[N], r[N], h[N], rk[N];
	char s[N];
	void solve() {
		m = 26;
		L(i, 1, n) rk[i] = s[i] - 'a' + 1, cnt[rk[i]] += 1;
		L(i, 1, m) cnt[i] += cnt[i - 1];
		R(i, n, 1) ord[cnt[rk[i]]--] = i; 
			
		for(int k = 1; k <= n; k <<= 1) {			
			int all = 0;
			L(i, n - k + 1, n) r[++all] = i;
			L(i, 1, n) if(ord[i] > k) r[++all] = ord[i] - k;
			
			
			L(i, 1, m) cnt[i] = 0;
			L(i, 1, n) cnt[rk[i]] += 1; 
			L(i, 1, m) cnt[i] += cnt[i - 1];
			R(i, n, 1) ord[cnt[rk[r[i]]]--] = r[i];
			swap(r, rk);
			rk[ord[1]] = all = 1;
			L(i, 2, n) 
				rk[ord[i]] = all = all + 
					(r[ord[i]] != r[ord[i - 1]] || r[ord[i] + k] != r[ord[i - 1] + k]);
			
			m = all;
			if(n == m) break ;
		}
//		L(i, 1, n) cout << ord[i] << ' ';
//		cout << '\n';
	}
	void height() {
		int k = 0;
		L(i, 1, n) {
			if(rk[i] == 1) {
				h[i] = k = 0;
				continue ;
			}
			if(k) k -= 1;
			int j = ord[rk[i] - 1];
			while(k + i <= n && k + j <= n && s[k + i] == s[k + j]) ++k;
			h[i] = k;
		}
	} 
	void init() {
		solve();
		height();
		L(i, 1, n) a.a[rk[i]] = h[i];
		a.init(n);
	}
	inline int lcp(int x, int y) {
		if(x == y) return n - x + 1;
		x = rk[x], y = rk[y];
		if(x > y) swap(x, y);
		return a.query(x + 1, y);
	}
} ma, mb;

struct godly {
	int n, f[N], w[N];
	inline int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}
	void init(int pn) {
		n = pn;
		L(i, 1, n + 1) f[i] = i, w[i] = 0;
	}
	void cov(int l, int r, int v) {
		for(int x = find(l); x <= r; x = find(x)) 
			f[x] = x + 1, w[x] = v;
	}
} X, Y;

int n, q, B, tB;
char s[N];

hint pre[N];
hint get(int l, int r) {
	return (pre[r] - pre[l - 1]).divk(l);
}

vi fc[N];

int nxt[N], lst[N]; 

bool Border(int l, int r) {
	int len = r - l + 1;
	L(j, 1, min(B, len - 1)) 
		if(get(l, l + j - 1) == get(r - j + 1, r))
			return true;
	int Rk = ma.rk[l], mn = 1e9;
	R(i, Rk - 1, max(Rk - tB + 1, 1)) {
		int p = ma.ord[i];
		mn = min(mn, ma.h[ma.ord[i + 1]]);
		if(l <= p && p <= r && mn >= r - p + 1) return true;
	}
	mn = 1e9;
	L(i, Rk + 1, min(Rk + tB - 1, n)) {
		int p = ma.ord[i];
		mn = min(mn, ma.h[p]);
		if(l <= p && p <= r && mn >= r - p + 1) return true;
	}
	return false;
}

RMQ qwq;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	hash_init();
	cin >> n >> (s + 1) >> q;
	B = sqrt(n); 
	tB = (n + B - 1) / B;
	L(i, 1, n) pre[i] = pre[i - 1] + ((hint) (s[i] - 'a' + 1)).mulk(i);
	
	L(i, 2, n) if(!sz(fc[i])) L(j, 1, n / i) fc[i * j].emplace_back(i);
	
	ma.n = n, mb.n = n;
	L(i, 1, n) ma.s[i] = mb.s[n - i + 1] = s[i];
	
	
	ma.init();
	mb.init();
//	L(i, 1, n) cout << ma.ord[i] << ' ';
//	cout << '\n';
	
	L(i, 1, n) nxt[i] = n + 1, lst[i] = 0;
	L(i, 1, n) L(j, i + 1, n) if(s[i] == s[j]) {
		nxt[i] = j, lst[j] = i;
		break ;
	}
//	L(i, 1, n) cout << nxt[i] << ' ';
//	cout << '\n';
	
	X.init(n);
	Y.init(n); 
	
	L(len, 1, n) {
		for(int i = len; i + len <= n; i += len) {
			int u = i, v = i + len;
			int la = mb.lcp(n - u + 1, n - v + 1), lb = ma.lcp(u, v);
			la = min(la, len);
			lb = min(lb, len);
			if(la + lb > len)  
				X.cov(u - la + 1, u - (len - lb), len), 
				Y.cov(v + (len - la), v + lb - 1, len);
		}
	}
	
	L(i, 1, n) if(!X.w[i]) X.w[i] = 1e9;
	L(i, 1, n) if(!Y.w[i]) Y.w[i] = 1e9;
		
	L(i, 1, n) qwq.a[i] = i + X.w[i] * 2 - 1;
	qwq.init(n);
	
	L(i, 1, q) {
		int l, r;
		
		cin >> l >> r;
		int len = r - l + 1;
		
		bool ok = true;
		
		if(r - l + 1 <= 26) {
			L(i, l, r) if(nxt[i] <= r) ok = false;
			if(ok) {
				cout << -1 << '\n';
				continue;
			}
		} else ok = false;
		
		for(const int &t : fc[len]) {
			int z = len / t;
			if(get(l, r - z) == get(l + z, r)) 
				ok = true;
		} 
		
		if(ok) {
			cout << 1 << '\n';
			continue ;
		}
		
		if(Border(l, r)) {
			cout << 2 << '\n';
			continue ;
		}
		
		if(l + X.w[l] * 2 - 1 <= r || r - Y.w[r] * 2 + 1 >= l) {
			cout << 2 << '\n';
			continue ;
		} 
		
		if(nxt[l] <= r || lst[r] >= l) {
			cout << 3 << '\n';
			continue ;
		}
		
		if(qwq.query(l, r) <= r) {
			cout << 3 << '\n';
			continue ;
		}
		
		cout << 4 << '\n'; 
	}
	return 0;
} 

/*
11
abababaabab
0


1
1 11
*/