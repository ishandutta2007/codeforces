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
const ll maxN = 200010, maxT = 61, A = 179, mid = 150;
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
int tmr = 0;
vector<ll>tin, tout, dep;
vector<vector<int>>g;
void dfs(int v, int p = -1) {
	tin[v] = tmr++;
	for (auto x : g[v]) {
		if (x == p)
			continue;
		dfs(x, v);
		dep[v] += dep[x];
	}
	tout[v] = tmr++;
}

int l, r;
int rt = -1;
ll root_cnt;
set<int>ss;
bool is_it_good_dfs(int v, int to, int p = -1) {
	bool ans = false;
	ss.insert(v);
	if (v == to) {
		ans = ss.count(0);
		ss.erase(v);
		return ans;
	}
	for (auto x : g[v]) {
		if (x == p)
			continue;
		ans |= is_it_good_dfs(x, to, v);
	}
	ss.erase(v);
	return ans;
}
void upd_cnt_root() {
	root_cnt = dep[rt];
	for (auto x : g[rt]) {
		if (tin[x] > tin[rt] && tin[x] <= tin[l] && tout[l] <= tout[x])
			root_cnt -= dep[x];
	}
}
void solve() {
	int n;
	cin >> n;
	l = r = rt = -1;
	tin.assign(n, 0);
	tout.assign(n, 0);
	dep.assign(n, 1);
	tmr = 0;
	g.assign(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	vector<ll>dp(n + 1);
	dp[0] = (ll)n * (n - 1) / 2;
	for (int i = 0; i < n; ++i) {
		if (rt == -1) {
			rt = i;
		}
		else {
			if (l == -1) {
				l = i;
				upd_cnt_root();
			}
			else {
				if (tin[i] <= tin[l] && tout[l] <= tout[i])
				{

				}
				else {
					if (tin[l] <= tin[i] && tout[i] <= tout[l])
					{
						l = i;
					}
					else {
						if (r == -1) {
							if (!is_it_good_dfs(i, l))
								break;
							r = i;
						}
						else {
							if (tin[i] <= tin[r] && tout[r] <= tout[i])
							{

							}
							else {
								if (tin[r] <= tin[i] && tout[i] <= tout[r])
								{
									r = i;
								}
								else {
									break;
								}
							}
						}
					}
				}
			}
		}
		if (l == -1 && r == -1) {
			ll cnt = 1;
			for (auto x : g[rt]) {
				dp[i + 1] += cnt * dep[x];
				cnt += dep[x];
			}
			//dp[i + 1] = dep[rt] * (n - dep[rt]);
		}
		else {
			if (r == -1) {
				dp[i + 1] = dep[l] * root_cnt;
			}
			else {
				dp[i + 1] = dep[l] * dep[r];
			}
		}
	}

	for (int i = 0; i < n; ++i)dp[i] -= dp[i + 1];
	for (auto x : dp)cout << x << " ";
	cout << "\n";
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}