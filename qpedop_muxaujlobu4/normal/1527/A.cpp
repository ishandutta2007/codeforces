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
	int n;
	cin >> n;
	int ans = 1;
	while (ans * 2 <= n)ans <<= 1;
	cout << ans - 1 << "\n";
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