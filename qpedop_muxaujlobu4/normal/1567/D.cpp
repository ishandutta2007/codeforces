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
const int mod = 1000000007;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 500048, maxT = 600100, A = 179, K = 170;
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
vector<string>a;
int vl(string s) {
	int r = 0;
	for (auto x : s) {
		r += x - '0';
	}
	return r;
}
int rec(string s, int n) {
	int y = s.size() - 1, res = 0;
	//?????????????????
	while (vl(s) < n) {
		int yy = s.size() - 1;
		while (s[yy] == '0')--yy;
		string t = "1";
		ll pw = 1;
		for (int j = yy + 1; j < s.size(); ++j) {
			t.push_back('0');
			pw *= 10;
		}
		ll vv = stoi(s) - pw;
		if (vv == 0 && pw != 1) {
			pw /= 10;
			vv = 9 * pw;
			t = to_string(pw);
			s = to_string(vv);
			int tmp = rec(t, max(1LL, min(pw, (ll)n - vl(s))));
			n -= tmp;
			res += tmp;
		}
		else {
			s = to_string(vv);
			int tmp = rec(t, max(1LL, min(pw, (ll)n - vl(s))));
			n -= tmp;
			res += tmp;
		}
	}
	y = s.size() - 1;
	for (int i = y; i >= 0; --i) {
		while (n > 1 && s[i] != '0') {
			--n;
			--s[i];
			++res;
			string t = "1";
			for (int j = i + 1; j < s.size(); ++j)
				t.push_back('0');
			a.push_back(t);
		}
	}
	a.push_back(s);
	++res;
	return res;
}
void solve() {
	string s;
	int n;
	cin >> s >> n;
	a.clear();
	rec(s, n);
	for (auto x : a)
		cout << x << " ";
	cout << "\n";
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