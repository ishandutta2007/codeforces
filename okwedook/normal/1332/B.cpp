#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return x >= 2;
}

vector<int> primes;

vector<int> primedivs(int x) {
    vector<int> ans;
    for (auto i : primes) {
        if (x % i == 0) {
            ans.pb(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans.pb(x);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    set<int> st;
    for (auto i : a)
        for (auto j : primedivs(i)) 
            st.insert(j);
    vector<int> ans(n);
    int m = 0;
    for (auto i : st) {
        vector<int> ind;
        for (int j = 0; j < n; ++j)
            if (ans[j] == 0 && a[j] % i == 0)
                ind.pb(j);
        if (sz(ind)) {
            ++m;
            for (auto i : ind)
                ans[i] = m;
        }
    }
    cout << m << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    FAST; FIXED;
    for (int i = 1; i * i <= 1000; ++i)
        if (prime(i)) primes.pb(i);
    int t;
    cin >> t;
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}