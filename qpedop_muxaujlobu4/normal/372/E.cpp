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
#define int long long
const ll INF = 1e9 + 100;
const int mod = 1000000007;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 70010, maxT = 25000, A = 179, mid = 150;
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
pair<int, int>compr(int a, int b) {
	if (a == 0)return { 0,1 };
	int g = gcd(abs(a), abs(b));
	a /= g;
	b /= g;
	if (a < 0) {
		a = -a;
		b = -b;
	}
	return { a,b };
}
pair<int, int>rbld(int a, int b) {
	if (a == 0)return { 0,1 };
	swap(a, b);
	return compr(a, b);
}
pair<int, int>midd(pair<int, int>f, pair<int, int>s) {
	return compr(f.first * s.second + f.second * s.first, 2 * f.second * s.second);
}
pair<int, int>get_v(pair<int, int>f, pair<int, int>s) {
	//if (f.first == 0 && s.first == 0) {
	//	return { 0,1 };
	//}
	int aa = f.first * s.second;
	int bb = f.second * s.first;
	int cc = f.second * s.second;
	aa -= bb;
	return compr(aa, cc);
}
void solve() {
	int n;
	cin >> n;
	vector < pair<pair<int, int>, pair<int, int>>>vi(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		tie(a, b) = compr(a, b);
		tie(c, d) = compr(c, d);
		ll aa, bb, cc, dd;
		aa = a * a;
		bb = b * b;
		cc = c * c;
		dd = d * d;
		aa = (aa * dd + cc * bb);
		bb = bb * dd;
		tie(aa, bb) = compr(aa, bb);
		tie(a, b) = compr(a * bb, b * aa);
		tie(c, d) = compr(c * bb, d * aa);
		vi[i] = { { a,b }, {c, d} };
	}
	ll ans = 0;
	map<tuple< pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>, ll>mp;
	map<pair< pair<int, int>, pair<int, int>>, ll>mp1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			pair<int, int>x, y;
			x = midd(vi[i].first, vi[j].first);
			y = midd(vi[i].second, vi[j].second);
			/*if (x.first == 0) {
				y = { 1,1 };
			}
			if (y.first == 0) {
				x = { 1,1 };
			}*/
			pair<int, int>x1, y1;
			x1 = get_v(vi[i].first, x);
			y1 = get_v(vi[i].second, y);
			if (x1.first == 0) {
				y1 = { 1,1 };
			}
			if (y1.first == 0) {
				x1 = { 1,1 };
			}
			if (x1.first != 0 && y1.first != 0) {
				y1.second *= x1.first;
				x1.second *= y1.first;
				x1.first = 1;
				y1.first = 1;
			}
			if (x1.second < 0) {
				x1.second = -x1.second;
				y1.second = -y1.second;
			}
			if (x1.second != 0 && y1.second != 0) {
				ll g = gcd(abs(x1.second), abs(y1.second));
				x1.second /= g;
				y1.second /= g;
			}
			++mp[make_tuple(x, y, x1, y1)];
			mp1[{x, y}] = 1;
		}
	}
	ans = (mod - n * (n - 1) / 2 - mp1.size()) % mod;
	for (auto tt : mp) {
		pair<int, int>x, y;
		tie(x, y, ignore, ignore) = tt.first;
		mp1[{x, y}] = mp1[{x, y}] * (tt.second + 1) % mod;
	}
	for (auto x : mp1) {
		ans = (ans + x.second) % mod;
	}
	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
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