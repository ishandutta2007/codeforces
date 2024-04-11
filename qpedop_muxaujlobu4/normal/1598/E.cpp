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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 1010, maxT = 3010, A = 179, K = 420;
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
	cout << "No solution\n";
	exit(0);
}
int n, m;
vector<vector<ll>>a;
void solve() {
	ll ans = 0;
	int q;
	cin >> n >> m >> q;
	a.assign(n, vector<ll>(m));
	vector<vector<ll>>f(n, vector<ll>(m, 1));
	vector<vector<ll>>s(n, vector<ll>(m, 1));
	ll tmp = n * m;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (j + 1 < m) {
				f[i][j] += s[i][j + 1];
			}
			if (i + 1 < n) {
				s[i][j] += f[i + 1][j];
			}
			ans += f[i][j] + s[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		a[x][y] ^= 1;
		if (a[x][y] == 0) {
			++tmp;
			ans += 2;
			f[x][y] = s[x][y] = 1;
			int tx = x, ty = y;
			for (int i = 0; tx >= 0 && ty >= 0; ++i) {
				if (a[tx][ty])break;
				if (i % 2 == 0) {
					if (ty + 1 < m) {
						ll tmp = 1 + s[tx][ty + 1];
						ans += tmp - f[tx][ty];
						f[tx][ty] = tmp;
					}
					--tx;
				}
				else {
					if (tx + 1 < n) {
						ll tmp = 1 + f[tx + 1][ty];
						ans += tmp - s[tx][ty];
						s[tx][ty] = tmp;
					}
					--ty;
				}
			}

			tx = x, ty = y;
			for (int i = 0; tx >= 0 && ty >= 0; ++i) {
				if (a[tx][ty])break;
				if (i % 2 == 1) {
					if (ty + 1 < m) {
						ll tmp = 1 + s[tx][ty + 1];
						ans += tmp - f[tx][ty];
						f[tx][ty] = tmp;
					}
					--tx;
				}
				else {
					if (tx + 1 < n) {
						ll tmp = 1 + f[tx + 1][ty];
						ans += tmp - s[tx][ty];
						s[tx][ty] = tmp;
					}
					--ty;
				}
			}
		}
		else {
			--tmp;
			ans -= f[x][y] + s[x][y];
			int tx = x, ty = y;
			f[x][y] = s[x][y] = 0;
			for (int i = 0; tx >= 0 && ty >= 0; ++i) {
				if (i == 0) {
					--tx;
					continue;
				}
				if (a[tx][ty])break;
				if (i % 2 == 0) {
					if (ty + 1 < m) {
						ll tmp = 1 + s[tx][ty + 1];
						ans += tmp - f[tx][ty];
						f[tx][ty] = tmp;
					}
					--tx;
				}
				else {
					if (tx + 1 < n) {
						ll tmp = 1 + f[tx + 1][ty];
						ans += tmp - s[tx][ty];
						s[tx][ty] = tmp;
					}
					--ty;
				}
			}

			tx = x, ty = y;
			for (int i = 0; tx >= 0 && ty >= 0; ++i) {
				if (i == 0) { 
					--ty;
					continue; 
				}
				if (a[tx][ty])break;
				if (i % 2 == 1) {
					if (ty + 1 < m) {
						ll tmp = 1 + s[tx][ty + 1];
						ans += tmp - f[tx][ty];
						f[tx][ty] = tmp;
					}
					--tx;
				}
				else {
					if (tx + 1 < n) {
						ll tmp = 1 + f[tx + 1][ty];
						ans += tmp - s[tx][ty];
						s[tx][ty] = tmp;
					}
					--ty;
				}
			}


		}
		cout << ans - tmp << '\n';
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
	//freopen("input.in", "r", stdin); freopen("input.out", "w", stdout);
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