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

struct node {
	ll x, d;
	node() {}
	node(ll x, ll d) {
		this->x = x;
		this->d = d;
	}
};

bool operator<(const node &a, const node &b) {
	if (a.x == b.x) return a.d > b.d;
	return a.x < b.x;
}

signed main() {
	ll n;
	cin >> n;
	vector<node> arr;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		arr.pb(node(l, 1));
		arr.pb(node(r + 1, -1));
	}
	vector<ll> ans(n);
	ll curr = -1;
	sort(arr);
	for (int i = 1; i < arr.size(); ++i) {
		curr += arr[i - 1].d;
		if (curr >= 0) 
			ans[curr] += arr[i].x - arr[i - 1].x;
	}
	for (auto i : ans) cout << i << ' ';
    return 0;
}