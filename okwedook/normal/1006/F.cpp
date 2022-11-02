#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 998244353
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
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<vector<ll>> arr;
vector<vector<ll>> from, to;
hashmap<ll, ll> useddown;
hashmap<ll, ll> usedup;
ll n, m, k;

void dfsdown(int i, int j, ll currsum) {
	if (i == 0 && j == 0) {
		useddown[currsum]++;
		return;
	}
	if (i > 0) dfsdown(i - 1, j, currsum ^ arr[i - 1][j]);
	if (j > 0) dfsdown(i, j - 1, currsum ^ arr[i][j - 1]);
}

void dfsup(int i, int j, ll currsum) {
	if (i == n - 1 && j == m - 1) {
		usedup[currsum]++;
		return;
	}
	if (i < n - 1) dfsup(i + 1, j, currsum ^ arr[i + 1][j]);
	if (j < m - 1) dfsup(i, j + 1, currsum ^ arr[i][j + 1]);
}

signed main() {
	FAST;
	cin >> n >> m >> k;
	arr = vector<vector<ll>> (n, vector<ll>(m));
	from = to = vector<vector<ll>> (20);
	for (auto &i : arr)
		for (auto &j : i)
			cin >> j;
	ll ans = 0;
	/*if (n - 1  + m - 1 < 19) {
		dfsup(0, 0, arr[0][0]);
		cout << usedup[k];
		return 0;
	}*/
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (i + j == n - 1) {
				useddown.clear();
				usedup.clear();
				dfsdown(i, j, arr[i][j]);
				dfsup(i, j, arr[i][j]);
				for (auto t : useddown) 					
					ans += t.s * usedup[k ^ t.f ^ arr[i][j]];
			}
	cout << ans;
	return 0; 
}