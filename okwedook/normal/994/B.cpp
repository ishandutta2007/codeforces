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
	ll p, c;
	ll ind;
	node() {}
};

bool operator<(const node &a, const node &b) {
	return a.p < b.p;
}

int main() {
    FAST;
    ll n, k;
    cin >> n >> k;
    vector<node> arr(n);
    for (auto &i : arr) cin >> i.p;
    for (auto &i : arr) cin >> i.c;
	vector<ll> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = arr[i].c;
		arr[i].ind = i;
	}
    sort(arr);
	vector<ll> curr;
	vector<ll> add;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && arr[i].p != arr[i - 1].p) {
			for (auto j : add) curr.pb(j);
			add = vector<ll>(0);
			sort(curr);
			reverse(curr);
			while (curr.size() > k) curr.popb();
		}
		for (auto j : curr) ans[arr[i].ind] += j;
		add.pb(arr[i].c);
	}
	for (auto i : ans) cout << i << ' ';
    return 0;
}