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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 1010, A = 179, K = 200;
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
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	for (auto& vec : a) {
		for (auto& x : vec)cin >> x;
	}
	vector<vector<int>>syff_mx = a,
		syff_mn = a, pref_mn = a, pref_mx = a;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			pref_mn[i][j] = min(pref_mn[i][j - 1], pref_mn[i][j]);
			pref_mx[i][j] = max(pref_mx[i][j - 1], pref_mx[i][j]);
		}
		for (int j = m - 2; j >= 0; --j) {
			syff_mn[i][j] = min(syff_mn[i][j], syff_mn[i][j + 1]);
			syff_mx[i][j] = max(syff_mx[i][j], syff_mx[i][j + 1]);
		}
	}
	for (int j = 0; j + 1 < m; ++j) {
		vector<pair<int, int>>mx1(n);
		for (int i = 0; i < n; ++i) {
			mx1[i] = { pref_mx[i][j],i };
		}
		sort(mx1.begin(), mx1.end());
		vector<int>seq(n);
		for (int i = 0; i < n; ++i)seq[i] = mx1[i].second;
		vector<int>p1(n), p2(n), s1(n), s2(n);
		for (int i = 0; i < n; ++i) {
			int v = seq[i];
			p1[i] = pref_mn[v][j];
			p2[i] = pref_mx[v][j];
			s1[i] = syff_mn[v][j + 1];
			s2[i] = syff_mx[v][j + 1];
			if (i) {
				s1[i] = min(s1[i], s1[i - 1]);
				p2[i] = max(p2[i], p2[i - 1]);
			}
		}
		for (int i = n - 2; i >= 0; --i) {
			p1[i] = min(p1[i], p1[i + 1]);
			s2[i] = max(s2[i], s2[i + 1]);
		}
		string s(n, 'R');
		for (int i = 0; i + 1 < n; ++i) {
			s[seq[i]] = 'B';

			if (p2[i] < p1[i + 1] && s1[i] > s2[i + 1]) {
				cout << "YES\n";
				cout << s << " " << j + 1 << "\n";
				return;
			}
		}
	}
	cout << "NO\n";
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
	cin >> t;
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