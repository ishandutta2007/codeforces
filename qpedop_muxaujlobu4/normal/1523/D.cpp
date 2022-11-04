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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200100, maxT = 61, A = 179, mid = 150;
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
bitset<maxT>arr[maxN];
mt19937 mt_rand(time(0));
void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			arr[i][j] = s[j] == '1';
		}
	}
	bitset<maxT>ans;
	for (int test = 0; test < 180; ++test) {
		int id = ((rand() << 15) ^ rand()) % n;
		vector<int>tmp;
		for (int j = 0; j < m; ++j) {
			if (arr[id][j])tmp.push_back(j);
		}
		int sz = tmp.size();
		vector<int>dp(1 << sz);
		for (int i = 0; i < n; ++i) {
			int msk = 0;
			for (int j = 0; j < sz; ++j)
				if (arr[i][tmp[j]]) {
					msk |= (1 << j);
				}
			++dp[msk];
		}
		for (int i = sz - 1; i >= 0; --i) {
			for (int j = 0; j < (1 << sz); ++j) {
				if ((j & (1 << i)) != 0) {
					dp[j ^ (1 << i)] += dp[j];
				}
			}
		}
		for (int i = 0; i < (1 << sz); ++i) {
			int cnt = 0;
			if (dp[i] < (n + 1) / 2)continue;
			for (int j = 0; j < sz; ++j) {
				if ((i & (1 << j)) != 0)
					++cnt;
			}
			if (cnt > ans.count()) {
				ans.reset();
				for (int j = 0; j < sz; ++j) {
					if ((i & (1 << j)) != 0)
						ans[tmp[j]] = 1;
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i];
	}
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