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
int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 210, maxT = 510, A = 179, K = 450;
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
ll fact[maxN], inv[maxN], p2[maxN * maxN];
ll cnt_bad[maxN][maxN];
ll cnt_distinct[maxN][maxN];
ll total[maxN][maxN];
void build() {
	fact[0] = inv[0] = p2[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = bp(fact[i], mod - 2);
	}
	for (int i = 1; i < maxN * maxN; ++i)
		p2[i] = p2[i - 1] * 2 % mod;
}
ll C(int n, int k) {
	return fact[n] * inv[k] % mod * inv[n - k] % mod;
}
ll sub(ll strt, ll cnt) {
	ll res = 1;
	for (int i = 0; i < cnt; ++i)res = (res * (strt - i)) % mod;
	return res;
}
void solve() {
	int n, k;
	cin >> n >> k >> mod;
	build();
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			total[i][j] = p2[i * j];
			cnt_distinct[i][j] = sub(p2[j] - 1, i);
			for (int l = 0; l < j; ++l) {
				cnt_distinct[i][j] = (cnt_distinct[i][j] -
					C(j, l) * cnt_distinct[i][l] % mod + mod) % mod;
				total[i][j] = (total[i][j] -
					C(j, l) * total[i][l] % mod + mod) % mod;
			}
		}
	}
	ll ans = 0;
	total[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int a = 0; a < i; ++a) {
				for (int b = 0; b < j; ++b) {
					if (i == n && i % 2 && n == a + 1)
						continue;
					ll bad = (total[a][b] -
						cnt_bad[a][b] + mod) % mod;
					bad = (bad * cnt_distinct[i - a][j - b] % mod
						* C(i, a) % mod * C(j, b)) % mod;

					cnt_bad[i][j] = (cnt_bad[i][j] + bad * p2[(i - a) * b]) % mod;
				}
			}
		}
	}
	for (int i = 0; i <= k; ++i) {
		ans = (ans + C(k, i) * (total[n][i] - cnt_bad[n][i] + mod)) % mod;
	}
	cout << ans << endl;
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