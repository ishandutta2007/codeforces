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
ll qw(int i, int j) {
	cout << "? " << i << " " << j << endl;
	ll v;
	cin >> v;
	return v;
}
ll find(ll v) {
	ll l = 0, r = INF;
	while (l + 1 != r) {
		ll m = (l + r) / 2;
		if (m * (m + 1) <= v)l = m;
		else r = m;
	}
	if (l * (l + 1) == v)return l;
	return -1;
}
vector<int>p;
int bb[maxN];
void build() {
	for (int i = 2; i < maxN; ++i) {
		if (bb[i])
			continue;
		p.push_back(i);
		for (int j = i + i; j < maxN; j += i) {
			bb[j] = 1;
		}
	}
}
bool is_it_prm(ll v) {
	for (auto x : p) {
		if (x * x > v)break;
		if (v % x == 0)return false;
	}
	return true;
}
int mx_prm(ll v) {
	ll ans = 0;
	for (ll x : p) {
		if (x * x > v)break;
		ans = x;
		while (v % x == 0)v /= x;
	}
	if (v != 1)return v;
	return ans;
}
void solve() {
	int n;
	cin >> n;
	vector<int>ans(n);
	if (n <= 100) {
		ll mx = 0;
		vector<vector<ll>>g(n, vector<ll>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ll t = qw(i + 1, j + 1);
				g[i][j] = t;
				mx = max(mx, find(t) + 1);
			}
		}
		vector<vector<vector<int>>>rf(n, vector<vector<int>>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ll vl = find(g[i][j]);
				if (vl == -1)continue;
				int k = n - 1 - (mx - (vl + 1));
				if (k >= 0) {
					rf[k][i].push_back(j);
					rf[k][j].push_back(i);
				}
			}
		}
		for (int  m = 0; m < n; ++m) {
			vector<int>idx, used(n);
			int lvl = n - 1, v = m;
			bool nxt = 0;
			while (lvl) {
				used[v] = 1;
				idx.push_back(v);
				vector<int>tmp;
				for (auto x : rf[lvl][v]) {
					if (!used[x])
						tmp.push_back(x);
				}
				if (tmp.size() != 1) {
					nxt = 1;
					break;
				}
				--lvl;
				v = tmp[0];
			}
			if (nxt)continue;
			idx.push_back(v);
			for (auto x : idx)ans[x] = mx--;
			break;
		}
	}
	else {
		if (n <= 5000) {
			ll mx = 0;
			vector<int>idx;
			for (int i = 0; i + 1 < n; ++i) {
				ll v = qw(i + 1, i + 2);
				ll tmp = mx_prm(v);
				if (tmp > mx) {
					mx = tmp;
					idx.clear();
				}
				if (tmp == mx) {
					idx.push_back(i);
					idx.push_back(i + 1);
				}
			}
			int j = -1;
			if (idx.size() != 2 && idx.size() != 4)
				exit(1234);
			if (idx.size() == 4)j = idx[1];
			else {
				if (idx[0] == 0)j = idx[0];
				else j = idx[1];
			}
			ans[j] = mx;
			for (int i = 0; i < n; ++i) {
				if (i == j)
					continue;
				ll v = qw(i + 1, j + 1);
				ans[i] = v / mx;
			}
		}
		else {
			vector<int>not_used;
			for (int i = 0; i < n; ++i) {
				not_used.push_back(i);
			}
			ll mx = 0;
			vector<int>idx;
			for (int i = 0; i < 5000 && not_used.size() >= 2; ++i) {
				int f = mt_rand() % not_used.size();
				swap(not_used[f], not_used.back());
				f = not_used.back();
				not_used.pop_back();
				int s = mt_rand() % not_used.size();
				swap(not_used[s], not_used.back());
				s = not_used.back();
				not_used.pop_back();
				ll v = qw(f + 1, s + 1);
				ll tmp = mx_prm(v);
				if (tmp > mx) {
					mx = tmp;
					idx = { f,s };
				}
			}
			int j = -1;
			for (int i = 0; i < n; ++i) {
				if (i == idx[0] || i == idx[1])
					continue;
				ll v = qw(idx[0] + 1, i + 1);
				ll tmp = mx_prm(v);
				if (tmp > mx) {
					j = i;
					mx = tmp;
				}
				else {
					if (tmp == mx) {
						j = idx[0];
					}
					else {
						j = idx[1];
					}
				}
				break;
			}
			ans[j] = mx;
			for (int i = 0; i < n; ++i) {
				if (i == j)continue;
				ans[i] = qw(i + 1, j + 1) / mx;
			}
		}
	}
	cout << "! ";
	for (auto x : ans)cout << x << " "; cout << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	build();
	//cout << p.size() << endl;
	int t = 1;
	cin >> t;
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