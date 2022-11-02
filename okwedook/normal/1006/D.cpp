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

signed main() {
	FAST;
	ll n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	ll ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		map<char, ll> st1, st2, st;
		st1[s1[i]]++;
		st2[s2[i]]++;
		st1[s1[n - i - 1]]++;
		st2[s2[n - i - 1]]++;
		st[s1[i]]++;
		st[s2[i]]++;
		st[s1[n - i - 1]]++;
		st[s2[n - i - 1]]++;
		vector<ll> arr, arr1, arr2;
		for (auto i : st) arr.pb(i.s);
		for (auto i : st1) arr1.pb(i.s);
		for (auto i : st2) arr2.pb(i.s);
		sort(arr1);
		sort(arr2);
		sort(arr);
		if (arr.size() == 2) {
			if (arr[0] == arr[1]) continue;
			++ans;
		}
		else if (arr.size() == 3) {
			if (arr1.size() == 1) ans += 2;
			else ++ans;
		}
		else if (arr.size() == 4) ans += 2;
	}
	if (n & 1) {
		if (s1[n / 2] != s2[n / 2]) ++ans;
	}
	cout << ans;
	return 0; 
}