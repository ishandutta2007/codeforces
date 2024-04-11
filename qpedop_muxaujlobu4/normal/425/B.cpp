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
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
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
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 200015, maxT = 2e9, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
int trivial_solution(int n, int m, vector<vector<int>>a, int k) {
	int res = INF;
	for (int msk = 0; msk < (1 << n); ++msk) {
		int tmpr = 0;
		vector<int>b(n);
		for (int j = 0; j < n; ++j)b[j] = ((msk & (1 << j)) != 0);
		for (int j = 0; j < m; ++j) {
			int c1 = 0, c2 = 0;
			for (int i = 0; i < n; ++i) {
				if (b[i] == a[i][j])++c1;
				else ++c2;
			}
			tmpr += min(c1, c2);
		}
		res = min(res, tmpr);
	}
	if (res > k)res = -1;
	return res;
}
int ct(vector<int>a, vector<int>b, int bit) {
	int res = 0;
	for (int i = 0; i < a.size(); ++i) {
		if ((a[i] ^ b[i]) != bit)++res;
	}
	return res;
}
int solution(int n, int m, vector<vector<int>>a, int k) {
	int res = INF;
	for (auto vec : a) {
		int tmpr = 0;
		for (auto v : a) {
			tmpr += min(ct(vec, v, 0), ct(vec, v, 1));
		}
		res = min(res, tmpr);
	}
	if (res > k)res = -1;
	return res;
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>>a(n, vector<int>(m));
	for (auto& vec : a) {
		for (auto& x : vec)cin >> x;
	}
	int res;
	if (n <= k) {
		res = trivial_solution(n, m, a, k);
	}
	else {
		res = solution(n, m, a, k);
	}
	cout << res << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("labyrinth.in", "r", stdin); freopen("labyrinth.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
// 1 1 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3