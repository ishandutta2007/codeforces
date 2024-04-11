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
const ll maxN = 4e4, maxT = 61, A = 179, mid = 150;
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
	cout << "-1\n";
	exit(0);
}
int n, m, ans = 0;
int dp1[1 << 14][101];
int used[1 << 14][101];
int dp2[100][1 << 14];
inline void bld() {
	for (int j = 0; j < (1 << n); ++j) {
		for (int k = 0; k <= m; ++k) {
			dp1[j][k] = INF;
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			dp2[i][j] = -1;
		}
	}
}
inline int dst(const pair<int, int>& a, const pair<int, int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
pair<int, int>a[14], b[100];
int tmr[100];
int dd[1 << 14][100];
int dd1[1 << 14][14];
inline void solve() {
	cin >> n >> m;
	bld();
	priority_queue<tuple<int, int, int>>q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second >> tmr[i];
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < m; ++j) {
			dd[i][j] = INF;
			for (int k = 0; k < n; ++k) {
				if ((i & (1 << k)) != 0) {
					dd[i][j] = min(dd[i][j], dst(a[k], b[j]));
				}
			}
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			dd1[i][j] = INF;
			for (int k = 0; k < n; ++k) {
				if ((i & (1 << k)) != 0) {
					dd1[i][j] = min(dd1[i][j], dst(a[k], a[j]));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		dp1[1 << i][0] = 0;
		q.push(make_tuple(0, 1 << i, 0));
	}
	for (int i = 0; i < m; ++i) {
		dp2[i][0] = 0;
		q.push(make_tuple(-tmr[i], -1, i));
	}
	while (!q.empty()) {
		int aa, bb;
		tie(ignore, aa, bb) = q.top();
		q.pop();
		if (aa != -1) {
			int cnt = bb;
			int msk = aa;
			if (used[msk][cnt])continue;
			used[msk][cnt] = 1;
			int cost = dp1[msk][cnt];
			for (int i = 0; i < m; ++i) {
				if (cost + dd[msk][i] <= tmr[i]) {
					dp2[i][msk] = max(dp2[i][msk], cnt);
				}
			}
			for (int i = 0; i < n; ++i) {
				int add = dd1[msk][i];
				if (dp1[msk | (1 << i)][cnt] > cost + add) {
					dp1[msk | (1 << i)][cnt] = cost + add;
					q.push(make_tuple(-(cost + add), msk | (1 << i), cnt));
				}
			}
		}
		else {
			int v = bb;
			int cost = tmr[v];
			for (int msk = 0; msk < (1 << n); ++msk) {
				if (dp2[v][msk] == -1)
					continue;
				int cnt = dp2[v][msk] + 1;
				ans = max(ans, cnt);
				for (int i = 0; i < m; ++i) {
					if (i == v)
						continue;
					if (cost + dst(b[i], b[v]) <= tmr[i]) {
						dp2[i][msk] = max(dp2[i][msk], cnt);
					}
				}
				for (int i = 0; i < n; ++i) {
					int add = 0;
					if ((msk & (1 << i)) == 0) {
						add = dst(b[v], a[i]);
					}
					if (dp1[msk | (1 << i)][cnt] > cost + add) {
						dp1[msk | (1 << i)][cnt] = cost + add;
						q.push(make_tuple(-(cost + add), msk | (1 << i), cnt));
					}
				}
			}
		}
	}
	cout << ans << endl;
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