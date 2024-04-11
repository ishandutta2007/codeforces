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
	cout << "No\n";
	exit(0);
}
struct edge {
	int fr, to;
	ll f, c;
	edge(int FR = 0, int TO = 0, ll F = 0, ll C = 0) {
		fr = FR;
		to = TO;
		f = F;
		c = C;
	}
};
struct dinic {
	int sz, s, t;
	vector<vector<int>>Gr;
	vector<edge>Ed;
	dinic(int SZ = 1) {
		sz = SZ;
		s = 0;
		t = sz - 1;
		Gr.resize(sz);
	}
	void add(int fr, int to, ll c) {
		Ed.push_back(edge(fr, to, 0, c));
		Ed.push_back(edge(to, fr, 0, 0));
		Gr[fr].push_back(Ed.size() - 2);
		Gr[to].push_back(Ed.size() - 1);
	}
	vector<int>path;
	bool bfs() {
		path.assign(sz, -1);
		path[s] = 0;
		queue<int>q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto e : Gr[v]) {
				if (Ed[e].f == Ed[e].c || path[Ed[e].to] != -1)continue;
				path[Ed[e].to] = path[v] + 1;
				q.push(Ed[e].to);
			}
		}
		return path[t] != -1;
	}
	vector<int>used;
	ll dfs(int i, ll cs = INF) {
		if (i == t)return cs;
		for (; used[i] < Gr[i].size(); ++used[i]) {
			int e = Gr[i][used[i]];
			if (path[Ed[e].fr] + 1 == path[Ed[e].to] && Ed[e].c > Ed[e].f) {
				ll tmp = dfs(Ed[e].to, min(cs, Ed[e].c - Ed[e].f));
				if (!tmp)continue;
				Ed[e].f += tmp;
				Ed[e ^ 1].f -= tmp;
				return tmp;
			}
		}
		return 0;
	}
	ll run() {
		ll ans = 0;
		while (bfs()) {
			used.assign(sz, 0);
			while (ll pt = dfs(s)) {
				ans += pt;
			}
		}
		return ans;
	}
};
int n, m;
void show(vector<vector<int>>a) {
	cout << "--------\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------\n";
}
int run(vector<vector<int>>a) {
	int r = 0;
	vector<vector<int>>b(n, vector<int>(m));
	vector<vector<int>>c(n, vector<int>(m));
	vector<vector<int>>dp(n, vector<int>(m));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i + 1 < n)b[i][j] ^= b[i + 1][j];
			if (j + 1 < m)b[i][j] ^= b[i][j + 1];
			if (i + 1 < n && j + 1 < m)b[i][j] ^= b[i + 1][j + 1];
			if ((a[i][j] ^ b[i][j]) == 1) {
				++r;
				b[i][j] ^= 1;
				c[i][j] = 1;
			}
		}
	}
	int res = r;
	dinic d = dinic(n + m + 2);
	for (int i = 1; i <= n; ++i)d.add(0, i, 1);
	for (int i = n + 1; i <= n + m; ++i)
		d.add(i, n + m + 1, 1);
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			if (c[i][j] == 1 && c[i][m - 1] == 1 && c[n - 1][j] == 1)
				d.add(i + 1, n + 1 + j, 1);
		}
	}
	int tmp = d.run();
	if (tmp % 2 == 1) {
		if (c[n - 1][m - 1] == 1)++tmp;
		else --tmp;
	}
	res -= tmp;
	return res;
}
void solve() {
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char t;
			cin >> t;
			a[i][j] = t == 'B';
		}
	}
	int ans = run(a);

	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("party.in", "r", stdin); freopen("party.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}