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

struct node {
	ll x, ind;
	bool type;
	node() {}
	node(ll x, ll ind, bool type) {
		this->x = x;
		this->ind = ind;
		this->type = type;
	}
};
vector<ll> endd;

bool operator<(node a, node b) {
	if (a.x != b.x) return a.x < b.x;
	return endd[a.ind] > endd[b.ind];
}

int main() {
	FAST;
	ll n;
	cin >> n;
	vector<node> arr;
	endd = vector<ll> (n);
	for (ll i = 0; i < n; ++i) {
		ll u, v;
		cin >> u >> v;
		endd[i] = v;
		arr.pb(node(u, i, true));
		arr.pb(node(v, i, false));
	}
	sort(arr);
	ll mx = -inf, ind = -1;
	for (auto i : arr) {
		if (i.type) {
			if (mx < endd[i.ind]) mx = endd[i.ind], ind = i.ind;
			else {
				cout << i.ind + 1 << ' ' << ind + 1;
				return 0;
			}
		}
	}
	cout << "-1 -1";
    return 0; 
}