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
const ll maxN = 200010, maxT = 61, A = 179, mid = 150;
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
ll tree[maxN << 2];
int sz = 1;
void sett(int v, int vl) {
	v |= sz;
	tree[v] = vl;
	v >>= 1;
	while (v) {
		tree[v] = tree[2 * v] + tree[2 * v + 1];
		v >>= 1;
	}
}
int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		return tree[v];
	}
	int m = (tr + tl) / 2;
	int res = 0;
	if (ql <= m) {
		res += get(ql, qr, tl, m, 2 * v);
	}
	if (qr > m) {
		res += get(ql, qr, m + 1, tr, 2 * v + 1);
	}
	return res;
}
void solve(){
	string s;
	cin >> s;
	int n = s.length();
	map<char, vector<int>>mp;
	for (int i=0;i<n;++i) {
		mp[s[i]].push_back(i);
	}
	sz = 1;
	while (sz < n) {
		sz <<= 1;
	}
	vector<char>bb = { 'A','N','T','O' };
	sort(bb.begin(), bb.end());
	ll ans = -1;
	string res;
	do {
		for (int i = 0; i < n; ++i) {
			sett(i, 1);
		}
		ll tmp = 0;
		string tt;
		for (auto b : bb) {
			for (int i = 0; i < mp[b].size(); ++i) {
				tt.push_back(b);
				sett(mp[b][i], 0);
				tmp += get(0, mp[b][i]);
			}
		}
		if (tmp > ans) {
			ans = tmp;
			res = tt;
		}
	} while (next_permutation(bb.begin(), bb.end()));
	//cout << ans << "\n";
	cout << res << "\n";

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