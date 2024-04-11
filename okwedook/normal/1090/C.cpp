#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll int
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

struct bag : public set<ll> {
	int ind;
};

bool cmp(const bag &a, const bag &b) {
	return sz(a) > sz(b);
}

int main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<bag> arr(n);
    ll sumb = 0;
    for (int i = 0; i < n; ++i) {
    	int c;
    	cin >> c;
    	sumb += c;
    	for (int j = 0; j < c; ++j) {
    		int k;
    		cin >> k;
    		arr[i].insert(k);
    	}
    	arr[i].ind = i;
    }
	sort(all(arr), cmp);
	vector<int> f(n);
	for (int i = 0; i < n; ++i)
		f[i] = sumb / n + (sumb % n > i);
	int ptra = 0, ptrb = n - 1;
	vector<vector<int>> ans;
	while (ptra < ptrb && sz(arr[ptra]) > f[ptra]) {
		ll x = *(arr[ptra].begin());
		while (sz(arr[ptra]) > f[ptra] && sz(arr[ptrb]) < f[ptrb]) {
			if (!arr[ptrb].count(x)) {
				arr[ptra].erase(x);
				arr[ptrb].insert(x);
				ans.pb({arr[ptra].ind, arr[ptrb].ind, x});
			}
			auto it = arr[ptra].upper_bound(x);
			if (it == arr[ptra].end()) break; 
			x = *it;
		}
		if (sz(arr[ptra]) == f[ptra]) ++ptra;
		if (sz(arr[ptrb]) == f[ptrb]) --ptrb;
	}
	cout << sz(ans) << '\n';
	for (auto i : ans)
		cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] << '\n';
    return 0;
}