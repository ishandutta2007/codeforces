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
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 50010, maxT = 600100, A = 179, K = 170;
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
int qw(int i, int j, string s) {
	cout << s << " " << i << " " << j << endl;
	int v;
	cin >> v;
	return v;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>>b(30, vector<int>(3));
	vector<int>a(n);
	vector<pair<int, int>>id = { {1,2},{1,3},{2,3} };
	for (int i = 0; i < 3; ++i) {
		int f = qw(id[i].first, id[i].second, "or");
		int s = qw(id[i].first, id[i].second, "and");
		for (int j = 0; j < 30; ++j) {
			if ((f & (1 << j)) == (s & (1 << j))) {
				if ((f & (1 << j)) != 0)b[j][i] = 2;
				else b[j][i] = 0;
			}
			else {
				b[j][i] = 1;
			}
		}
	}
	for (int j = 0; j < 30; ++j) {
		if (b[j][0] == b[j][1] && b[j][1] == b[j][2]) {
			if (b[j][0] == 2) {
				a[0] |= 1 << j;
				a[1] |= 1 << j;
				a[2] |= 1 << j;
			}
		}
		else {
			for (int k = 0; k < 3; ++k) {
				if (b[j][k] == 2) {
					a[id[k].first - 1] |= 1 << j;
					a[id[k].second - 1] |= 1 << j;
				}
				if (b[j][k] == 0) {
					set<int>p = { 1,2,3 };
					p.erase(id[k].first);
					p.erase(id[k].second);
					a[(*p.begin()) - 1] |= 1 << j;
				}
			}
		}
	}
	for (int i = 3; i < n; ++i) {
		a[i] = qw(1, i + 1, "and");
		int tmp = qw(1, i + 1, "or");
		for (int j = 0; j < 30; ++j) {
			if ((a[i] & (1 << j)) != 0 || (tmp & (1 << j)) == 0)
				continue;
			if ((a[0] & (1 << j)) == 0)
				a[i] |= 1 << j;
		}
	}
	sort(a.begin(), a.end());
	cout << "finish " << a[k - 1] << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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