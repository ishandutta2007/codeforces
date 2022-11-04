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
const ll maxN = 1 << 20, maxT = 1010, A = 179, K = 450;
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
ll get_inv(vector<int>&a) {
	if (a.size() <= 1)return 0;
	int n = a.size();
	int sz = n / 2;
	vector<int>f(sz), s(n - sz);
	for (int i = 0; i < n; ++i) {
		if (i < sz)f[i] = a[i];
		else s[i - sz] = a[i];
	}
	ll add, res = 0;
	add = get_inv(f);
	res += add;
	add = get_inv(s);
	res += add;
	int yf = 0, ys = 0, y = 0;
	while (y < n) {
		if (ys == s.size() || (yf < f.size() && f[yf] <= s[ys])) {
			a[y++] = f[yf++];
		}
		else {
			a[y++] = s[ys++];
			res += f.size() - yf;
		}
	}
	return res;
}
vector<int>a;
vector<int>b;
vector<int>pss;
int n, m;
void rec(int l1, int r1, int l2, int r2) {
	if (l2 >= r2)return;
	if (l1 == r1) {
		for (int i = l2; i < r2; ++i)pss[i] = l1;
		return;
	}
	int m = (l2 + r2) / 2;
	ll cnt = 0;
	for (int i = l1; i <= r1; ++i) {
		if (i != n && b[m] > a[i])++cnt;
	}
	int pp = l1;
	ll res = cnt;
	for (int i = l1 + 1; i <= r1; ++i) {
		if (a[i - 1] < b[m])--cnt;
		if (a[i - 1] > b[m])++cnt;
		if (cnt < res)res = cnt, pp = i;
	}
	pss[m] = pp;
	rec(l1, pp, l2, m);
	rec(pp, r1, m + 1, r2);
}
void solve() {
	cin >> n >> m;
	a.assign(n, 0);
	b.assign(m, 0);
	pss.assign(m, -1);
	for (auto& x : a)
		cin >> x;
	//a.push_back(INF);
	for (auto& x : b)
		cin >> x;
	sort(b.begin(), b.end());
	rec(0, n, 0, m);
	int y = 0;
	vector<int>c;
	for (int i = 0; i < n; ++i) {
		while (y < m && pss[y] == i)c.push_back(b[y++]);
		c.push_back(a[i]);
	}
	while (y < m)c.push_back(b[y++]);
	ll ans = get_inv(c);
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