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
const int mod = 31607;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 1e6, maxT = 4010, A = 179, mid = 150;
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
const int sz = 20;
int n, k;
vector<int> pl(const vector<int>& a, const vector<int>& b) {
	vector<int>r(sz);
	for (int i = 0; i < sz; ++i) {
		r[i] = (a[i] + b[i]) % k;
	}
	return r;
}
vector<int> mn(const vector<int>& a, const vector<int>& b) {
	vector<int>r(sz);
	for (int i = 0; i < sz; ++i) {
		r[i] = (a[i] - b[i] + k) % k;
	}
	return r;
}
int chi_by_v(const vector<int>& a) {
	int r = 0;
	for (auto& x : a)
		r = r * k + x;
	return r;
}
vector<int>v_by_chi(int v) {
	vector<int>chi;
	while (v) {
		chi.push_back(v % k);
		v /= k;
	}
	while (chi.size() < sz) {
		chi.push_back(0);
	}
	reverse(chi.begin(), chi.end());
	return chi;
}
void solve() {
	cin >> n >> k;
	vector<vector<int>>add(2, vector<int>(sz));
	for (int i = 0; i < n; ++i) {
		vector<int>v = mn(add[(i % 2)], add[(i % 2) ^ 1]);
		if (i % 2 == 1)
			v = mn(v, v_by_chi(i));
		else
			v = pl(v, v_by_chi(i));
		cout << chi_by_v(v) << endl;
		int r;
		cin >> r;
		if (r == 1)
			return;
		if (r == -1) {
			exit(0);
		}
		add[(i % 2) ^ 1] = pl(add[(i % 2) ^ 1], v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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