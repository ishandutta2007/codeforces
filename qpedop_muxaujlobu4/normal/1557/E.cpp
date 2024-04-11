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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 100100, maxT = 519, A = 179, mid = 150, K = 350;
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
	cout << "No\n";
	exit(0);
}
int mx = 0, mn = 0;
bool qw(int x, int y, int &ps) {
	swap(x, y);
	cout << x << " " << y << endl;
	string s;
	cin >> s;
	/*if (s.length() > 4) {
		s = s.substr(s.length() - 4);
	}*/
	int r = 0;
	if (s == "Right")++r;
	if (s == "Down-Right")++r;
	if (s == "Up-Right")++r;
	if (s == "Up-Left")--r;
	if (s == "Down-Left")--r;
	if (s == "Left")--r;
	ps += r;
	mx = max(mx, ps);
	mn = min(mn, ps);
	if (s == "Done")false;
	return true;
}
void solve() {
	int ps = 0;
	mx = mn = 0;
	int px = 1, py = 8;
	if (!qw(px, py, ps))return;
	const vector<int>bb = { 4,5,3,6,2,7,1,8 };
	for (auto i : bb) {
		int j = i + ps;
		if (i + mx > 8 || i + mn < 1)
			continue;
		int tox, toy = 2;
		int lst = ps;
		if (j >= 5) {
			tox = 7;
			if (px != j - 1) {
				if (!qw(px = j - 1, py, ps))
					return;
			}
		}
		else {
			tox = 2;
			if (px != j + 1) {
				if (!qw(px = j + 1, py, ps))
					return;
			}
		}
		int addx = 1;
		if (tox < px)addx = -1;
		while (px != tox || py != toy) {
			if ((ps - lst == addx && px != tox) || py == toy) {
				lst = ps;
				if (py == toy && px + 2 * addx == tox)addx *= 2;
				if (!qw(px = px + addx, py, ps))
					return;
			}
			else {
				int addy = -1;
				if (px == tox && py + 2 * addy == toy)addy *= 2;
				if (!qw(px, py = py + addy, ps))
					return;
			}
		}
		if (!qw(px, py = 8, ps))
			return;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}