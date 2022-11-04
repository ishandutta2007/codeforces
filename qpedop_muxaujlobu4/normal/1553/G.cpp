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
const ll maxN = 200010, maxT = 801, A = 179, mid = 150;
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
bool is_it_prime(int v) {
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0)
			return false;
	return true;
}
int f[maxN];
int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	f[a] = b;
}
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int>p;
	for (int i = 2; i <= 1000; ++i)
		if (is_it_prime(i))p.push_back(i);
	vector<int>a(n);
	vector<int>dl(1 << 20, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		f[i] = i;
		int t = a[i];
		for (auto x : p) {
			if (t % x != 0)
				continue;
			if (dl[x] == -1)
				dl[x] = i;
			else 
				uni(dl[x], i);
			while (t % x == 0)
				t /= x;
		}
		if (t == 1)
			continue;
		if (dl[t] == -1)
			dl[t] = i;
		else 
			uni(dl[t], i);
	}
	vector<int>color(1 << 20, -1);
	set<pair<int, int>>st;
	vector<vector<int>>to_u(1 << 20);
	for (int i = 0; i < n; ++i) {
		if (color[a[i] + 1] != -1)
			continue;
		color[a[i] + 1] = find(i);
		to_u[a[i] + 1].push_back(color[a[i] + 1]);
	}
	for (int j = 2; j < (1 << 20); ++j) {
		if (dl[j] == -1)
			continue;
		int cl = find(dl[j]);
		for (int k = j; k < (1 << 20); k += j) {
			if (color[k] == -1 || color[k] == cl)
				continue;
			to_u[k].push_back(cl);
		}
	}
	for (int j = 2; j < (1 << 20); ++j) {
		int sz = to_u[j].size();
		for (int i = 0; i < sz; ++i) {
			for (int k = 0; k < i; ++k) {
				int a = to_u[j][i];
				int b = to_u[j][k];
				if (a > b)swap(a, b);
				if (a == b)
					continue;
				st.insert({ a,b });
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		a = find(a);
		b = find(b);
		if (a == b)
			cout << "0\n";
		else
			if (st.count({ min(a,b),max(a,b) }))
				cout << "1\n";
			else cout << "2\n";
	}

}
int32_t main()
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}