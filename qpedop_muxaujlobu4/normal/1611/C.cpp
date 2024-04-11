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
pair<deque<int>, deque<int>>run(deque<int>a) {
	int n = a.size();
	deque<int>res;
	for (int i = 0; i < n - 1; ++i) {
		if (a.front() < a.back()) {
			res.push_front(a.front());
			a.pop_front();
		}
		else {
			res.push_back(a.back());
			a.pop_back();
		}
	}
	deque<int>r1 = res;
	r1.push_back(a.back());
	res.push_front(a.back());
	return { res,r1 };
}
void solve() {
	int n;
	cin >> n;
	deque<int>a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	deque<int>dd, et = a;
	dd.push_back(a.back());
	a.pop_back();
	for (int i = 0; i < n - 1; ++i) {
		if (a.front() > a.back()) {
			dd.push_front(a.front());
			a.pop_front();
		}
		else {
			dd.push_back(a.back());
			a.pop_back();
		}
	}
	deque<int>f, s;
	tie(f, s) = run(dd);
	if (f == et || s == et) {
		for (int i = 0; i < n; ++i) {
			cout << dd.front() << " ";
			dd.pop_front();
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; ++i)dd.pop_front();
	a = et;
	dd.push_back(a.front());
	a.pop_front();
	for (int i = 0; i < n - 1; ++i) {
		if (a.front() > a.back()) {
			dd.push_front(a.front());
			a.pop_front();
		}
		else {
			dd.push_back(a.back());
			a.pop_back();
		}
	}
	//deque<int>f, s;
	tie(f, s) = run(dd);
	if (f == et || s == et) {
		for (int i = 0; i < n; ++i) {
			cout << dd.front() << " ";
			dd.pop_front();
		}
		cout << "\n";
		return;
	}
	cout << "-1\n";
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