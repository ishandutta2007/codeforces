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

vector<vector<pii>> go;
map<char, char> rev = {
	{'R', 'L'},
	{'L', 'R'},
	{'U', 'D'},
	{'D', 'U'}
};

map<pii, char> d = {
	{{-1, 0}, 'U'},
	{{1, 0}, 'D'},
	{{0, -1}, 'L'},
	{{0, 1}, 'R'}
};

int n;
vector<vector<bool>> used;
vector<vector<char>> ans;

void dfsmark(int x, int y, pii check, char path = 'X') {
	if (x < 0 || x >= n || y < 0 || y >= n || used[x][y] || go[x][y] != check) return;
	used[x][y] = true;
	ans[x][y] = path;
	for (auto i : d)
		dfsmark(x + i.f.f, y + i.f.s, check, rev[i.s]);
}

bool dfscycle(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || go[x][y].f != -1) return false;
	if (used[x][y]) return true;
	used[x][y] = true;
	for (auto i : d) {
		if (dfscycle(x + i.f.f, y + i.f.s)) {
			ans[x][y] = i.s;
			return true;
		}
	}
	return false;
}

signed main() {
	FAST; FIXED;
	cin >> n;
	go = vector<vector<pii>>(n, vector<pii>(n));
	used = vector<vector<bool>>(n, vector<bool>(n));
	ans = vector<vector<char>>(n, vector<char>(n));
	for (auto &i : go) {
		for (auto &j : i) {
			cin >> j;
			if (j.f != -1)
				--j.f, --j.s;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!used[i][j] && pii(i, j) == go[i][j])
				dfsmark(i, j, go[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!used[i][j] && go[i][j] == pii(-1, -1)) {
				if (!dfscycle(i, j)) {
					cout << "INVALID";
					return 0;
				}
			}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!used[i][j]) {
				cout << "INVALID";
				return 0;
			}
	cout << "VALID\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << ans[i][j];
		cout << '\n';
	}
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}