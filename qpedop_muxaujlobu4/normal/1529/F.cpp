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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 510, maxT = 519, A = 179, mid = 150, K = 350;
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
	cout << "No\n";
	exit(0);
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>>g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		//--a, --b;
		g[a].push_back({ c,b });
	}
	for (auto& vec : g) {
		sort(vec.begin(), vec.end());
	}
	for (int i = 0; i < n; ++i) {
		vector<ll>c(n, INF);
		c[i] = 0;
		ll mn = g[i][0].first;
		vector<queue<int>>q(n);
		for (auto p : g[i]) {
			if (p.second == i) {
				p.second = (p.second + 1) % n;
				++p.first;
			}
			if (p.first < c[p.second]) {
				c[p.second] = p.first;
				if (mn + n > c[p.second]) {
					q[c[p.second] - mn].push(p.second);
				}
			}
		}
		for (int add = 0; add < n; ++add) {
			while(!q[add].empty()) {
				int v = q[add].front();
				q[add].pop();
				if (c[v] < mn + add)
					continue;
				ll tm = mn + add;
				for (auto p : g[v]) {
					p.second = (p.second + tm) % n;
					if (p.first + c[v] < c[p.second]) {
						c[p.second] = p.first + c[v];
						if (mn + n > c[p.second]) {
							q[c[p.second] - mn].push(p.second);
						}
					}
					p.second = (p.second + 1) % n;
					++p.first;
					if (p.first + c[v] < c[p.second]) {
						c[p.second] = p.first + c[v];
						if (mn + n > c[p.second]) {
							q[c[p.second] - mn].push(p.second);
						}
					}
				}
				int to = (v + 1) % n;
				if (c[v] + 1 < c[to]) {
					c[to] = c[v] + 1;
					if (mn + n > c[to]) {
						q[c[to] - mn].push(to);
					}
				}

				to = (v + 2) % n;
				if (c[v] + 2 < c[to]) {
					c[to] = c[v] + 2;
					if (mn + n > c[to]) {
						q[c[to] - mn].push(to);
					}
				}
			}
		}


		for (auto x : c) {
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
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}