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
const int INF = -1e9;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 500100, maxT = 1601;
int sz = 1;
vector<pair<int, int>>tree;
void sett(int p, pair<int, int> v) {
	p |= sz;
	tree[p] = max(tree[p], v);
	p >>= 1;
	while (p) {
		tree[p] = max(tree[2 * p], tree[2 * p + 1]);
		p >>= 1;
	}
}
pair<int, int> get(int ql, int qr, int v = 1, int tl = 0, int tr = sz - 1) {
	if (ql > qr)return { 0, INF };
	if (ql <= tl && tr <= qr) {
		return tree[v];
	}
	pair<int, int>mx = { -1,-1 };
	int m = (tr + tl) / 2;
	if (ql <= m)mx = max(mx, get(ql, qr, 2 * v, tl, m));
	if (qr > m)mx = max(mx, get(ql, qr, 2 * v + 1, m + 1, tr));
	return mx;
}
vector<int>tree1;
void sett1(int p, int v) {
	p |= sz;
	tree1[p] = v;
	p >>= 1;
	while (p) {
		tree1[p] = max(tree1[2 * p], tree1[2 * p + 1]);
		p >>= 1;
	}
}
int get1(int ql, int qr, int v = 1, int tl = 0, int tr = sz - 1) {
	if (ql > qr)return 0;
	if (ql <= tl && tr <= qr) {
		return tree1[v];
	}
	int m = (tr + tl) / 2, mx = 0;
	if (ql <= m)mx = max(mx, get1(ql, qr, 2 * v, tl, m));
	if (qr > m)mx = max(mx, get1(ql, qr, 2 * v + 1, m + 1, tr));
	return mx;
}
void solve() {
	int n;
	cin >> n;
	int ans = 0;
	while (sz <= n + 1)sz <<= 1;
	tree.assign(2 * sz, { 0, INF });
	tree1.assign(2 * sz, 0);
	vector<int>a(n + 1, 0);
	vector<int>pre_ans(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sett(0, { 0,n });
	for (int i = 1; i <= n; ++i) {
		pair<int, int> fr = get(0, a[i]);
		++fr.first;
		int i1 = n - fr.second;
		if (get1(a[i] + 1, n + 1) > i1 && fr.second != INF)++fr.first;
		fr.second = n - i;
		ans = max(ans, fr.first);
		sett(a[i], fr);
		sett1(a[i], i);
		pre_ans[i] = fr.first;
	}
	cout << ans << "\n";
	//for (auto x : pre_ans)cout << x << " "; cout << endl;
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