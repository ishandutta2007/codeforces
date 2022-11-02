#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(2)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
	FAST;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	vector<pll> brr(n);
	for (auto &i : arr) cin >> i;
	for (int i = 0; i < n; ++i) {
		brr[i].s = arr[i];
		brr[i].f = 0;
		while (arr[i] % 2 == 0) ++brr[i].f, arr[i] /= 2;
		while (arr[i] % 3 == 0) --brr[i].f, arr[i] /= 3;
	}
	sort(brr);
	for (int i = 1; i < n; ++i) {
		if (brr[i].s * 3 != brr[i - 1].s && brr[i - 1].s * 2 != brr[i].s) {
			cout << -1;
			return 0;
		} 
	}
	for (auto i : brr) cout << i.s << ' ';
    return 0; 
}