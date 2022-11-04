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
const ll maxN = 100010, maxT = 600100, A = 179, K = 170;
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
set<pair<int, int>>g[maxN];
set<tuple<int, int, int>>ans;
ll res = INF;
map<pair<int, int>, int>ed;
pair<int, int>pii(int a, int b) {
	if (a > b)swap(a, b);
	return { a, b };
}
ll calc3(int v) {
	if (g[v].size() < 3)
		return INF;
	ll res = 0;
	auto it = g[v].begin();
	for (int i = 0; i < 3; ++i) {
		res += (*it++).first;
	}
	return res;
}
void upd_res_by_ans() {
	int fa, fb;
	tie(ignore, fa, fb) = *ans.begin();
	auto it = ans.begin();
	int cnt = 0;
	while (true) {
		if (it == ans.end())break;
		int sa, sb;
		tie(ignore, sa, sb) = *it;
		if (sa == fa || sa == fb || sb == fa || sb == fb)
			++it, ++cnt;
		else break;
	}
	if (cnt >= 10) {
		exit(1234);
	}
	if (it != ans.end())++it;
	for (auto t = ans.begin(); t != it; ++t) {
		ll fc;
		tie(fc, fa, fb) = *t;
		for (auto d = t; d != it; ++d) {
			ll sc;
			int sa, sb;
			tie(sc, sa, sb) = *d;
			if (sa == fa || sa == fb || sb == fa || sb == fb)
				continue;
			res = min(res, fc + sc);
		}
	}
}
void add(int v, int u, int c) {
	int i;
	i = 0;
	for (auto it = g[v].begin(); i < 3 && it != g[v].end(); ++i, ++it) {
		int a = v, b = (*it).second;
		tie(a, b) = pii(a, b);
		--ed[{a, b}];
		ans.erase(make_tuple((*it).first, a, b));
	}
	g[v].insert({ c,u });
	i = 0;
	for (auto it = g[v].begin(); i < 3 && it != g[v].end(); ++i, ++it) {
		int a = v, b = (*it).second;
		tie(a, b) = pii(a, b);
		if (++ed[{a, b}] == 2) {
			ans.insert(make_tuple((*it).first, a, b));
		}
	}

	i = 0;
	for (auto it = g[u].begin(); i < 3 && it != g[u].end(); ++i, ++it) {
		int a = u, b = (*it).second;
		tie(a, b) = pii(a, b);
		--ed[{a, b}];
		ans.erase(make_tuple((*it).first, a, b));
	}
	g[u].insert({ c,v });
	i = 0;
	for (auto it = g[u].begin(); i < 3 && it != g[u].end(); ++i, ++it) {
		int a = u, b = (*it).second;
		tie(a, b) = pii(a, b);
		if (++ed[{a, b}] == 2) {
			ans.insert(make_tuple((*it).first, a, b));
		}
	}
	int a, b;
	tie(ignore, a, b) = *ans.begin();
	res = min(calc3(a), calc3(b));
	upd_res_by_ans();
}
void del(int v, int u, int c) {
	int i;
	i = 0;
	for (auto it = g[v].begin(); i < 3 && it != g[v].end(); ++i, ++it) {
		int a = v, b = (*it).second;
		tie(a, b) = pii(a, b);
		--ed[{a, b}];
		ans.erase(make_tuple((*it).first, a, b));
	}
	g[v].erase({ c,u });
	i = 0;
	for (auto it = g[v].begin(); i < 3 && it != g[v].end(); ++i, ++it) {
		int a = v, b = (*it).second;
		tie(a, b) = pii(a, b);
		if (++ed[{a, b}] == 2) {
			ans.insert(make_tuple((*it).first, a, b));
		}
	}


	i = 0;
	for (auto it = g[u].begin(); i < 3 && it != g[u].end(); ++i, ++it) {
		int a = u, b = (*it).second;
		tie(a, b) = pii(a, b);
		--ed[{a, b}];
		ans.erase(make_tuple((*it).first, a, b));
	}
	g[u].erase({ c,v });
	i = 0;
	for (auto it = g[u].begin(); i < 3 && it != g[u].end(); ++i, ++it) {
		int a = u, b = (*it).second;
		tie(a, b) = pii(a, b);
		if (++ed[{a, b}] == 2) {
			ans.insert(make_tuple((*it).first, a, b));
		}
	}

	int a, b;
	tie(ignore, a, b) = *ans.begin();
	res = min(calc3(a), calc3(b));
	upd_res_by_ans();
}
void solve() {
	int n = getint<int>(), m = getint<int>();
	//g.assign(n, set<pair<int, int>>());
	map<pair<int, int>, int>mp;
	for (int i = 0; i < m; ++i) {
		int a = getint<int>(), b = getint<int>(), c = getint<int>();
		//cin >> a >> b >> c;
		--a, --b;
		mp[{a, b}] = mp[{b, a}] = c;
		add(a, b, c);
	}
	cout << res << '\n';
	int q = getint<int>();
	//cin >> q;
	/*if (n == 100000) {
		cout << q << endl;
		return;
	}*/
	while (q--) {
		int t = getint<int>();
		//cin >> t;
		if (t) {
			int a = getint<int>(), b = getint<int>(), c = getint<int>();
			//cin >> a >> b >> c;
			--a, --b;
			mp[pii(a, b)] = c;
			add(a, b, c);
		}
		else {
			int a = getint<int>(), b = getint<int>();
			//cin >> a >> b;
			--a, --b;
			del(a, b, mp[pii(a, b)]);
		}
		cout << res << "\n";
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