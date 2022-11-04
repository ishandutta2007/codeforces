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
const ll INF = 1e18 + 100;
//const int mod = 1000000007;
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 200010, maxT = 519, A = 179, mid = 350, K = 500;
mt19937 mt_rand(time(0));
const int mod = 998244353;
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "No\n";
	exit(0);
}
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
int mx_sz;
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
	vector<int>ans(min(n + m - 1, mx_sz));
	for (int i = 0; i < ans.size(); ++i) {
		ans[i] = fa[i];
	}
	return ans;
}
vector<ll>vls;
vector<int> rec(int l, int r) {
	vector<vector<int>>dp(vls.size() + 1, vector<int>(mx_sz));
	dp[0][0] = 1;
	for (int i = 0; i < vls.size(); ++i) {
		for (int j = 0; j < mx_sz; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			if (j + vls[i] + 1 < mx_sz) {
				dp[i + 1][j + vls[i] + 1] = (dp[i + 1][j + vls[i] + 1] + mod - dp[i][j]) % mod;
			}
		}
		for (int j = 1; j < mx_sz; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i + 1][j - 1]) % mod;
		}
	}
	return dp.back();
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>a(n);
	for (auto& x : a)
		cin >> x.first >> x.second;
	vector<int>dp(m + 1);
	for (int i = 1; i <= m; ++i) {
		vector<pair<int, int>>b = a;
		int mm = m / i;
		bool zr = 0;
		vls.clear();
		for (auto& x : b) {
			x.first = (x.first + i - 1) / i;
			x.second /= i;
			if (x.second < x.first)
				zr = 1;
			vls.push_back(x.second - x.first);
			mm -= x.first;
		}
		if (zr || mm < 0)
			continue;
		mx_sz = mm + 1;
		vector<int>bb = rec(0, n - 1);
		for (int j = 0; j < min((int)bb.size(),mx_sz); ++j) {
			dp[i] = (dp[i] + bb[j]) % mod;
		}
	}
	for (int i = m; i > 0; --i) {
		for (int j = 2 * i; j <= m; j += i) {
			dp[i] = (dp[i] - dp[j] + mod) % mod;
		}
	}
	cout << dp[1] << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
2 2
1 1
1 1 2 1
2 1 2
*/