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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 2500, A = 179, mid = 150;
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
	cout << "-1\n";
	exit(0);
}
vector<vector<int>>a;
const vector<pair<int, int>>go = { {0,1},{1,0},{0,-1},{-1,0} };
vector<vector<ll>>bfs(int sx, int sy) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<ll>>cost(n, vector<ll>(m, INF));
	if (a[sx][sy] == -1)
		return cost;
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	cost[sx][sy] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (auto pi : go) {
			int x1, y1;
			tie(x1, y1) = pi;
			x1 += x;
			y1 += y;
			if (x1 < n && x1 >= 0 && y1 < m && y1 >= 0 && cost[x][y] + 1 < cost[x1][y1] && a[x1][y1] != -1) {
				cost[x1][y1] = cost[x][y] + 1;
				q.push({ x1,y1 });
			}
		}
	}
	return cost;
}
void solve() {
	ll n, m, w;
	cin >> n >> m >> w;
	ll ans = INF;
	a.assign(n, vector<int>(m));
	for (auto& vec : a) {
		for (auto& x : vec)cin >> x;
	}
	vector<vector<ll>>f = bfs(0, 0), 
		s = bfs(n - 1, m - 1);
	if (f.back().back() < n * m) {
		ans = (ll)w * f.back().back();
	}
	vector<ll>ff(n * m, INF), ss(n * m, INF);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] <= 0)
				continue;
			if (f[i][j] < n * m) {
				ff[f[i][j]] = min(ff[f[i][j]], (ll)a[i][j]);
			}
			if (s[i][j] < n * m) {
				ss[s[i][j]] = min(ss[s[i][j]], (ll)a[i][j]);
			}
		}
	}
	ll mn1 = INF, mn2 = INF;
	for (int i = 0; i < n * m; ++i) {
		ff[i] += (ll)i * w;
		ss[i] += (ll)i * w;
		mn1 = min(mn1, ff[i]);
		mn2 = min(mn2, ss[i]);
	}
	ans = min(ans, mn1 + mn2);
	if (ans == INF)ans = -1;
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}