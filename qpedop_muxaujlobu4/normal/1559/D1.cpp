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
const ll maxN = 200010, maxT = 519, A = 179, mid = 350, K = 500;
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
	cout << "No\n";
	exit(0);
}
struct dsu {
	vector<int>f;
	dsu(int n) {
		f.assign(n, 0);
		for (int i = 0; i < n; ++i)
			f[i] = i;
	}
	int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
	bool uni(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)
			return false;
		f[a] = b;
		return true;
	}
};
void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	dsu f = dsu(n), s = dsu(n);
	vector<pair<int, int>>ans;
	for (int i = 0; i < m1; ++i) {
		int a, b;
		cin >> a >> b;
		f.uni(--a, --b);
	}
	for (int i = 0; i < m2; ++i) {
		int a, b;
		cin >> a >> b;
		s.uni(--a, --b);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (f.find(i) != f.find(j) &&
				s.find(i) != s.find(j)) {
				ans.push_back({ i + 1,j + 1 });
				f.uni(i, j);
				s.uni(i, j);
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.first << " " << x.second << "\n";
	}
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