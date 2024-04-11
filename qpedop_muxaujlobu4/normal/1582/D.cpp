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
const ll maxN = 510, maxT = 3010, A = 179, K = 420;
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
void solve() {
	int n;
	cin >> n;
	vector<ll>a(n);	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n % 2 == 0) {
		for (int i = 0; i < n; i += 2) {
			ll b = a[i], c = a[i + 1];
			cout << -c << " " << b << " ";
		}
		cout << "\n";
		return;
	}
	vector<ll>ans(n);
	map<ll, vector<int>>mp;
	vector<ll>vls;
	for (int i = 3; i < n; ++i) {
		mp[a[i]].push_back(i);
		vls.push_back(abs(a[i]));
	}
	sort(vls.begin(), vls.end());
	vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
	vector<int>idx;
	idx.push_back(0);
	idx.push_back(1);
	idx.push_back(2);
	for (auto x : vls) {
		vector<int>f = mp[x];
		vector<int>s = mp[-x];
		while (!f.empty() && !s.empty()) {
			ans[f.back()] = 1;
			ans[s.back()] = 1;
			f.pop_back();
			s.pop_back();
		}
		while (f.size() >= 2) {
			ans[f.back()] = 1;
			f.pop_back();
			ans[f.back()] = -1;
			f.pop_back();
		}
		while (s.size() >= 2) {
			ans[s.back()] = 1;
			s.pop_back();
			ans[s.back()] = -1;
			s.pop_back();
		}
		if (f.size() == 1)idx.push_back(f[0]);
		if (s.size() == 1)idx.push_back(s[0]);
	}
	while (idx.size() > 3 || idx.size() == 2) {
		int b, c;
		b = idx.back();
		idx.pop_back();
		c = idx.back();
		idx.pop_back();
		ans[b] = -a[c];
		ans[c] = a[b];
	}
	if (idx.size() == 3) {
		ll t1 = abs(a[0]) * (abs(a[1]) + abs(a[2]));
		ans[0] = t1 / a[0];
		t1 = -abs(a[0]) * abs(a[1]);
		ans[1] = t1 / a[1];
		t1 = -abs(a[0]) * abs(a[2]);
		ans[2] = t1 / a[2];
	}
	for (auto x : ans)cout << x << " "; cout << "\n";
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
	cin >> t;
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