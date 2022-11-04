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
void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	set<int>t;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1')t.insert(i);
	}
	if (t.empty()) {
		cout << s << "\n";
		return;
	}
	int v = *t.begin();
	for (int i = 0; i < m; ++i) {
		if (v - i - 1 < 0)
			break;
		s[v - i - 1] = '1';
	}
	v = *t.rbegin();
	for (int i = 0; i < m; ++i) {
		if (v + i + 1 >= n)
			break;
		s[v + i + 1] = '1';
	}
	while (t.size() > 1) {
		v = *t.begin();
		t.erase(t.begin());
		int tmp = *t.begin();
		++v;
		--tmp;
		for (int cnt = 0; cnt < m && v < tmp; ++cnt, ++v, --tmp) {
			s[v] = s[tmp] = '1';
		}
	}
	cout << s << "\n";
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