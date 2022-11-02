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

void read(int &x) {
	static char c;
	c = getchar();
	if (c == '-') {
		x = 0;
		while ((c = getchar()) >= '0')
			x = (x << 3) + (x << 1) + (c - '0');
		x = -x;
	} else {
		x = c - '0';
		while ((c = getchar()) >= '0')
			x = (x << 3) + (x << 1) + (c - '0');
	}
}

void print(int x) {
	if (x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}

const int N = 1e6 + 1;
int a[N], ind[N];
bool used[N];

void solve() {
	int n;
	read(n);
	for (int i = 0; i < n; ++i) read(a[i]), used[i] = false;
	int v = 0, pind = 0;
	while (!used[v]) {
		used[v] = true;
		ind[pind++] = v;
		v -= a[v];
	}
	bool flag = false;
	for (int i = 0; ; ++i)
		if (ind[i] == v) {
			print(pind - i);
			putchar('\n');
			for (int j = i; j < pind; ++j)
				print(ind[j] + 1), putchar(' ');
			putchar('\n');
			return;
		}
}

signed main() {
	FAST; RANDOM;
	int t;
	read(t);
	while (t--) solve();
	return 0;
}