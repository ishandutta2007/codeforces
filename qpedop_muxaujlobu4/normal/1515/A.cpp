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
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 200100, maxT = 10010, A = 179, mid = 150;
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
bool is_it_good(vector<int>a, int x) {
	int s = 0;
	for (auto d : a) {
		s += d;
		if (s == x)
			return false;
	}
	return true;
}
void solve() {
	int n, x;
	cin >> n >> x;
	vector<int>a(n);
	for (auto& x : a)
		cin >> x;
	if (!is_it_good(a, x)) {
		bool f = 1;
		for (auto x : a)
			f &= x == a[0];
		int sum = 0;
		for (auto x : a)sum += x;
		if (f || x == sum) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	sort(a.begin(), a.end());
	if (!is_it_good(a, x)) {
		int y = 0;
		int s = 0;
		while (s < x)
			s += a[y++];
		bool f = 0;
		for (int i = y; i < n; ++i) {
			if (a[i] > a[y - 1]) {
				f = 1;
				swap(a[i], a[y - 1]);
				break;
			}
		}
		if (!f) {
			for (int i = 0; i < y; ++i) {
				if (a[i] < a[y]) {
					f = 1;
					swap(a[i], a[y]);
					break;
				}
			}
		}
	}
	for (auto x : a)
		cout << x << " "; cout << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/