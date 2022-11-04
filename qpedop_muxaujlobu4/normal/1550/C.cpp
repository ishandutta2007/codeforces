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
int dst(pair<int, int>x, pair<int, int>y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}
bool is_it_good(set<pair<int, int>>s) {
	for (auto x : s)
		for (auto y : s) {
			if (x == y)
				continue;
			for (auto z : s) {
				if (z == y || z == x)
					continue;
				vector<int>d;
				d.push_back(dst(x, y));
				d.push_back(dst(x, z));
				d.push_back(dst(y, z));
				sort(d.begin(), d.end());
				if (d[0] + d[1] == d[2])
					return false;
			}
		}
	return true;
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	int j = 0;
	for (auto& x : a)cin >> x;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n) {
			//s.insert({ a[j],j });
			bool f = 1;
			++j;
			for (int i1 = i; i1 < j; ++i1) {
				for (int i2 = i1 + 1; i2 < j; ++i2) {
					for (int i3 = i2 + 1; i3 < j; ++i3) {
						if (a[i1] <= a[i2] && a[i2] <= a[i3])
							f = 0;
						if (a[i1] >= a[i2] && a[i2] >= a[i3])
							f = 0;
					}
				}
			}
			if (!f) {
				--j;
				break;
			}
		}
		//cout << " " << s.size() << endl;;
		ans += j - i;
	}
	cout << ans << "\n";
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}