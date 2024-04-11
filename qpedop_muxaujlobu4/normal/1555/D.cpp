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
const int mod = 1000000007;
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 10010, maxT = 10010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
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
	cout << "-1\n";
	exit(0);
}
void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<ll>>a(3, vector<ll>(n + 1));
	vector<vector<ll>>b(3, vector<ll>(n + 1));
	vector<vector<ll>>c(3, vector<ll>(n + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			a[j][i + 1] = a[j][i];
			b[j][i + 1] = b[j][i];
			c[j][i + 1] = c[j][i];
		}
		if (s[i] == 'a') {
			++a[i % 3][i + 1];
		}
		if (s[i] == 'b') {
			++b[i % 3][i + 1];
		}
		if (s[i] == 'c') {
			++c[i % 3][i + 1];
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;
		vector<ll>ta(3), tb(3), tc(3);
		ll ans = INF;
		for (int j = 0; j < 3; ++j) {
			ta[j] = a[j][r] - a[j][l];
			tb[j] = b[j][r] - b[j][l];
			tc[j] = c[j][r] - c[j][l];
		}
		vector<int>p = { 0,1,2 };
		do {
			ll tmp = 0;
			for (int j = 0; j < 3; ++j) {
				if (p[0] != j)tmp += ta[j];
				if (p[1] != j)tmp += tb[j];
				if (p[2] != j)tmp += tc[j];
			}

			ans = min(ans, tmp);
		} while (next_permutation(p.begin(), p.end()));

		cout << ans << "\n";
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}