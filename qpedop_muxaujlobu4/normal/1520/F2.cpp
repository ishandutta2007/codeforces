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
const ll maxN = 200010, maxT = 2500, A = 179, mid = 150;
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
int qw(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int v;
	cin >> v;
	if (v == -1) {
		exit(0);
	}
	return v;
}
void solve() {
	int n, q;
	cin >> n >> q;
	int q0;
	cin >> q0;
	vector<int>a((n + 15) / 16);
	for (int i = 1; i <= n; i += 16) {
		int l = i;
		int r = min(n, i + 15);
		a[l / 16] = r - qw(1, r);
	}
	for (int i = (int)a.size() - 1; i > 0; --i) {
		a[i] -= a[i - 1];
	}
	while (q--) {
		/*if (q == 0) {
			exit(1234);
		}*/
		int k;
		if (q0 != -1) {
			k = q0;
			q0 = -1;
		}
		else 
			cin >> k;
		int l = 0, sum = a[0];
		while (sum < k) {
			sum += a[++l];
		}
		--a[l];
		l *= 16;
		int r = min(n, l + 16);
		while (l + 1 != r) {
			int m = (l + r) / 2;
			if (m - qw(1, m) >= k) {
				r = m;
			}
			else l = m;
		}
		cout << "! " << r << endl;
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}