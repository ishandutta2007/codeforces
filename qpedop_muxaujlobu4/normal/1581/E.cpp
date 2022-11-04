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
const ld eps = 1e-6, pi = acos(-1);
const ll maxN = 110, maxT = 4096, A = 179, K = 420;
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
	int n, m;
	cin >> n >> m;
	vector<int>x(n), y(n), tmr(n), ps(m);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<int>>tt(K);
	for (int i = 1; i < K; ++i) {
		tt[i].assign(i, 0);
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		int op, k;
		cin >> op >> k;
		res += ps[i];
		--k;
		int len = x[k] + y[k];
		if (op == 1) {
			tmr[k] = i;
			if (len < K) {
				for (int j = x[k]; j < x[k] + y[k]; ++j) {
					++tt[len][(tmr[k] + j) % len];
				}
			}
			else {
				for (ll j = i; j + x[k] < m; j += x[k] + y[k]) {
					++ps[j + x[k]];
					if (j + x[k] + y[k] < m) {
						--ps[j + x[k] + y[k]];
					}
				}
			}
		}
		else {
			if (len < K) {
				for (int j = x[k]; j < x[k] + y[k]; ++j) {
					--tt[len][(tmr[k] + j) % len];
				}
			}
			else {
				ll v = i - tmr[k];
				v %= (x[k] + y[k]);
				if (v >= x[k])--res;
				for (ll j = tmr[k]; j + x[k] < m; j += x[k] + y[k]) {
					--ps[j + x[k]];
					if (j + x[k] + y[k] < m) {
						++ps[j + x[k] + y[k]];
					}
				}
			}
		}
		int rr = res;
		for (int j = 1; j < K; ++j) {
			rr += tt[j][i % j];
		}
		cout << rr << "\n";
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
	//freopen("snake.in", "r", stdin); freopen("snake.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
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