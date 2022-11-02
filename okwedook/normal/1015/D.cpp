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

signed main() {
	ll n, k, s;
	cin >> n >> k >> s;
	if ((n - 1) * k < s || k > s) {
		cout << "NO";
		return 0;
	}
	vector<ll> ans;
	ll curr = 1;
	while (s > n - 1 && s - (n - 1) >= k - 1) {
		if (curr == 1) curr = n;
		else curr = 1;
		s -= n - 1;
		--k;
		ans.pb(curr);
	}
	while (k > 1) {
		if (curr == n - 1 || curr == 1) ++curr;
		else --curr;
		ans.pb(curr);
		--k;
		--s;
	}
	if (s > 0) {
		if (curr >= n - 1) ans.pb(curr - s);
		else ans.pb(curr + s);
	}
	if (ans[ans.size() - 1] > n || ans[ans.size() - 1] < 1) {
		while (ans[ans.size() - 1] < 1) ans[ans.size() - 1] += n;
		while (ans[ans.size() - 1] > n) ans[ans.size() - 1] -= n;
	}
	cout << "YES" << '\n';
	for (auto i : ans) cout << i << ' ';
	return 0;
}