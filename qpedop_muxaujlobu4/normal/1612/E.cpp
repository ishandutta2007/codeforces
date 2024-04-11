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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 110, maxT = 200000, A = 179, K = 450;
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
	cout << "impossible\n";
	exit(0);
}
ld prec[maxN][maxN];
void build() {
	for (int i = 0; i < maxN; ++i)prec[i][0] = prec[0][i] = 1;
	for (int i = 1; i < maxN; ++i) {
		for (int j = 1; j < maxN; ++j) {
			prec[i][j] = prec[i - 1][j] + prec[i][j - 1];
		}
	}
}
ld fun(int cnt, int k) {
	if (cnt <= k)return 1;
	return (ld)k / cnt;
}
void solve() {
	build();
	int n;
	cin >> n;
	vector<pair<int, int>>a(n);
	for (auto& x : a) {
		cin >> x.first >> x.second;
		--x.first;
	}
	pair<ll, ll> ans = { -1,1 };
	vector<int>viv;
	for (int k = 1; k <= 20; ++k) {
		vector<pair<ll, int>>t(maxT);
		for (int i = 0; i < maxT; ++i) {
			t[i] = { 0,i };
		}
		for (auto x : a) {
			t[x.first].first += min(k, x.second);
		}
		sort(t.rbegin(), t.rend());
		ll tmp = 0;
		for (int i = 0; i < k; ++i)tmp += t[i].first;
		if (tmp * ans.second > ans.first * k) {
			ans = { tmp, k };
			viv.clear();
			for (int i = 0; i < k; ++i) {
				viv.push_back(t[i].second + 1);
			}
		}
	}
	sort(viv.begin(), viv.end());
	cout << viv.size() << "\n";
	for (auto x : viv)cout << x << " "; cout << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
2 5
5 6
6 7
5
4 3 2 5 6 7
1
*/