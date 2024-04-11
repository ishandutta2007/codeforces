#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

hashmap<ll, pll> mymap;

void add(ll x, ll ind) {
	mymap[x].s = ind;
	if (mymap[x].f == 1) {
		mymap[x].f = 0;
		add(2 * x, ind);
	} else ++mymap[x].f;
}

int main() {
	FAST;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i;
	for (int i = 0; i < n; ++i) add(arr[i], i);
	vector<pll> newvec;
	for (auto i : mymap) 
		if (i.s.f == 1) {
			newvec.pb(mp(i.s.s, i.f));
		}
	sort(newvec.begin(), newvec.end());
	cout << newvec.size() << '\n';
	for (auto i : newvec) cout << i.s << ' ';
    return 0;
}