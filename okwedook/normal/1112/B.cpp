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

signed main() {
	FAST; FIXED; RANDOM;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	cin >> a;
	vector<pii> segm;
	set<pii> st;
	for (int i = 0; i < k; ++i)
		st.insert({0, i});
	for (int i = 0; i < n; ++i) {
		auto fr = *st.begin();
		st.erase(fr);
		segm.pb({fr.f, fr.f + a[i]});
		fr.f += a[i];
		st.insert(fr);
	}
	vector<ll> sum(151 * n);
	for (auto i : segm) ++sum[i.s];
	for (int i = 1; i < sz(sum); ++i) sum[i] += sum[i - 1];
	int ans = 0;
	for (auto s : segm) {
		bool check = false;
		for (int i = s.f; i < s.s; ++i) {
			int percent = round(100.0 * sum[i] / n);
			if (percent == i - s.f + 1) check = true;
		}
		ans += check;
	}
	cout << ans;
	return 0;
}