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
const ll maxN = 200010, maxT = 600100, A = 179, K = 170;
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
struct game{
	int n, lst;
	vector<int>ans;
	ll h;
	game(int l = 0, int r = 0) {
		n = r - l + 1;
		ans.assign(n, 0);
		h = 0;
		lst = -1;
	}

};
bool cmp(const game& a, const game& b) {
	return a.h < b.h;
}
void solve() {
	ll k, a, h;
	cin >> k >> a >> h;
	if (k <= 4) {
		int cnt = (1 << k) - 1;
		for (int i = 0; i < (1 << cnt); ++i) {
			queue<int>q;
			ll res = 0;
			vector<int>ans(1 << k);
			for (int j = 1; j <= (1 << k); ++j) {
				q.push(j);
			}
			int j = 0;
			for (int r = 1; r <= k; ++r) {
				ll pl = (1 << (k - r)) + 1;
				ll aa = bp(a, pl) % mod;
				queue<int>q1;
				while (!q.empty()) {
					int v = q.front();
					q.pop();
					int u = q.front();
					q.pop();
					if ((i & (1 << j++)) != 0) {
						q1.push(v);
						res = (res + (ll)u * aa) % mod;
						ans[u - 1] = pl;
					}
					else {
						q1.push(u);
						res = (res + (ll)v * aa) % mod;
						ans[v - 1] = pl;
					}
				}
				q = q1;
			}
			ans[q.front() - 1] = 1;
			res = (res + (ll)q.front() * a) % mod;
			if (res == h) {
				for (auto x : ans)cout << x << " ";
				cout << "\n";
				return;
			}
		}
		cout << "-1\n";
		return;
	}
	else {
		int kk = k - 1;
		int cnt = (1 << kk) - 1;
		int y;
		vector<game>f(1 << cnt), s(1 << cnt);
		y = 0;
		for (int i = 0; i < (1 << cnt); ++i) {
			queue<int>q;
			ll res = 0;
			vector<int>ans(1 << kk);
			for (int j = 1; j <= (1 << kk); ++j) {
				q.push(j);
			}
			int j = 0;
			for (int r = 0; r < kk; ++r) {
				ll pl = (1 << (kk - r)) + 1;
				ll aa = bp(a, pl) % mod;
				queue<int>q1;
				while (!q.empty()) {
					int v = q.front();
					q.pop();
					int u = q.front();
					q.pop();
					if ((i & (1 << j++)) != 0) {
						q1.push(v);
						res = (res + (ll)u * aa) % mod;
						ans[u - 1] = pl;
					}
					else {
						q1.push(u);
						res = (res + (ll)v * aa) % mod;
						ans[v - 1] = pl;
					}
				}
				q = q1;
			}
			ans[q.front() - 1] = 2;
			res = (res + (ll)q.front() * a % mod * a) % mod;
			f[y] = game(1, 1 << kk);
			f[y].h = res;
			f[y].lst = q.front();
			f[y].ans = ans;
			++y;
		}
		sort(f.begin(), f.end(), cmp);

		y = 0;
		for (int i = 0; i < (1 << cnt); ++i) {
			queue<int>q;
			ll res = 0;
			vector<int>ans(1 << kk);
			for (int j = (1 << kk) + 1; j <= (1 << k); ++j) {
				q.push(j);
			}
			int j = 0;
			for (int r = 0; r < kk; ++r) {
				ll pl = (1 << (kk - r)) + 1;
				ll aa = bp(a, pl) % mod;
				queue<int>q1;
				while (!q.empty()) {
					int v = q.front();
					q.pop();
					int u = q.front();
					q.pop();
					if ((i & (1 << j++)) != 0) {
						q1.push(v);
						res = (res + (ll)u * aa) % mod;
						ans[u - 1 - (1 << kk)] = pl;
					}
					else {
						q1.push(u);
						res = (res + (ll)v * aa) % mod;
						ans[v - 1 - (1 << kk)] = pl;
					}
				}
				q = q1;
			}
			ans[q.front() - 1 - (1 << kk)] = 2;
			res = (res + (ll)q.front() * a % mod * a) % mod;
			s[y] = game(1, 1 << kk);
			s[y].h = res;
			s[y].lst = q.front();
			s[y].ans = ans;
			++y;
		}
		sort(s.begin(), s.end(), cmp);
		for (auto x : f) {
			x.ans[x.lst - 1] = 1;
			ll tmp = (x.h - (ll)x.lst * a % mod * a % mod + (ll)x.lst * a % mod + mod) % mod;
			ll dd = (h - tmp + mod) % mod;
			int b = 0, e = s.size();
			while (b + 1 != e) {
				int m = (b + e) / 2;
				if (s[m].h <= dd)b = m;
				else e = m;
			}
			if (s[b].h == dd) {
				for (auto p : x.ans)cout << p << " ";
				for (auto p : s[b].ans)cout << p << " ";
				cout << "\n";
				return;
			}
		}
		for (auto x : s) {
			x.ans[x.lst - 1 - (1 << kk)] = 1;
			ll tmp = (x.h - (ll)x.lst * a % mod * a % mod + (ll)x.lst * a % mod + mod) % mod;
			ll dd = (h - tmp + mod) % mod;
			int b = 0, e = f.size();
			while (b + 1 != e) {
				int m = (b + e) / 2;
				if (f[m].h <= dd)b = m;
				else e = m;
			}
			if (f[b].h == dd) {
				for (auto p : f[b].ans)cout << p << " ";
				for (auto p : x.ans)cout << p << " ";
				cout << "\n";
				return;
			}
		}
		cout << "-1\n";
		return;
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
/*
2 2
1 1
1 1 2 1
2 1 2
*/