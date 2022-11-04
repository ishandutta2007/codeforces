#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1000000000;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 250010, maxT = 200000, A = 179, K = 450;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	et %= mod;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "impossible\n";
	exit(0);
}
vector<vector<int>>gg;
ll dp[maxN];
ll dep[maxN];
ll f[maxN], g[maxN];
void build() {
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
//void dfs(int v, int p = -1) {
//	ll vl = 1;
//	int cnt = 0;
//	for (auto x : gg[v]) {
//		if (x == p)
//			continue;
//		++cnt;
//		dfs(x, v);
//		dep[v] += dep[x] + 1;
//		vl = (vl * c(dep[v], dep[x] + 1) % mod * dp[x] % mod);
//	}
//	// !!!
//	vl = vl * (dep[v] + 1 - cnt) % mod;
//
//
//	dp[v] = vl;
//}
ll cntt[maxN];
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;
void fft(vector<int>& a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1 : root;
		for (int i = len; i < root_pw; i <<= 1)
			wlen = int(wlen * 1ll * wlen % mod);
		for (int i = 0; i < n; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; ++j) {
				int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
				w = int(w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = bp(n, mod - 2);//   n
		for (int i = 0; i < n; ++i)
			a[i] = int(a[i] * 1ll * nrev % mod);
	}
}
vector<int>mult(const vector<int>& a, const vector<int>& b) {
	int n = a.size(), m = b.size();
	int sz = 1;
	while (sz < n + m)sz <<= 1;
	vector<int>fa(sz), fb(sz);
	for (int i = 0; i < n; ++i)fa[i] = a[i];
	for (int i = 0; i < m; ++i)fb[i] = b[i];
	fft(fa, false);
	fft(fb, false);
	for (size_t i = 0; i < sz; ++i)
		fa[i] = (ll)fa[i] * fb[i] % mod;
	fft(fa, true);
	vector<int>ans(n + m);
	for (int i = 0; i < n + m; ++i) {
		ans[i] = fa[i];
	}
	return ans;
}
vector<int>cld;
vector<int>rec(int l, int r) {
	if (l + 1 == r) {
		vector<int>tmp(2, 1);
		tmp[1] = cld[l];
		return tmp;
	}
	int m = (l + r) / 2;
	return mult(rec(l, m), rec(m, r));
}
void solve() {
	build();
	int n;
	cin >> n;
	gg.assign(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		++cntt[x];
		++cntt[y];
	}
	for (int i = 1; i < n; ++i)--cntt[i];
	sort(cntt, cntt + n);
	for (int i = 0; i < n; ++i) {
		if (cntt[i] == 0)continue;
		cld.push_back(cntt[i]);
	}
	vector<int>tmp = rec(0, cld.size());
	ll ans = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		if (i % 2 == 0) {
			ans = (ans + f[n - i] * tmp[i]) % mod;
		}
		else 	
			ans = (ans - f[n - i] * tmp[i] % mod + mod) % mod;
	}
	cout << ans << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
2 5
5 6
6 7
5
4 3 2 5 6 7
1
*/