#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7; 
int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

// 
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
const int hash_cnt = 5, hash_mod[hash_cnt] = {998244353, 1019260817, 1000000007, 1000000009, getP()}, hash_G = 10; 
const int hash_N = 5e5 + 7;
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
// 

hint vx;
char s[N], r[N];
int n, m;
hint pre[N];
hint get (int l, int r) { return (pre[r] - pre[l - 1]).divk(n - r); } 
template < int N > struct zfun {
	char s[N];
	int z[N];
	void work (int n) {
		L(i, 1, n) z[i] = 0;
		int p = 1;
		L(i, 2, n) {
			if(z[p] + p >= i) z[i] = min(z[p] + p - i, z[i - p + 1]);
			while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++ z[i];
			if(i + z[i] > p + z[p]) p = i;
		}
		z[1] = n;
	}
};
zfun < N > z;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	hash_init();
	cin >> (s + 1) >> (r + 1);
	n = strlen(s + 1);
	m = strlen(r + 1);
	L(i, 1, m) z.s[i] = r[i];
	L(i, 1, n) z.s[i + m] = s[i];
	z.work(n + m);
	L(i, 1, n) pre[i] = pre[i - 1] + ((hint) (s[i] - '0')).mulk(n - i);
	L(i, 1, m) vx = vx + ((hint) (r[i] - '0')).mulk(m - i);
	
	L(i, 1, n - m + 1) {
		int lcp = z.z[i + m], len = m - lcp;
		if(len <= 0) continue;
		if(i + m + len - 1 <= n) {
			if(get(i, i + m - 1) + get(i + m, i + m + len - 1) == vx) 
				return cout << i << ' ' << i + m - 1 << '\n' << i + m << ' ' << i + m + len - 1 << '\n', 0;
		}
		if(i > len) {
			if(get(i, i + m - 1) + get(i - len, i - 1) == vx) 
				return cout << i - len << ' ' << i - 1 << '\n' << i << ' ' << i + m - 1 << '\n' , 0;
		}
		len -= 1;
		if(len <= 0) continue;
		if(i + m + len - 1 <= n) {
			if(get(i, i + m - 1) + get(i + m, i + m + len - 1) == vx) 
				return cout << i << ' ' << i + m - 1 << '\n' << i + m << ' ' << i + m + len - 1 << '\n', 0;
		}
		if(i > len) {
			if(get(i, i + m - 1) + get(i - len, i - 1) == vx) 
				return cout << i - len << ' ' << i - 1 << '\n' << i << ' ' << i + m - 1 << '\n' , 0;
		}
	}
	
	if(m >= 1) {
		L(i, 1, n - (m - 1) * 2 + 1) 
		if (get(i, i + m - 2) + get(i + m - 1, i + m * 2 - 3) == vx) 
			return cout << i << ' ' << i + m - 2 << '\n' << i + m - 1 << ' ' << i + m * 2 - 3 << '\n', 0;	
	}
	return 0;
}