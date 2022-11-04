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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 400100, maxT = 61, A = 179, mid = 150;
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
	cout << "-1" << endl;
	exit(0);
}
void solve() {
	ll n, m, x, y;
	cin >> n >> m >> x >> y;
	tuple<ll, ll, ll, ll, ll>ans = make_tuple(-1, -1, -1, -1, -1);
	vector < pair<ll, ll>>pt;
	pt.push_back({ 1,1 });
	pt.push_back({ 1,m });
	pt.push_back({ n,1 });
	pt.push_back({ n,m });
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			ll x1, y1, x2, y2;
			tie(x1, y1) = pt[i];
			tie(x2, y2) = pt[j];
			ans = max(ans, make_tuple(abs(x - x1) + abs(x - x2) + abs(x1 - x2)
				+ abs(y - y1) + abs(y - y2) + abs(y1 - y2), x1, y1, x2, y2));
		}
	}
	ll x1, y1, x2, y2;
	tie(x, x1, y1, x2, y2) = ans;
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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