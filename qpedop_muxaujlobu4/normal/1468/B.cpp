#pragma comment(linker, "/STACK:9759095000")
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
//#define double long double
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
vector<int>f;
vector<ll>dp;
vector<ll>s;
int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	dp[a] += dp[b];
	s[a] += s[b];
	f[b] = a;
}
vector<ll>k;
int give_y(int x) {
	if (x != find(x))return -1;
	ll ct = dp[x];
	ll sum = s[x];
	int b = -1, e = k.size();
	while (b + 1 != e) {
		int mid = (b + e) / 2;
		if (k[mid] * ct < sum)b = mid;
		else e = mid;
	}
	return b;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll>a(n);
	k.assign(m, 0);
	f.assign(n, 0);
	dp.assign(n, 1);
	s.assign(n, 0);
	for (int i = 0; i < n; ++i)f[i] = i;
	for (auto& x : a)cin >> x;
	for (auto& x : k)cin >> x;
	vector<set<int>>to_uni(m);
	for (int i = 0; i < n; ++i) {
		s[i] = a[i];
		int y = give_y(i);
		if (y == -1)continue;
		to_uni[y].insert(i);
	}
	ll mx = 1;
	vector<int>ans(m);
	for (int i = m - 1; i >= 0; --i) {
	//sort(to_uni[i].begin(), to_uni[i].end());
		for (auto x : to_uni[i]) {
			if (x != find(x))continue;
			while (x + dp[x] != n && s[x] > k[i] * dp[x]) {
				uni(x, x + dp[x]);
			}
			if (x + dp[x] != n) {
				int y = give_y(x);
				if (y != -1 && y < i) {
					to_uni[y].insert(x);
				}
			}
			mx = max(mx, dp[x]);
		}
		ans[i] = mx - 1;
	}
	for (auto x : ans)cout << x << " "; cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}