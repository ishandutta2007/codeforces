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
const ll INF = 3e18 + 100;
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 20, maxT = 600100, A = 179, K = 170;
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
ll pw[maxN];
map<pair<int, int>, int>mp;
vector<ll>c1(2), c0(2);
map<int, int>row_ct, col_ct;
set<int>cant_row, cant_col;
int n, m;
int to_row[2][2][maxN];
int to_col[2][2][maxN];
void del(int x, int y) {
	int v = mp[{x, y}];
	mp.erase({ x, y });
	if (v == 1) {
		--c1[(x + y) % 2];
	}
	else --c0[(x + y) % 2];
	--to_row[v][y % 2][x];
	if (to_row[1][0][x] != 0 && to_row[1][1][x] != 0) {
		cant_row.insert(x);
	}
	else {
		if (to_row[0][0][x] != 0 && to_row[0][1][x] != 0) {
			cant_row.insert(x);
		}
		else {
			if (to_row[1][0][x] != 0 && to_row[0][0][x] != 0) {
				cant_row.insert(x);
			}
			else {
				if (to_row[1][1][x] != 0 && to_row[0][1][x] != 0) {
					cant_row.insert(x);
				}
				else {
					cant_row.erase(x);
				}
			}
		}
	}
	--to_col[v][x % 2][y];

	if (to_col[1][0][y] != 0 && to_col[1][1][y] != 0) {
		cant_col.insert(y);
	}
	else {
		if (to_col[0][0][y] != 0 && to_col[0][1][y] != 0) {
			cant_col.insert(y);
		}
		else {
			if (to_col[1][0][y] != 0 && to_col[0][0][y] != 0) {
				cant_col.insert(y);
			}
			else {
				if (to_col[1][1][y] != 0 && to_col[0][1][y] != 0) {
					cant_col.insert(y);
				}
				else {
					cant_col.erase(y);
				}
			}
		}
	}
	if (--row_ct[x] == 0)row_ct.erase(x);
	if (--col_ct[y] == 0)col_ct.erase(y);
}
void add(int x, int y, int val) {
	mp[{x, y}] = val;
	if (val == 1) {
		++c1[(x + y) % 2];
	}
	else ++c0[(x + y) % 2];
	++to_row[val][y % 2][x];
	++to_col[val][x % 2][y];
	if (to_row[1][0][x] != 0 && to_row[1][1][x] != 0) {
		cant_row.insert(x);
	}
	else {
		if (to_row[0][0][x] != 0 && to_row[0][1][x] != 0) {
			cant_row.insert(x);
		}
		else {
			if (to_row[1][0][x] != 0 && to_row[0][0][x] != 0) {
				cant_row.insert(x);
			}
			else {
				if (to_row[1][1][x] != 0 && to_row[0][1][x] != 0) {
					cant_row.insert(x);
				}
				else {
					cant_row.erase(x);
				}
			}
		}
	}


	if (to_col[1][0][y] != 0 && to_col[1][1][y] != 0) {
		cant_col.insert(y);
	}
	else {
		if (to_col[0][0][y] != 0 && to_col[0][1][y] != 0) {
			cant_col.insert(y);
		}
		else {
			if (to_col[1][0][y] != 0 && to_col[0][0][y] != 0) {
				cant_col.insert(y);
			}
			else {
				if (to_col[1][1][y] != 0 && to_col[0][1][y] != 0) {
					cant_col.insert(y);
				}
				else {
					cant_col.erase(y);
				}
			}
		}
	}

	++row_ct[x], ++col_ct[y];
}
void solve() {
	int q;
	cin >> n >> m >> q;
	pw[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		pw[i] = pw[i - 1] * 2 % mod;
	}

	while (q--) {

		int x, y, t;
		cin >> x >> y >> t;
		if (mp.count({ x,y }))
			del(x, y);
		if (t != -1) {
			add(x, y, t);
		}
		ll ans = 0;
		if (cant_row.empty()) {
			ans = (ans + pw[n - row_ct.size()]) % mod;
		}
		if (cant_col.empty()) {
			ans = (ans + pw[m - col_ct.size()]) % mod;
		}
		if (c1[0] + c1[1] + c0[0] + c0[1] == 0) {
			ans = (ans - 2 + mod) % mod;
		}
		else {
			if (c1[0] + c0[1] == 0 || c1[1] + c0[0] == 0) {
				ans = (ans - 1 + mod) % mod;
			}
		}
		cout << ans << "\n";
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
	//freopen("exam.in", "r", stdin); freopen("exam.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
11
6 8 7 9 11 13 15 17 19 18 20
*/