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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 500048, maxT = 600100, A = 179, K = 170;
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
	cout << "NO\n";
	exit(0);
}
vector<vector<int>>g, g1;
vector<int> used, ts;
int cnt, n, m;
int code(pair<int, int>p) { return m * p.first + p.second; }
vector<set<int>>comp;
void dfs1(int v) {
	used[v] = 1;
	if (comp.back().count(v - cnt) || comp.back().count(v + cnt))
		panic();
	comp.back().insert(v);
	for (auto x : g1[v]) {
		if (used[x])
			continue;
		dfs1(x);
	}
}
void dfs(int v) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (used[x])
			continue;
		dfs(x);
	}
	ts.push_back(v);
}
void solve() {
	cin >> n >> m;
	vector<vector<int>>ans(n, vector<int>(m, 1));
	vector<string>a(n);
	for (auto& x : a)
		cin >> x;
	cnt = n * m;
	g.assign(2 * cnt, vector<int>());
	g1.assign(2 * cnt, vector<int>());
	const vector<pair<int, int>>go = { {0,1},{1,0},{0,-1},{-1,0} };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.')
				continue;
			vector<pair<int, int>>nb;
			for (auto pi : go) {
				int x, y;
				tie(x, y) = pi;
				x += i;
				y += j;
				if (a[x][y] == '.')
					nb.push_back({ x,y });
			}
			if (nb.size() % 2)
				panic();
			if (nb.size() == 0) {
				ans[i][j] = 0;
			}
			else {
				if (nb.size() == 2) {
					ans[i][j] = 5;
					g[code(nb[0]) + cnt].push_back(code(nb[1]));
					g[code(nb[1]) + cnt].push_back(code(nb[0]));
					g[code(nb[0])].push_back(code(nb[1]) + cnt);
					g[code(nb[1])].push_back(code(nb[0]) + cnt);
				}
				else {
					ans[i][j] = 10;
					for (int i = 0; i < 4; ++i) {
						g[code(nb[i]) + cnt].push_back(code(nb[(i + 1) % 4]));
						g[code(nb[i])].push_back(code(nb[(i + 1) % 4]) + cnt);
					}
				}
			}
		}
	}
	used.assign(2 * cnt, 0);
	for (int i = 0; i < 2 * cnt; ++i) {
		if (used[i])
			continue;
		dfs(i);
	}
	for (int i = 0; i < 2 * cnt; ++i) {
		for (auto x : g[i])
			g1[x].push_back(i);
	}
	used.assign(2 * cnt, 0);
	reverse(ts.begin(), ts.end());
	for (auto i : ts) {
		if (used[i])
			continue;
		comp.push_back(set<int>());
		dfs1(i);
	}
	reverse(comp.begin(), comp.end());
	used.assign(cnt, 0);
	for (auto vec : comp) {
		for (auto t : vec) {
			int v = 1;
			if (t >= cnt) {
				t -= cnt;
				v = 4;
			}
			int x = t / m, y = t % m;
			if (a[x][y] == 'X')
				continue;
			if (used[t])
				continue;
			used[t] = 1;
			ans[x][y] = v;
		}
	}
	cout << "YES\n";
	for (auto vec : ans) {
		for (auto x : vec) {
			cout << x << " ";
		}
		cout << "\n";
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