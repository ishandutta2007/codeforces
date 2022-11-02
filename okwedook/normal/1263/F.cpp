#pragma GCC optimize("O3", "unroll-all-loops")
//#pragma GCC target("avx2")
 
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
#include <random>
#include <cassert>
#include <complex>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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

struct Tree {
	vector<int> tin, tout, par, sub;
	graph tree;
	int currt = 0;
	Tree(int n) {
		tin = tout = par = sub = vector<int>(n, -1);
		tree = graph(n);
	}
	void add(int p, int v) {
		par[v] = p;
	}
	void process(int v) {
		int start = currt++;
		while (v != -1 && tin[v] == -1) {
			tin[v] = start;
			if (par[v] != -1) tree[par[v]].pb(v);
			v = par[v];
		}
	}
	int dfs(int v = 0) {
		tout[v] = tin[v];
		sub[v] = 1;
		for (auto i : tree[v]) {
			tout[v] = dfs(i);
			sub[v] += sub[i];
		}
		return tout[v];
	}
};

int n;

void read(vector<vector<pii>> &ans) {
	int sz;
	cin >> sz;
	Tree t(sz);
	for (int i = 1; i < sz; ++i) {
		int p;
		cin >> p;
		t.add(p - 1, i); 
	}
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		t.process(v - 1);
	}
	t.dfs();
	for (int i = 0; i < sz; ++i)
		ans[t.tout[i]].pb({t.tin[i], t.sub[i] - (i == 0)});
}
 
signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    vector<vector<pii>> segm(n);
    read(segm);
    read(segm);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
    	for (auto segm : segm[i]) {
    		int l = segm.f;
    		int r = i;
    		int c = segm.s;
    		checkmax(dp[r], (l == 0 ? 0 : dp[l - 1]) + c);
    	}
    }
    cout << dp.back();
    return 0;
}