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
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 600100, A = 179, K = 170;
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
	cout << "-1\n";
	exit(0);
}
void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>idx;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '2')idx.push_back(i);
	}
	if (idx.size() == 1 || idx.size() == 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<string>a(n, string(n, 'X'));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] == '1' || s[j] == '1') {
				a[i][j] = a[j][i] = '=';
				continue;
			}
			int y = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
			if (y == 0) {
				int t = lower_bound(idx.begin(), idx.end(), j) - idx.begin();
				if (t == 1) {
					a[i][j] = '+';
					a[j][i] = '-';
				}
				else {
					if (t + 1 == idx.size()) {
						a[i][j] = '-';
						a[j][i] = '+';
					}
					else {
						a[i][j] = a[j][i] = '=';
					}
				}
			}
			else {
				if (y + 1 != idx.size() && idx[y + 1] == j) {
					a[i][j] = '+';
					a[j][i] = '-';
				}
				else {
					a[i][j] = a[j][i] = '=';
				}
			}
		}
	}
	for (auto s : a)cout << s << "\n";
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
/*
2 2
1 1
1 1 2 1
2 1 2
*/