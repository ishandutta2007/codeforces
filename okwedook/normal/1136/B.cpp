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

int t(vector<int> &cnt, int from, int to) {
	int ans = cnt[from];
	cnt[from] = 0;
	cnt[to] += ans;
	return ans;
}

int solve(int n, int k, int at, int to) {
	--k;
	if (at == k) return mod;
	vector<int> cnt(n, 1);
	int ans = t(cnt, k, at);
	int pos = k;
	for (int i = k - 1; i >= to; --i) {
		++ans;
		ans += t(cnt, i, k);
		pos = i;
	}
	for (int i = k + 1; i <= to; ++i) {
		++ans;
		ans += t(cnt, i, k);
		pos = i;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i)
		if (i != k && cnt[i]) {
			flag = true;
		}
	if (flag) {
		for (int i = pos - 1; i >= 0; --i) {
			++ans;
			if (i < k) ans += t(cnt, i, k);
		}
		for (int i = pos + 1; i < n; ++i) {
			++ans;
			if (i > k) ans += t(cnt, i, k);
		}
	}
	return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, k;
    cin >> n >> k;
    int ans = mod;
    for (int i = 0; i < n; i += n - 1)
    	for (int j = 0; j < n; j += n - 1) {
    		checkmin(ans, solve(n, k, i, j));
    		//cout << ans << '\n';
    	}
    cout << ans + n;
    return 0;
}