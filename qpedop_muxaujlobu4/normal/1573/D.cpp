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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 100010, maxT = 4096, A = 179, K = 170;
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
	int n;
	cin >> n;
	vector<int>a(n), p(n + 1);
	vector<int>ans;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i + 3 < n; ++i) {
		if (a[i] == 1 && a[i + 1] + a[i + 2] + a[i + 3] == 0) {
			ans.push_back(i + 1);
			a[i + 1] = a[i + 2] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + a[i];
	}
	if (p.back() % 2 == 1) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0 && i && i + 1 < n && a[i - 1] == 1 && a[i + 1] == 1 && p[i] % 2) {
			a[i - 1] = a[i + 1] = 0;
			++p[i];
			ans.push_back(i);
		}
		if (a[i] || p[i] % 2)
			continue;
		for (int j = i; j + 2 < n; ++j) {
			if (a[j] == 0 && a[j + 1] == 1) {
				if (a[j + 2] == 1) {
					ans.push_back(j + 1);
					a[j + 1] = a[j + 2] = 0;
				}
				else {
					int s = a[j + 1] + a[j + 2] + a[j + 3];
					s %= 2;
					ans.push_back(j + 2);
					a[j + 1] = a[j + 2] = a[j + 3] = s;
					if (s) {
						ans.push_back(j + 1);
						a[j + 1] = a[j + 2] = 0;
					}
				}
			}
		}

		for (int j = i; j - 2 >= 0; --j) {
			if (a[j] == 0 && a[j - 1] == 1) {
				if (a[j - 2] == 1) {
					ans.push_back(j + 1 - 2);
					a[j - 1] = a[j - 2] = 0;
				}
				else {
					int s = a[j - 1] + a[j - 2] + a[j - 3];
					s %= 2;
					ans.push_back(j + 2 - 4);
					a[j - 1] = a[j - 2] = a[j - 3] = s;
					if (s) {
						ans.push_back(j + 1 - 2);
						a[j - 1] = a[j - 2] = 0;
					}
				}
			}
		}



		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto x : ans)cout << x << " "; cout << "\n";
		return;
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
	//freopen("kitten.in", "r", stdin); freopen("kitten.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
11
6 8 7 9 11 13 15 17 19 18 20
*/