#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(all(arr)); }
template<class T1> inline void rsort(T1 &arr) { sort(rall(arr)); }
template<class T1> inline void reverse(T1 &arr) { reverse(all(arr)); }
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

struct group {
	vector<ll> costs;
	void sort() {
		rsort(costs);
	}
	void add(ll x) {
		costs.pb(x);
	}
	ll pop() {
		ll ans = costs.back();
		costs.popb();
		return ans;
	}
	size_t size() {
		return costs.size();
	}
};

bool operator<(const group &a, const group &b) {
	if (a.costs.size() != b.costs.size()) return a.costs.size() > b.costs.size();
	if (a.costs.size() == 0) return false;
	return a.costs.back() < b.costs.back();
}
vector<group> arr;
ll curr = 0;
ll ans = inf, paid = 0;

void check() {
	vector<ll> carr;
	for (auto &i : arr)
		for (auto &j : i.costs)
			carr.pb(j);
	sort(carr);
	for (int i = 1; i < carr.size(); ++i) carr[i] += carr[i - 1];
	ll count = 0;
	if (arr.size() > 0 && arr[0].size() >= curr)
		count = carr[arr[0].size() - curr];
	checkmin(ans, paid + count);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<pll> free;
    map<ll, ll> cnt;
    hashmap<ll, group> groups;
    for (int i = 0; i < n; ++i) {
    	pll a;
    	cin >> a.f >> a.s;
    	if (a.f == 1) ++curr;
    	else groups[a.f].add(a.s);
    }
    for (auto &i : groups) i.s.sort();
    for (auto i : groups) arr.pb(i.s);
    sort(arr);
	check();
	while (arr.size() > 0 && arr[0].size() > 0) {
		paid += arr[0].pop();
		++curr;
		sort(arr);
		check();
	}
	cout << ans;
    return 0;
}