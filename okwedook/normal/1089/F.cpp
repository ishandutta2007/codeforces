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
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

void check(ll n, ll a1, ll b1, ll a2, ll b2) {
	if (!(n % b1 == 0 && n % b2 == 0)) return;
	//cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
    ll f = a1 * b2 + a2 * b1;
    ll s = b2 * b1;
    ll g = __gcd(f, s);
    f /= g;
    s /= g;
    if (s - f == 1 && s % b1 == 0 && s % b2 == 0 && s == n) {
    	cout << "YES\n";
    	cout << 2 << '\n';
    	cout << a1 << ' ' << b1 << '\n';
    	cout << a2 << ' ' << b2 << '\n';
    	exit(0);
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int b1 = 2; b1 * b1 <= n; ++b1) 
    	if (n % b1 == 0) {
    		for (int a1 = 1; a1 < b1; ++a1) {
    			int b2 = n / b1;
    			//a1 * b2 + a2 * b1 / b1 * b2
    			ll s = (ll)b1 * (ll)b2;
    			ll f = s - s / n;
    			int a2 = (f - a1 * b2) / b1;
    			check(n, a1, b1, a2, b2);
    		}
    	}
    cout << "NO";
    return 0;
}