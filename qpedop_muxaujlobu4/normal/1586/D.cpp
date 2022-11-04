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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 20010, maxT = 3010, A = 179, K = 420;
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
	cout << "No solution\n";
	exit(0);
}
int qw(vector<int>a) {
	cout << "? ";
	for (auto x : a)cout << x << " ";
	cout << endl;
	int v;
	cin >> v;
	return v;
}
void solve() {
	int n;
	cin >> n;
	vector<int>qq;
	vector<int>ans(n, -1);
	ans.back() = 1;
	for (int i = 2; i <= n; ++i) {
		vector<int>q(n, i);
		q.back() = 1;
		int v = qw(q);
		if (v == 0)break;
		++ans.back();
		qq.push_back(v - 1);
	}
	int tmp = ans.back() - 1;
	for (auto x : qq)ans[x] = tmp--;
	qq.push_back(n - 1);
	tmp = ans.back();
	vector<int>v1;
	for (int i = 2; i <= n; ++i) {
		vector<int>q(n, 1);
		for (auto x : qq)q[x] = i;
		for (auto x : v1)q[x] = n;
		int v = qw(q);
		if (v == 0)break;
		ans[v - 1] = ++tmp;
		v1.push_back(v - 1);
	}

	cout << "! ";
	for (auto x : ans)cout << x << " ";
	cout << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.in", "r", stdin); freopen("input.out", "w", stdout);
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