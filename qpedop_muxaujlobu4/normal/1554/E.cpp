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
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 100010, maxT = 10010, A = 179, mid = 150;
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
int pl(const int& a, const int& b) {
	int r = a + b;
	if (r >= mod)
		r -= mod;
	return r;
}
vector<set<int>>g;
vector<ll>ans;
void solve() {
	int n;
	cin >> n;
	g.assign(n, set<int>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].insert(b);
		g[b].insert(a);
	}
	ans.assign(n, 0);
	ans[0] = bp(2, n - 1);
	vector<vector<int>>to_del(n + 1);
	for (int i = 0; i < n; ++i) {
		to_del[g[i].size()].push_back(i);
	}
	bool can_we_cont = true;
	vector<int>pw(n), used(n);
	vector<int>pw1(n), ost(n);
	set<int>vert;
	for (int i = 0; i < n; ++i)
		vert.insert(i);
	vector<int>in_size(n);
	for (int i = 0; i < n; ++i) {
		in_size[i] = g[i].size();
	}
	for (int i = 2; i <= n; ++i) {
		for (auto v : to_del[i - 1]) {
			used[v] = 1;
			vert.erase(v);
			if (g[v].size() < in_size[v]) {
				can_we_cont = false;
			}
			while (!g[v].empty()) {
				int vv = *g[v].begin();
				g[v].erase(g[v].begin());
				g[vv].erase(v);
				++pw[vv];
			}
		}
		if (!can_we_cont)
			break;
		queue<int>q;
		for (auto x : vert) {
			if (g[x].size() <= 1)
				q.push(x);
			pw1[x] = pw[x];
			ost[x] = g[x].size();
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			used[v] = 1;
			int neib = -1;
			for (auto x : g[v])
				if (!used[x])neib = x;
			if (neib != -1) {
				--ost[neib];
				if (ost[neib] == 1) {
					q.push(neib);
				}
				if (pw[v] % i == 0)++pw[neib];
				else ++pw[v];
			}
		}
		ll gd = -1;
		for (auto x : vert) {
			if (pw[x] == 0)
				continue;
			if (gd == -1)gd = pw[x];
			gd = gcd(gd, pw[x]);
		}
		for (auto x : vert)pw[x] = pw1[x], ost[x] = 0, used[x] = 0;
		if (gd == i) {
			ans[i - 1] = 1;
			ans[0] = pl(ans[0], mod - 1);
		}
	}

	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}