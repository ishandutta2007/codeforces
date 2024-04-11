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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 300010, maxT = 600100, A = 179, K = 170;
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
	cout << "No\n";
	exit(0);
}
void solve() {
	int n;
	cin >> n;
	int len = to_string(n).length();
	if (len <= 1) {
		cout << n - 1 << "\n";
		return;
	}
	vector<int>a;
	while (n) {
		a.push_back(n % 10);
		n /= 10;
	}
	ll ans = 0;
	//reverse(a.begin(), a.end());
	for (int m = 0; m < (1 << (len - 2)); ++m) {
		int bb = m << 2;
		vector<int>b = a;
		for (int j = 0; j < len; ++j) {
			if ((bb & (1 << j)) != 0) {
				--b[j];
			}
			if ((m & (1 << j)) != 0) {
				b[j] += 10;
			}
		}
		bool zr = 1, ch = 1, gd = 1;
		for (int j = 0; j < len; ++j) {
			if (b[j] < 0 || b[j] > 18)gd = 0;
			else {
				ch &= b[j] % 2 == 0;
				zr &= b[j] < 10;
			}
		}
		if (!gd)continue;
		if (zr)ans -= 2;
		//if (ch)ans -= 1;
		ll tmp = 1;
		for (auto x : b) {
			if (x < 10) {
				tmp *= x + 1;
			}
			else {
				ll tchn = x - 9;
				x -= 2 * tchn;
				tmp *= x + 1;
			}
		}

		ans += tmp;
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
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}