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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 400100, maxT = 61, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1" << endl;
	exit(0);
}
int n, m;
vector<vector<int>>used;
vector<vector<char>>a;
const vector<pair<int, int>>go = { { 0,1 },{1,0},{0,-1},{-1,0} };
int code(int i, int j) {
	return i * m + j;
}
pair<int, int>vrt_by_code(int code) {
	return { code / m,code % m };
}
int dep[maxN];
vector<int>g[maxN], g1[maxN];
int color[maxN];
vector<int>ts;
void dfs(int v) {
	dep[v] = 1;
	for (auto x : g[v]) {
		if (!dep[x]) {
			dfs(x);
		}
	}
	ts.push_back(v);
}
vector<vector<int>>comp;
vector<set<int>>imp;
vector<int>important;
void dfs1(int v) {
	dep[v] = 1;
	comp.back().push_back(v);
	color[v] = comp.size();
	for (auto x : g1[v]) {
		if (!dep[x]) {
			dfs1(x);
		}
	}
}
void dfs2(int v) {
	dep[v] = 1;
	for (auto x : g[v]) {
		if (!dep[x]) {
			dfs2(x);
		}
		else {
			if (color[x] != color[v] && !imp[color[x] - 1].empty()) {
				for (auto y : imp[color[x] - 1])
					important[y] = n;
				imp[color[x] - 1].clear();
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	a.assign(n, vector<char>(m));
	used.assign(n, vector<int>(m));
	vector<vector<int>>id(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] != '.') {
				id[j].push_back(i);
			}
		}
	}
	vector<int>arr(m);
	important.resize(m);
	for (int j = 0; j < m; ++j) {
		cin >> arr[j];
		if (arr[j] == 0)
			important[j] = n;
		else 
			important[j] = id[j][id[j].size() - arr[j]];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.')
				continue;
			int cdd = code(i, j);
			for (auto x : go) {
				int ii, jj;
				tie(ii, jj) = x;
				ii += i;
				jj += j;
				if (ii < 0 || jj < 0 || ii >= n || jj >= m)
					continue;
				if (a[ii][jj] == '.')
					continue;
				int cdd1 = code(ii, jj);
				g[cdd].push_back(cdd1);
				g1[cdd1].push_back(cdd);
			}
			for (int k = max(0, j - 1); k <= min(j + 1, m - 1); ++k) {
				int y = upper_bound(id[k].begin(), id[k].end(), i) - id[k].begin();
				if (y != id[k].size()) {
					int ii = id[k][y];
					int cdd1 = code(ii, k);
					g[cdd].push_back(cdd1);
					g1[cdd1].push_back(cdd);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cdd = code(i, j);
			if (a[i][j] != '.' && !dep[cdd]) {
				dfs(cdd);
			}
		}
	}
	reverse(ts.begin(), ts.end());
	fill(begin(dep), end(dep), 0);
	for (auto v : ts) {
		if (!dep[v]) {
			comp.push_back({});
			imp.push_back({});
			dfs1(v);
			for (auto x : comp.back()) {
				int ii, jj;
				tie(ii, jj) = vrt_by_code(x);
				if (important[jj] == ii)
					imp.back().insert(jj);
			}
		}
	}
	fill(begin(dep), end(dep), 0);
	for (int i = (int)comp.size() - 1; i >= 0; --i) {
		if (!imp[i].empty()) {
			dfs2(comp[i][0]);
		}
	}
	vector<int>dp_max(comp.size(), -1), dp_min(comp.size(), m);
	set<pair<int, int>>seg;
	for (int i = (int)comp.size() - 1; i >= 0; --i) {
		if (!imp[i].empty()) {
			dp_min[i] = *imp[i].begin();
			dp_max[i] = *imp[i].rbegin();
		}
		for (auto fr : comp[i]) {
			for (auto to : g[fr]) {
				dp_min[i] = min(dp_min[i], dp_min[color[to] - 1]);
				dp_max[i] = max(dp_max[i], dp_max[color[to] - 1]);
			}
		}
		if (dp_max[i] != -1) {
			seg.insert({ dp_min[i],dp_max[i] });
		}
	}
	int ans = 0;
	int mx = -1;
	int rr = -1;
	set<int>isk;
	for (auto s : seg) {
		int l, r;
		tie(l, r) = s;
		if (l > rr) {
			if (isk.empty())isk.insert(l);
			if (*isk.begin() != l) {
				rr = mx;
				++ans;
				isk.clear();
				if (l > rr) {
					isk.insert(l);
					mx = max(mx, r);
				}
			}
			else {
				mx = max(mx, r);
			}
		}
		else mx = max(mx, r);
	}
	if (!isk.empty())++ans;
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
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}