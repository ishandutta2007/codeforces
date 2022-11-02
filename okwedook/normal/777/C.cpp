#pragma GCC optimize("O3", "unroll-loops")

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

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;
    vector<pii> arr;
    for (int j = 0; j < m; ++j) {
    	int past = 0, cnt = 0;
    	for (int i = 0; i < n; ++i) {
    		if (a[i][j] >= past) ++cnt;
    		else arr.pb({i - cnt, i - 1}), cnt = 1;
    		past = a[i][j];
    	}
    	if (cnt > 0) arr.pb({n - cnt, n - 1});
    }
    sort(arr);
    int sum = 0;
    for (int i = 1; i < sz(arr); ++i) checkmax(arr[i].s, arr[i - 1].s);
    int k;
	cin >> k;
	while (k--) {
		int askl, askr;
		cin >> askl >> askr;
		--askl, --askr;
		int l = -1, r = sz(arr);
		while (r - l > 1) {
			int m = r + l >> 1;
			if (arr[m].f > askl) r = m;
			else l = m;
		}
		if (l == -1 || arr[l].s < askr) cout << "No\n";
		else cout << "Yes\n";
	}
    return 0;
}