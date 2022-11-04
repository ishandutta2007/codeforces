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
const int mod = 998244353;
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 2020, maxT = 100100, A = 179, mid = 150;
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
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<int>>ps(4, vector<int>(n + 1));
	for (int i = 0; i < n; ++i) {
		ps[0][i + 1] = ps[0][i];
		ps[1][i + 1] = ps[1][i];
		ps[2][i + 1] = ps[2][i];
		ps[3][i + 1] = ps[3][i];
		if (s[i] == '?')continue;
		int add = 0;
		if (i % 2 == 0)add = 2;
		++ps[add + s[i] - '0'][i + 1];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll b = -1, e = i;
		while (b + 1 != e) {
			ll m = (b + e) / 2;
			if ((ps[0][i] == ps[0][m] && ps[3][i] == ps[3][m])
				|| (ps[1][i] == ps[1][m] && ps[2][i] == ps[2][m]))e = m;
			else b = m;
		}
		ans += i - e;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}