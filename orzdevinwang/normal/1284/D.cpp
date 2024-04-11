#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
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
const int hash_cnt = 5, hash_mod[hash_cnt] = {998244353, 1019260817, 1000000007, 1000000009, getP()}, 
	hash_G = 19491001; // rem
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
int n;
struct dt {
	int l[N], r[N], arr[N], atot;
	hint ns[N];
	hint A[N], B[N];
	void solve () {
		L(i, 1, n) arr[++atot] = l[i], arr[++atot] = r[i];
		sort(arr + 1, arr + atot + 1);
		atot = unique(arr + 1, arr + atot + 1) - arr - 1;
		L(i, 1, n) 
			l[i] = lower_bound (arr + 1, arr + atot + 1, l[i]) - arr, 
			r[i] = lower_bound (arr + 1, arr + atot + 1, r[i]) - arr, 
			A[r[i]] = A[r[i]] + ((hint) 1).mulk(i), 
			B[l[i]] = B[l[i]] + ((hint) 1).mulk(i);
		L(i, 1, atot) 
			A[i] = A[i - 1] + A[i];
		R(i, atot, 1) 
			B[i] = B[i + 1] + B[i];
		L(i, 1, n) 
			ns[i] = A[l[i] - 1] + B[r[i] + 1];
	}
} a, b;
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	hash_init();
	L(i, 1, n) cin >> a.l[i] >> a.r[i] >> b.l[i] >> b.r[i];
	a.solve (), b.solve ();
	L(i, 1, n) if(a.ns[i] != b.ns[i]) return cout << "NO\n", 0;
	cout << "YES\n";
	return 0;
}