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

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	cin >> s;
	sort(all(s), [](const string &a, const string &b) {
		return sz(a) < sz(b);
	});
	map<char, int> cnt;
	for (auto i : s)
		for (auto j : i)
			cnt[j]++;
	int ans = 0;
	for (auto s : s) {
		for (int l = 0, r = sz(s) - 1; l <= r; ++l, --r) {
			if (l == r) {
				if (cnt['1'] == 0 || cnt['0'] > 0 && cnt['0'] % 2 == 1) --cnt['0'];
				else --cnt['1'];
			} else {
				if (cnt['0'] < 2 && cnt['1'] < 2) goto go;
				if (cnt['0'] >= 2) cnt['0'] -= 2;
				else cnt['1'] -= 2;
			}
		}
		++ans;
	}
	go: cout << ans << '\n';
}

signed main() {
	FAST; FIXED; RANDOM;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}