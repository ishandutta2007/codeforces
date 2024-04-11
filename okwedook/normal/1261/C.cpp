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
#include <random>
#include <cassert>
 
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
#define mod 998244353
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

vector<vector<int>> sum;

inline int get(int x, int y) {
	if (x < 0 || y < 0) return 0;
	return sum[x][y];
}

inline int get(int x1, int x2, int y1, int y2) {
	--x1, --y1;
	return get(x2, y2) - get(x2, y1) - get(x1, y2) + get(x1, y1);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    cin >> a;
    sum = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j) {
    		sum[i][j] = a[i][j] == 'X';
    		if (i > 0) sum[i][j] += sum[i - 1][j];
    		if (j > 0) sum[i][j] += sum[i][j - 1];
    		if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
    	}
    int l = -1, r = min(n, m) + 1;
    while (r - l > 1) {
    	int mid = r + l >> 1;
    	int len = mid * 2 + 1;
    	queue<pii> que;
    	vector<vector<int>> dist(n, vector<int>(m, mod));
    	for (int i = 0; i + len <= n; ++i)
    		for (int j = 0; j + len <= m; ++j)
    			if (get(i, i + len - 1, j, j + len - 1) == len * len) {
    				que.push({i + mid, j + mid});
    				dist[i + mid][j + mid] = 0;
    			}
    	static vector<pii> d = {
    		{1, 0},
    		{-1, 0},
    		{0, 1},
    		{0, -1},
    		{1, 1},
    		{1, -1},
    		{-1, 1},
    		{-1, -1}
    	};
    	while (sz(que)) {
    		auto f = que.front();
    		que.pop();
    		for (auto d : d) {
    			pii s = {f.f + d.f, f.s + d.s};
    			if (s.f >= 0 && s.f < n && s.s >= 0 && s.s < m && dist[s.f][s.s] == mod) {
    				dist[s.f][s.s] = dist[f.f][f.s] + 1;
    				que.push(s);
    			}
    		}
    	}
    	bool flag = true;
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < m; ++j)
    			if ((dist[i][j] <= mid) != (a[i][j] == 'X'))
    				flag = false;
    	if (flag) l = mid;
    	else r = mid;
    }
    int len = 2 * l + 1;
   	a = vector<string>(n, string(m, '.'));
   	for (int i = 0; i + len <= n; ++i)
   		for (int j = 0; j + len <= m; ++j)
   			if (get(i, i + len - 1, j, j + len - 1) == len * len)
   				a[i + l][j + l] = 'X';
   	cout << l << '\n';
   	for (auto i : a) cout << i << '\n';
    return 0;
}