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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 400100, maxT = 61, A = 179, mid = 150;
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
	cout << "-1" << endl;
	exit(0);
}
vector<vector<int>>g;
vector<int>used1, used2;
vector<int>col;
vector<ll>a, b;
ll dfs1(int v) {
	used1[v] = 1;
	ll ans = b[v] - a[v];
	for (auto x : g[v]) {
		if (!used1[x]) {
			ans += dfs1(x);
		}
	}
	return ans;
}
vector<ll>sum;
bool dfs2(int v, int color) {
	sum[color] += b[v] - a[v];
	used2[v] = 1;
	col[v] = color;
	bool ans = true;
	for (auto x : g[v]) {
		if (used2[x]) {
			ans &= col[v] != col[x];
		}
		else {
			ans &= dfs2(x, color ^ 1);
		}
	}
	return ans;
}
void solve(){
	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	used1.assign(n, 0);
	used2.assign(n, 0);
	a.assign(n, 0);
	b.assign(n, 0);
	col.assign(n, 0);
	for (auto& x : a)cin >> x;
	for (auto& x : b)cin >> x;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		if (used1[i])
			continue;
		ans &= abs(dfs1(i)) % 2 == 0;
		sum.assign(2, 0);
		if (!dfs2(i, 0)) {
			continue;
		}
		ans &= sum[0] == sum[1];
	}
	if (ans)cout << "YES\n";
	else cout << "NO\n";
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
		solve();
	}
	return 0;
}