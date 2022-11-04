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
typedef long double ld;
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
const int maxN = 500100, maxT = 1601;
vector<int>f;
int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return false;
	f[a] = b;
	return true;
}
void solve() {
	ll s_ans = INF, f_ans = -INF, k, n, m;
	cin >> n >> m >> k;
	f.assign(n, 0);
	for (int i = 0; i < n; ++i)f[i] = i;
	vector<tuple<ll ,int, int>>edg(m);
	set<int>vl;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		vl.insert(c);
		--a;
		--b;
		edg[i] = make_tuple(c, a, b);
	}
	sort(edg.begin(), edg.end());
	for (auto x : vl)s_ans = min(s_ans, abs(x - k));
	int ct = 0;
	for (auto x : edg) {
		if (ct + 1 == n)break;
		ll cs;
		int a, b;
		tie(cs, a, b) = x;
		if (cs >= k && f_ans == -INF)f_ans = 0, s_ans = -INF;
		if (uni(a, b)) {
			f_ans += max(0LL, cs - k);
			++ct;
		}
	}
	cout << max(f_ans, s_ans) << "\n";
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}