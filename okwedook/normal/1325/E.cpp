#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#ifdef DEBUG
	mt19937 gen(857204);
#else
	mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

const int N = 1e6 + 100;
int mind[N];

vector<int> dec(int x) {
	map<int, int> cnt;
	while (x > 1) {
		cnt[mind[x]]++;
		x /= mind[x];
	}
	vector<int> ans;
	for (auto i : cnt)
		if (i.s % 2 == 1)
			ans.pb(i.f);
	if (sz(ans) == 1) ans.insert(ans.begin(), 1);
	return ans;
}

signed main() {
	FAST; FIXED;
	for (int i = 2; i * i < N; ++i)
		if (mind[i] == 0)
			for (int j = i * i; j < N; j += i)
				mind[j] = i;
	int cnt = 0;
	for (int i = 1; i < N; ++i)
		if (mind[i] == 0) mind[i] = i, ++cnt;
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;
	set<int> one;
	int ans = mod;
	vector<pii> edge;
	graph G(N), rev(N);
	for (auto i : a) {
		auto d = dec(i);
		if (sz(d) == 0) {
			checkmin(ans, 1);
		} 
		if (sz(d) == 2) {
			G[d[0]].pb(d[1]);
			G[d[1]].pb(d[0]);
		}
	}
	for (int i = 0; i < sz(G); ++i) {
		sort(G[i]);
		for (int j = 1; j < sz(G[i]); ++j)
			if (G[i][j] == G[i][j - 1])
				checkmin(ans, 2);
	}
	vector<int> d, p;
	auto bfs = [&](int v) {
		queue<int> que;
		d.assign(sz(G), mod);
		p.assign(sz(G), -1);
		que.push(v);
		p[v] = v;
		d[v] = 0;
		while (sz(que)) {
			auto f = que.front();
			que.pop();
			for (auto i : G[f])
				if (p[i] == -1) {
					p[i] = f;
					d[i] = d[f] + 1;
					que.push(i);
				}
		}
	};
	for (int s = 0; s < sqrt(sz(G)); ++s) {
		if (sz(G[s]) || sz(rev[s])) {
			bfs(s);
			for (int i = 0; i < sz(G); ++i) {
				for (auto j : G[i])
					if (p[i] != j && p[j] != i) {
						checkmin(ans, d[i] + d[j] + 1);
					}
			}
		}
	}
	cout << (ans > n ? -1 : ans);
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}