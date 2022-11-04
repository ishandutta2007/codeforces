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
const ll maxN = 13, maxT = 600100, A = 179, K = 170;
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
ll c[maxN][maxN];
ll f[maxN];
void build() {
	f[0] = 1;
	for (int i = 1; i < maxN; ++i)f[i] = f[i - 1] * i;
	for (int i = 0; i < maxN; ++i) {
		c[i][0] = c[0][i] = 1;
	}
	for (int i = 1; i < maxN; ++i) {
		for (int j = 1; j < maxN; ++j) {
			c[i][j] = c[i - 1][j] + c[i][j - 1];
		}
	}
}
ll C(int n, int k) {
	return c[n - k][k];
}
ll AA(int n, int k) {
	return f[n] / f[n - k];
}
int g[maxN][maxN];
int n;
int used[maxN];
set<vector<int>>clr[maxN];
vector<pair<int, int>>pr;
vector<int>col;
void rec1(int lvl, int clrr = 1) {
	if (lvl == n / 2) {
		clr[clrr - 1].insert(col);
		return;
	}
	for (int i = 1; i <= clrr; ++i) {
		col[pr[lvl].first - 1] = col[pr[lvl].second - 1] = i;
		rec1(lvl + 1, clrr + (i == clrr));
	}
}
void rec(int lvl) {
	if (lvl == n / 2) {
		vector<int>tmp(n / 2);
		for (int i = 0; i < n / 2; ++i)
			tmp[i] = i;
		bool gg = 0;
		do {
			bool gd = 1;
			for (int i = 1; i < n / 2; ++i) {
				if (!g[pr[tmp[i - 1]].first][pr[tmp[i]].first] ||
					!g[pr[tmp[i - 1]].second][pr[tmp[i]].second]) {
					if (!g[pr[tmp[i - 1]].first][pr[tmp[i]].second] ||
						!g[pr[tmp[i - 1]].second][pr[tmp[i]].first]) {
						gd = 0;
						break;
					}
				}
			}
			gd &= g[pr[tmp.back()].first][pr[tmp.back()].second];
			if (gd) {
				gg = 1;
				break;
			}
		} while (next_permutation(tmp.begin(), tmp.end()));
		if (!gg)
			return;
		col.assign(n, 0);
		rec1(0);
		return;
	}
	int st = 1;
	while (used[st])++st;
	for (int to = st + 1; to <= n; ++to) {
		if (used[to])
			continue;
		used[st] = used[to] = 1;
		pr.push_back({ st,to });
		rec(lvl + 1);
		pr.pop_back();
		used[st] = used[to] = 0;
	}
}
void solve() {
	build();
	int m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	rec(0);
	ll ans = 0;
	for (int i = 1; i <= k; ++i) {
		ll tmp = AA(k, i);
		ans += (ll)clr[i].size() * tmp;
	}
	cout << ans << "\n";
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