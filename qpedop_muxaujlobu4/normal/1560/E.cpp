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
const int mod = 998244353;
const double eps = 4.5e-9, pi = acos(-1);
const ll maxN = 100010, maxT = 600100, A = 179, K = 170;
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
	cout << "No\n";
	exit(0);
}
void solve() {
	string s;
	cin >> s;
	vector<int>cnt(26), lst(26, -1);
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		++cnt[s[i] - 'a'];
		lst[s[i] - 'a'] = i;
	}
	int lett = 0;
	for (auto x : cnt)lett += x != 0;
	int len = 0;
	vector<pair<int, int>>tt;
	vector<pair<int, char>>tt1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i]) {
			tt1.push_back({ lst[i],'a' + i });
			tt.push_back({ lst[i],cnt[i] });
		}
	}
	sort(tt.rbegin(), tt.rend());	
	sort(tt1.begin(), tt1.end());
	for (auto x : tt) {
		/*if (x.second % lett != 0) {
			cout << "-1\n";
			return;
		}*/
		len += x.second / lett--;
	}
	string ss = s.substr(0, len);



	string aa;
	string t;
	for (auto x : tt1) {
		t += ss;
		aa.push_back(x.second);
		string tmp;
		for (auto b : ss)if (b != x.second)tmp.push_back(b);
		ss = tmp;
	}
	if (t == s) {
		cout << s.substr(0, len) << " " << aa << "\n";
	}
	else cout << "-1\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
2 2
1 1
1 1 2 1
2 1 2
*/