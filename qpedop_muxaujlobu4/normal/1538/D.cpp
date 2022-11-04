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
vector<ll>p;
void bld() {
	vector<int>tr(maxN);
	for (int i = 2; i < maxN; ++i) {
		if (tr[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < maxN; j += i)
			tr[j] = 1;
	}
}
void solve() {
	ll a, b, k;
	cin >> a >> b >> k;
	vector<ll>va, vb, vg;
	ll g = gcd(a, b);
	ll ta = a, tb = b, tg = g;
	for (auto x : p) {
		while (a % x == 0) {
			va.push_back(x);
			a /= x;
		}
		while (b % x == 0) {
			vb.push_back(x);
			b /= x;
		}
		while (g % x == 0) {
			vg.push_back(x);
			g /= x;
		}
	}
	if (a != 1) {
		va.push_back(a);
	}
	if (b != 1) {
		vb.push_back(b);
	}
	if (g != 1) {
		vg.push_back(g);
	}
	if (k > va.size() + vb.size() || k == 1 && ta != tg && tb != tg
		|| k == 1 && ta == tb || k == 0 && ta != tb) {
		cout << "NO\n";
	}
	else cout << "YES\n";
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
	bld();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}