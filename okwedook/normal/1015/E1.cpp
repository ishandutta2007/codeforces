#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<class T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<class T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

ll dp[1000][1000][4], flag[1000][1000][2];

signed main() {
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (auto &i : arr) cin >> i;
	for (int i = 0; i < n; ++i) {
		ll curr = 0;
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.') curr = 0;
			else curr++;
			dp[i][j][0] = curr;
		}
		curr = 0;
		for (int j = m - 1; j >= 0; --j) {
			if (arr[i][j] == '.') curr = 0;
			else curr++;
			dp[i][j][1] = curr;
		}
	}
	for (int j = 0; j < m; ++j) {
		ll curr = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i][j] == '.') curr = 0;
			else curr++;
			dp[i][j][2] = curr;
		}
		curr = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (arr[i][j] == '.') curr = 0;
			else curr++;
			dp[i][j][3] = curr;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			ll t = inf;
			for (int k = 0; k < 4; ++k)
				checkmin(t, dp[i][j][k]);
			--t;
			if (t > 0) {
				flag[i][j - t][0]++;
				if (j + t + 1 < m) flag[i][j + t + 1][0]--;
				flag[i - t][j][1]++;
				if (i + t + 1 < n) flag[i + t + 1][j][1]--;
			}
		}
	vector<string> check(n, string(m, '.'));
	for (int i = 0; i < n; ++i) {
		ll curr = 0;
		for (int j = 0; j < m; ++j) {
			curr += flag[i][j][0];
			if (curr) check[i][j] = '*';
		}
	}
	for (int j = 0; j < m; ++j) {
		ll curr = 0;
		for (int i = 0; i < n; ++i) {
			curr += flag[i][j][1];
			if (curr) check[i][j] = '*';
		}
	}
	if (check != arr) {
		cout << -1;
		return 0;
	}
	vector<pair<pll, ll>> ans;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			ll t = inf;
			for (int k = 0; k < 4; ++k)
				checkmin(t, dp[i][j][k]);
			--t;
			if (t > 0) {
				ans.pb(mp(mp(i + 1, j + 1), t));
			}
		}
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i.f.f << ' '  << i.f.s << ' ' << i.s << '\n';
	return 0;
}