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
	for (auto &i : arr) cin >> i;
	map<ll, ll> mapp;
	vector<ll> indarr(n);
	for (int i = 0; i < n; ++i) {
		if (mapp.count(arr[i] - 1)) indarr[i] = mapp[arr[i] - 1];
		else indarr[i] = -1;
		mapp[arr[i]] = i;
	}
	vector<ll> cnt(n);
	for (int i = 0; i < n; ++i)
		cnt[i] = (indarr[i] == -1 ? 0 : cnt[indarr[i]]) + 1;
	ll ans = 0, ind = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > ans) {
			ans = cnt[i];
			ind = i;
		}
	}
	vector<ll> ansarr(ans);
	for (int i = 0; i < ans; ++i) {
		ansarr[i] = ind + 1;
		ind = indarr[ind];
	}
	--ans;
	reverse(ansarr);
	cout << ansarr.size() << '\n';
	for (auto &i : ansarr) cout << i << ' ';
    return 0;
}