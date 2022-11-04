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
const int mod = 1000000007;
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 1000100, maxT = 1000000, A = 179, mid = 150;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
//void bld(int n) {
//	vector<ll>dp_same(n + 1, 0);
//	vector<ll>dp_diff(n + 1, 0);
//	vector<ll>ct_same(n + 1, 0);
//	vector<ll>ct_diff(n + 1, 0);
//	dp_same[1] = 1;
//	ct_same[1] = 1;
//	ct_diff[0] = 1;
//	ct_diff[1] = 1;
//	for (int i = 2; i <= n; ++i) {
//		set<int>s_s, s_d;
//		for (int l1 = 0; l1 < i; ++l1) {
//			int l2 = i - l1 - 1;
//			s_s.insert(dp_diff[l1] ^ dp_diff[l2]);
//			if (l1 && l2) {
//				s_s.insert(dp_same[l1] ^ dp_same[l2]);
//			}
//			if (l1) {
//				s_d.insert(dp_same[l1] ^ dp_diff[l2]);
//			}
//			if (l2) {
//				s_d.insert(dp_diff[l1] ^ dp_same[l2]);
//			}
//		}
//		while (s_s.count(dp_same[i]))
//			++dp_same[i];
//		while (s_d.count(dp_diff[i]))
//			++dp_diff[i];
//		for (int l1 = 0; l1 < i; ++l1) {
//			int l2 = i - l1 - 1;
//			if ((dp_diff[l1] ^ dp_diff[l2]) == 0) {
//				ct_same[i] += ct_diff[l1] * ct_diff[l2];
//			}
//			if (l1 && l2 && (dp_same[l1] ^ dp_same[l2]) == 0) {
//				ct_same[i] += ct_same[l1] * ct_same[l2];
//			}
//			if (l1 && (dp_same[l1] ^ dp_diff[l2]) != 0) {
//				ct_diff[i] += ct_same[l1] * ct_diff[l2];
//			}
//			if (l2 && (dp_diff[l1] ^ dp_same[l2]) != 0) {
//				ct_diff[i] += ct_diff[l1] * ct_same[l2];
//			}
//		}
//	}
//
//
//
//	for (int i = 0; i <= n; ++i) {
//		cout << i << "\n";
//		cout << "same: " << dp_same[i] << " " << ct_same[i] << "\n";
//		cout << "diff: " << dp_diff[i] << " " << ct_diff[i] << "\n";
//		cout << "-----------\n";
//	}
//}
ll f[maxN], g[maxN];
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	int n;
	cin >> n;
	//bld(n);
	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
	}
	g[maxN - 1] = bp(f[maxN - 1], mod - 2);
	for (int i = maxN - 2; i >= 0; --i) {
		g[i] = g[i + 1] * (i + 1) % mod;
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		if ((n - i) % 2 == 1)continue;
		if ((i + (n - i) / 2) % 2 == 1)continue;
		int cnt = i + (n - i) / 2;
		ll tmp = c(cnt, i);
		tmp = (tmp * 2) % mod;
		tmp = (tmp * n % mod * f[cnt - 1]) % mod;
		ans = (ans + tmp) % mod;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}