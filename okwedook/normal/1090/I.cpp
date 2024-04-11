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
#define ll long long
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

void solve() {
	ll n, l, r;
	ui x, y, z, b1, b2;
	cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
	vector<ui> b(n);
	b[0] = b1;
	b[1] = b2;
	for (int i = 2; i < n; ++i)
		b[i] = b[i - 2] * x + b[i - 1] * y + z;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		a[i] = ((ll)b[i] % (r - l + 1)) + l;
	ll mn = a[0], ans = 5 * inf;
	for (int i = 1; i < n; ++i) {
		if (mn < a[i]) checkmin(ans, a[i] * mn);
		checkmin(mn, a[i]);
	}
	ll mx = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (mx > a[i]) checkmin(ans, a[i] * mx);
		checkmax(mx, a[i]);
	}
	if (ans == 5 * inf) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
}

int main() {
    FAST; FIXED; RANDOM;
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}