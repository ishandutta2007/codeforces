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
const ll INF = 2e18 + 100;
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
void solve() {
	int n;
	cin >> n;
	int ans = 0, msk = (1 << 20) - 2;
	vector<int>a(n);
	for (auto& x : a)
		cin >> x;
	for (int t = 0; t < 20; ++t) {
		vector<ll>ps(n + 1);
		for (int i = 0; i < n; ++i) {
			ps[i + 1] = ps[i] ^ a[i];
			ps[i + 1] &= msk;
		}
		vector<vector<vector<int>>>qu(2, vector<vector<int>>(1 << 20));
		for (int i = 0; i <= n; ++i) {
			qu[i % 2][ps[i]].push_back(i);
		}
		vector<int>pp(n + 1);
		for (int i = 0; i < n; ++i)pp[i + 1] = pp[i] + (a[i] & 1);
		for (const auto& vv : qu) {
			for (const auto& bb : vv) {
				int y = 0;
				int sz = bb.size();
				for (int i = 0; i < sz; ++i) {
					while (y < sz && pp[bb[y]] - pp[bb[i]] == bb[y] - bb[i]) {
						ans = max(ans, bb[y] - bb[i]);
						++y;
					}
				}
			}
		}
		for (auto& x : a)x /= 2;
	}



	cout << ans << "\n";
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