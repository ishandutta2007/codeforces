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
int a[maxN];
int pr[maxN];
int le[maxN];
vector<int>vi[maxN];
int sz = maxN;
int t[2 * maxN];
void sett(int l, int r, int vll) {
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1) {
			t[l] = min(t[l], vll);
			++l;
		}
		if (r % 2 == 0) {
			t[r] = min(t[r], vll);
			--r;
		}
	}
}
int n;
int get(int v) {
	int r = n;
	for (v += sz; v; v >>= 1)r = min(r, t[v]);
	return r;
}
void solve() {
	cin >> n;
	fill(t, t + 2 * sz, n);
	fill(le, le + n, INF);
	for (int i = 2; i < maxN; ++i) {
		if (pr[i] != 0)
			continue;
		for (int j = i; j < maxN; j += i)pr[j] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			while (a[i] > 1) {
				vi[pr[a[i]]].push_back(i);
				a[i] /= pr[a[i]];
			}
		}
		else {
			while (a[i] > 1) {
				if (vi[pr[a[i]]].empty()) {
					le[i] = 0;
				}
				else {
					le[i] = min(le[i], vi[pr[a[i]]].back() + 1);
					vi[pr[a[i]]].pop_back();
				}
				a[i] /= pr[a[i]];
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		if (le[i] == INF)continue;
		sett(le[i], i, i);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += get(i) - i;
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