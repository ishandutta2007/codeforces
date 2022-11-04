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
const ll INF = 1000000007;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200100, maxT = 510, A = 179, K = 450;
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
map<pair<ll, ll>, ll>mp;
ll qw(ll l, ll r) {
	/*if (l >= 2) {
		if (l == 2)++l;
		return (r - l + 1) * (r - l) / 2;
	}
	if (r <= 3) {
		if (r == 3)--r;
		return (r - l + 1) * (r - l) / 2;
	}
	else {
		l = 3;
		return (r - l + 1) * (r - l) / 2 + 1;
	}*/
	if (mp.count({ l,r }))return mp[{l, r}];
	if (l < 1)return -1;
	cout << "? " << l << " " << r << endl;
	ll v;
	cin >> v;
	if (v == -1)exit(0);
	return mp[{l, r}] = v;
}
pair<bool, int> find_l(ll cnt) {
	ll l = 1, r = INF;
	while (l + 1 != r) {
		ll m = (l + r) / 2;
		if (m * (m - 1) / 2 <= cnt)l = m;
		else r = m;
	}
	return { l * (l - 1) / 2 == cnt,l };
}
void solve() {
	mp.clear();
	ll n;
	cin >> n;
	ll cnt = qw(1, n);
	ll l = 1, r = n;
	while (l + 1 != r) {
		ll m = (l + r) / 2;
		ll tmp = qw(1, m);
		if (tmp == 0) {
			l = m;
			continue;
		}
		if (tmp == cnt) {
			r = m;
			continue;
		}
		bool fl;
		ll len;
		tie(fl, len) = find_l(tmp);
		if (!fl) {
			r = m;
			continue;
		}
		if (!find_l(cnt - tmp).first) {
			l = m;
			continue;
		}
		else {
			if (qw(m - len + 1, m) == tmp) {
				l = m;
			}
			else r = m;
		}
	}
	ll tmp = qw(1, r);
	ll tt = find_l(tmp).second;
	while (!find_l(tmp).first || qw(r - tt + 1, r) != tmp) {
		--r;
		tmp = qw(1, r);
		tt = find_l(tmp).second;
	}
	cout << "! " << r - tt + 1 << " " << r + 1 << " " << r + find_l(cnt - tmp).second << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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