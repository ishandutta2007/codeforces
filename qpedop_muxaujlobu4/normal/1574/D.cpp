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
const ll INF = 3e18 + 100;
const int mod = 1000000007;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 100048, maxT = 600100, A = 179, K = 170;
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
void solve() {
	int n;
	cin >> n;
	vector<vector<ll>>c(n);
	set<vector<int>>gov, used;
	vector<int>st(n);
	for (int i = 0; i < n; ++i) {
		int cnt;
		cin >> cnt;
		c[i].resize(cnt);
		st[i] = cnt;
		for (auto& x : c[i])
			cin >> x;
	}
	int q;
	cin >> q;
	while (q--) {
		vector<int>vv(n);
		for (auto& x : vv) {
			cin >> x;
		}
		gov.insert(vv);
	}
	ll sum = 0;
	for (auto x : c)sum += x.back();
	priority_queue<pair<ll, vector<int>>>qq;
	qq.push({ sum,st });
	used.insert(st);
	while (true) {
		ll cc;
		vector<int>b;
		tie(cc, b) = qq.top();
		qq.pop();
		if (!gov.count(b)) {
			for (auto x : b)cout << x << " "; cout << "\n";
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (b[i] == 1)
				continue;
			vector<int>tmp = b;
			--tmp[i];
			if (used.count(tmp))
				continue;
			used.insert(tmp);
			ll tc = cc - c[i][tmp[i]] + c[i][tmp[i] - 1];
			qq.push({ tc,tmp });
		}
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
	//freopen("exam.in", "r", stdin); freopen("exam.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
11
6 8 7 9 11 13 15 17 19 18 20
*/