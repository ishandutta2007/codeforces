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
bool debugg = 0;
vector<int>anss = { 9, 10, 19, 7, 16, 18, 11, 14,
15, 6, 20, 8, 17, 4, 5, 3, 12, 2, 13, 1, };
map<vector<int>, int>mp;
int qw(int a, int b, int c) {
	vector<int>q = { a,b,c };
	sort(q.begin(), q.end());
	if (mp.count(q))return mp[q];
	if (!debugg) {
		cout << "? ";
		for (auto x : q)cout << x << " ";
		cout << endl;
	}
	int v;
	if (debugg) {
		--a, --b, --c;
		vector<int>qq;
		qq.push_back(abs(anss[a] - anss[b]));
		qq.push_back(abs(anss[c] - anss[b]));
		qq.push_back(abs(anss[a] - anss[c]));
		sort(qq.begin(), qq.end());
		v = qq[1];
	}
	else
		cin >> v;
	if (v == -1)
		exit(0);
	return mp[q] = v;
}
// mt_rand()
void solve(int numb = 0) {
	mp.clear();
	int n;
	cin >> n;
	if (debugg) {
		anss.assign(n, 0);
		for (auto& x : anss)cin >> x;
	}
	int f = -1, s = -1;
	int mn = INF;
	for (int i = 0; i < 13 && f == -1; ++i) {
		for (int j = i + 1; j < 13 && f == -1; ++j) {
			for (int k = j + 1; k < 13; ++k) {
				int v = qw(i + 1, j + 1, k + 1);
				mn = min(mn, v);
				if (v <= (n - 4) / 6) {
					f = i + 1;
					s = j + 1;
					break;
				}
			}
		}
	}
	if (f == -1) {
		exit(n);
	}
	/*do {
		int i = mt_rand() % n + 1;
		int j = mt_rand() % n + 1;
		int k = mt_rand() % n + 1;
		if (i == j || j == k || i == k)
			continue;
		if (qw(i, j, k) <= (n - 4) / 6)
			f = i, s = j;
	} while (f == -1);*/
	vector<int>res(n);
	int mx = 0, i_mx = -1;
	for (int i = 0; i < n; ++i) {
		if (i + 1 == f || i + 1 == s)continue;
		res[i] = qw(i + 1, f, s);
		if (res[i] > mx) {
			mx = res[i];
			i_mx = i + 1;
		}
	}
	vector<int>one, two;
	for (int i = 0; i < n; ++i) {
		if (res[i] + 2 == mx) {
			two.push_back(i + 1);
		}
		if (res[i] + 1 == mx) {
			one.push_back(i + 1);
		}
	}
	f = -1, s = -1;
	for (auto x : one) {
		for (auto y : two) {
			if (qw(x, y, i_mx) == 1) {
				f = x;
				s = i_mx;
			}
		}
	}
	if (f == -1) {
		exit(1234);
	}
	res.assign(n, 0);
	res[f - 1] = 2;
	res[s - 1] = 1;
	for (int i = 1; i <= n; ++i) {
		if (f == i || s == i)continue;
		res[i - 1] = qw(f, s, i) + 2;
	}
	if (res[0] > res[1]) {
		for (auto& x : res)x = n - x + 1;
	}
	cout << "! ";
	for (auto x : res)cout << x << " ";
	cout << endl;
	int v;
	cin >> v;
	if (v == -1) {
		exit(0);
	}
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
		solve(t);
	}
	return 0;
}