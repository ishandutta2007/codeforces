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
const ll maxN = 1 << 20, maxT = 200000, A = 179, K = 450;
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
ll fact[maxN];
ll cnt[maxN];
ll ps[maxN];
ll sq[maxN];
ll cnt_open[maxN];
ll add[maxN];
void build() {
	fact[0] = 1;
	for (int i = 1; i < maxN; ++i)
		fact[i] = fact[i - 1] * i % mod;
}
void solve() {
	build();
	int n;
	cin >> n;
	vector<int>a(n);
	for (auto& x : a) {
		cin >> x;
		++cnt[x];
	}
	sort(a.rbegin(), a.rend());
	ll ans = 1;
	ll mx = 0;
	for (int i = maxN - 3; i > 1; --i) {
		ans = ans * fact[cnt[i]] % mod * fact[cnt[i]] % mod;
		add[i] = (add[i + 2] + cnt[i + 2] * 2) % mod;
		add[i] = (add[i] + cnt[i] - cnt[i + 2]) % mod;
		sq[i] = (sq[i + 2] + add[i]) % mod;
		cnt[i - 2] += cnt[i];
		ps[i - 2] = (ps[i] + cnt[i - 2]) % mod; 
		ll len = cnt[i] + cnt[i - 1];
		ll nw = cnt[i - 2] - cnt[i];
		mx = (mx + sq[i] * nw) % mod;
		mx = (mx + ps[i] * (i - 2) % mod * nw) % mod;
		if (i != 2) {
			mx = (mx + (ps[i] * (i - 2) + sq[i]) % mod * len % mod * 2) % mod;
		}
		else {
			mx = (mx + (ps[i] * (i - 2) + sq[i]) % mod * len % mod) % mod;
			
		}
	}
	ans = ans * fact[cnt[1]] % mod;
	cout << mx << " " << ans << "\n";
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