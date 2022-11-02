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

signed main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	a.pb(0);
	a.pb(m);
	sort(a);
	n = a.size();
	vector<ll> plus(n), minus(n), prefp(n), prefm(n);
	ll past = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) plus[i] = a[i] - past;
		else minus[i] = a[i] - past;
		past = a[i];
	}
	prefp[0] = plus[0];
	prefm[0] = minus[0];
	for (int i = 1; i < n; ++i) {
		prefp[i] = plus[i] + prefp[i - 1];
		prefm[i] = minus[i] + prefm[i - 1];
	}
	ll ans = prefp[n - 1];
	for (int i = 0; i < n - 1; ++i) 
		if (a[i] + 1 < a[i + 1]) {
			ll k = prefp[i] + prefm[n - 1] - prefm[i + 1] + ((i & 1) ? a[i + 1] - a[i] - 1 : 1);
			if (k > ans) {
				ans = k;
			}
		}
	for (int i = 1; i < n; ++i) 
		if (a[i] - 1 > a[i - 1]) {
			ll k = prefp[i - 1] + prefm[n - 1] - prefm[i] + ((i & 1) ? 1 : a[i] - a[i - 1] - 1);
			if (k > ans) {
				ans = k;
			}
		}
	cout << ans;
    return 0;
}