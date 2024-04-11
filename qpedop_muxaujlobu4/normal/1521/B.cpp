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
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 250010, maxT = 4010, A = 179, mid = 150;
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
void inc(ll x, ll& y, ll z) {
	while (gcd(x, y) != 1 || gcd(y, z) != 1) {
		++y;
	}
}
void solve() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (auto& x : a)
		cin >> x;
	vector<tuple<ll, ll, ll, ll>>ans;
	ll mn = a[0];
	int id = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < mn) {
			mn = a[i];
			id = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i == id)continue;
		if (i % 2 == id % 2) {
			ans.push_back({ i,id,mn,mn });
		}
		else {
			ans.push_back({ i,id,mn + 1,mn });
		}
	}

	cout << ans.size() << "\n";
	for (auto x : ans) {
		ll x1, x2, x3, x4;
		tie(x1, x2, x3, x4) = x;
		cout << x1 + 1 << " " << x2 + 1 << " " << x3 << " " << x4 << "\n";
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
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}