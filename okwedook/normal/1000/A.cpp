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
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

ll dist(string a, string b) {
	if (a.size() != b.size()) return inf;
	ll cnt = 0;
	for (int i = 0; i < a.size(); ++i)
		cnt += a[i] != b[i];
	return cnt;
}

signed main() {
	FAST; FIXED;
	ll n;
	cin >> n;
	vector<bool> used1(n), used2(n);
	vector<string> arr1(n), arr2(n);
	for (auto &i : arr1) cin >> i;
	for (auto &i : arr2) cin >> i;
	ll ans = 0;
	for (int times = 0; times < n; ++times) {
		vector<pll> d(n, pll(inf, 0));
		for (int i = 0; i < n; ++i)
			if (!used1[i])
				for (int j = 0; j < n; ++j) 
					if (!used2[j]) {
						ll k = dist(arr1[i], arr2[j]);
						if (k < d[i].f) 
							d[i] = mp(k, j);
					}
		ll ind = 0;
		for (int j = 0; j < n; ++j)
			if (!used1[j]) ind = j;
		for (int j = 0; j < n; ++j)
			if (d[j].f < d[ind].f)
				ind = j;
		used1[ind] = true;
		used2[d[ind].s] = true;
		ans += d[ind].f;
	}
	cout << ans;
    return 0;
}