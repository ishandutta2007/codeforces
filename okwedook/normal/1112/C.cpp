#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <random>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(15);
#define RANDOM srand(3654765)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>> 
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a)	a.rbegin(), a.rend()
#define shuffle(a) \
	for (int i = 0; i < n; ++i) \
		swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }

const int MAXN = 5e5 + 10;

struct box {
	int need[MAXN], now[MAXN];
	int curr = 0;
	box() { for (int i = 0; i < MAXN; ++i) need[i] = mod; }
	void addnow(int x) {
		if (now[x] < need[x] && now[x] + 1 >= need[x]) ++curr;
		++now[x];
	}
	void decnow(int x) {
		if (now[x] >= need[x] && now[x] - 1 < need[x]) --curr;
		--now[x];
	}
};

signed main() {
	FAST; FIXED; RANDOM;
	int n, k, m, s;
	cin >> m >> k >> n >> s;
	vector<int> a(m), b(s);
	cin >> a >> b;
	map<int, int> cnt;
	for (auto i : b) ++cnt[i];
	int l = 0, r = 0;
	box curr;
	for (auto i : cnt) curr.need[i.f] = i.s;
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		int j = (m - n * k - i % k + k) + i;
		checkmin(j, m);
		if (j <= i) continue;
		while (r < j) curr.addnow(a[r++]);
		while (l < i) curr.decnow(a[l++]);
		while (r > j) curr.decnow(a[--r]);
		if (curr.curr == sz(cnt)) {
			for (int i = 0; i < MAXN; ++i) curr.need[i] %= mod;
			for (int j = 0; j < i % k; ++j) ans.pb(i - j - 1);
			int c = j - i - k;
			for (int t = i; t < j; ++t) {
				if (c > 0 && curr.need[a[t]] == 0) ans.pb(t), --c;
				else --curr.need[a[t]];
			}
			cout << sz(ans) << '\n';
			for (auto i : ans) cout << i + 1 << ' ';
			return 0;
		} 
	}
	cout << -1;
	return 0;
}