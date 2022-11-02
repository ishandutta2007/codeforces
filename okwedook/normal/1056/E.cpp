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

const ll p = 37;

ll add(ll &h, char c) {
	h = (h * p + c) % mod;
}

ll pp[2000000];
ll pref[2000000];

ll sum(ll a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

ll dif(ll a, ll b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

ll mul(ll a, ll b) {
	a *= b;
	a %= mod;
	return a;
}

ll get(ll r) {
	if (r < 0) return 0;
	return pref[r];
}

ll get(ll l, ll r) {
	return dif(get(r), mul(get(l - 1), pp[r - l + 1]));
}

signed main() {
    FAST; FIXED; RANDOM;
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    ll cnt0 = 0, cnt1 = 0;
    for (auto i : s)
    	if (i == '0') ++cnt0;
    	else ++cnt1;
    pp[0] = 1;
    for (int i = 1; i < m; ++i) {
    	pp[i] = (pp[i - 1] * p) % mod;
    }
    ll currh = 0;
    for (int i = 0; i < m; ++i) {
    	add(currh, t[i]);
    	pref[i] = currh;
    }
    int ans = 0;
    for (ll len0 = 1; len0 < m; ++len0) 
    	if ((m - len0 * cnt0) % cnt1 == 0) {
	    	ll len1 = (m - len0 * cnt0) / cnt1;
	    	if (len1 <= 0) continue;
	    	int ptr = 0;
	    	vector<int> st0, st1;
	    	for (auto i : s) 
	    		if (i == '0') {
	    			st0.pb(get(ptr, ptr + len0 - 1));
	    			ptr += len0;
	    		} else {
	    			st1.pb(get(ptr, ptr + len1 - 1));
	    			ptr += len1;
	    		}
	    	bool flag = true;
	    	for (int i = 1; i < sz(st0); ++i)
	    		flag &= st0[i] == st0[0];
	    	for (int i = 1; i < sz(st1); ++i)
	    		flag &= st1[i] == st1[0];
	    	flag &= st1[0] != st0[0];
	    	ans += flag;
	    }
	cout << ans;
    return 0;
}