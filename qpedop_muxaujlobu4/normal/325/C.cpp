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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 300100, maxT = 10010, A = 179, mid = 150;
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
	cout << "No solution\n";
	exit(0);
}
vector<vector<int>>g, qw, v_to_qw, qw_to_vert;
vector<pair<int, int>>strt;
vector<int>frm, brill, ans1, ans2, circle;
void build_f_ans() {
	int n = g.size();
	vector<int>used(n, 0);
	int m = brill.size();
	vector<int>cnt(m);
	priority_queue<pair<int, int>>q;
	for (auto x : strt) {
		if (x.second < ans1[x.first]) {
			ans1[x.first] = x.second;
			q.push({ -ans1[x.first],x.first });
		}
	}
	while (!q.empty()) {
		int v = q.top().second;
		q.pop();
		if (used[v])
			continue;
		used[v] = 1;
		for (auto x : v_to_qw[v]) {
			if (++cnt[x] == qw[x].size()) {
				int sum = brill[x];
				for (auto to : qw[x]) {
					sum = min(INF, (ll)sum + ans1[to]);
				}
				ans1[frm[x]] = min(ans1[frm[x]], sum);
				q.push({ -ans1[frm[x]],frm[x] });
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ans1[i] = ans2[i] = -1;
		}
		else ans1[i] = min(ans1[i], 314000000);
	}
}
void dfs_cir(int v, vector<int>& used, vector<int>& pr, vector<int>& cnt) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (used[x] == 2)
			continue;
		if (used[x] == 1) {
			++cnt[v];
			if (pr[x] != -1)
				--cnt[pr[x]];
			continue;
		}
		pr[x] = v;
		dfs_cir(x, used, pr, cnt);
		cnt[v] += cnt[x];
	}
	used[v] = 2;
}
void find_circles() {
	int n = g.size();
	vector<int>used(n);
	for (int i = 0; i < n; ++i) {
		if (ans1[i] == -1) {
			used[i] = 2;
		}
	}
	int m = brill.size();
	for (int i = 0; i < m; ++i) {
		bool f = ans1[frm[i]] != -1;
		for (auto x : qw[i])
			f &= ans1[x] != -1;
		if (!f)
			continue;
		for (auto x : qw[i]) {
			g[x].push_back(frm[i]);
		}
	}
	vector<int>pr(n, -1);
	vector<int>cnt(n, 0);
	for (int i = 0; i < n; ++i)
		if (!used[i])dfs_cir(i, used, pr, cnt);
	queue<int>q;
	for (int i = 0; i < n; ++i) {
		if (ans2[i] != -1 && cnt[i]) {
			ans2[i] = -2;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto x : g[v]) {
			if (ans2[x] != -1 && ans2[x] != -2) {
				ans2[x] = -2;
				q.push(x);
			}
		}
	}
}
vector<int>ts;
void dfs_ts(int v, vector<int>&used) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (used[x])
			continue;
		dfs_ts(x, used);
	}
	ts.push_back(v);
}
void calc_dp() {
	int n = g.size();
	vector<int>used(n, 0);
	for (int i = 0; i < n; ++i) {
		if (ans2[i] == -1 || ans2[i] == -2) {
			used[i] = 1;
		}
	}
	g.assign(n, vector<int>());
	int m = brill.size();
	vector<int>used2(m);
	for (int i = 0; i < m; ++i) {
		bool f = !used[frm[i]];
		for (auto x : qw[i])
			f &= !used[x];
		used2[i] = !f;
		if (!f)
			continue;
		for (auto x : qw[i]) {
			g[frm[i]].push_back(x);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i])
			dfs_ts(i, used);
	}
	for (auto v : ts) {
		for (int nb : qw_to_vert[v]) {
			if (used2[nb])
				continue;
			int sum = brill[nb];
			for (auto x : qw[nb]) {
				sum = min(INF, (ll)sum + ans2[x]);
			}
			ans2[v] = max(ans2[v], sum);
		}
	}
	for (auto& x : ans2) {
		x = min(x, 314000000);
	}
}
void solve() {
	int m, n;
	cin >> m >> n;
	g.assign(n, vector<int>());
	ans1.assign(n, INF);
	ans2.assign(n, -INF);
	circle.assign(n, 0);
	//gi.assign(n, vector<int>());
	v_to_qw.assign(n, vector<int>());
	qw_to_vert.assign(n, vector<int>());
	brill.assign(m, 0);
	qw.assign(m, vector<int>());
	frm.assign(m, 0);
	for (int i = 0; i < m; ++i) {
		int st, cnt;
		cin >> st >> cnt;
		frm[i] = --st;
		qw_to_vert[st].push_back(i);
		int b = 0;
		for (int j = 0; j < cnt; ++j) {
			int v;
			cin >> v;
			if (v == -1)++b;
			else {
				qw[i].push_back(--v);
				//g[st].push_back(v);
				v_to_qw[v].push_back(i);
			}
		}
		brill[i] = b;
		if (qw[i].empty()) {
			strt.push_back({ st,b });
		}
	}
	build_f_ans();
	find_circles();
	calc_dp();
	for (int i = 0; i < n; ++i) {
		cout << ans1[i] << " " << ans2[i] << "\n";
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/