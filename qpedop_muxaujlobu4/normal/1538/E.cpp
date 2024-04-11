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
struct my_s {
	ll ans;
	string preff, syff;

	my_s(string s = "b") {
		ans = 0;
		for (int i = 0; i < min(4, (int)s.length()); ++i) {
			preff.push_back(s[i]);
		}
		int sz = s.length();
		for (int i = max(0, sz - 4); i < sz; ++i) {
			syff.push_back(s[i]);
		}
		for (int i = 0; i + 4 <= sz; ++i) {
			if (s[i] == 'h' && s[i + 1] == 'a'
				&& s[i + 2] == 'h' && s[i + 3] == 'a')++ans;
		}
	}
	my_s(my_s l, my_s r) {
		ans = l.ans + r.ans;
		preff = l.preff;
		for (int i = 0; i < r.preff.size(); ++i) {
			if (preff.size() < 4) {
				preff.push_back(r.preff[i]);
			}
		}
		syff = "";
		int need = 4 - r.syff.size();
		for (int i = max(0, (int)l.syff.size() - need); i < l.syff.size(); ++i)
			syff.push_back(l.syff[i]);
		syff += r.syff;
		int sz = l.syff.size();
		string ss = l.syff + r.preff;
		for (int i = max(0, sz - 3); i < sz; ++i) {
			if (i + 4 > ss.size())break;
			if (ss[i] == 'h' && ss[i + 1] == 'a'
				&& ss[i + 2] == 'h' && ss[i + 3] == 'a')++ans;
		}
	}
};
void solve() {
	int q;
	cin >> q;
	string lst = "";
	map<string, my_s>mp;
	while (q--) {
		cin >> lst;
		string op;
		cin >> op;
		if (op == ":=") {
			string nw;
			cin >> nw;
			mp[lst] = my_s(nw);
		}
		else {
			string l, r, p;
			cin >> l >> p >> r;
			mp[lst] = my_s(mp[l], mp[r]);
		}
	}
	cout << mp[lst].ans << "\n";
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
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}