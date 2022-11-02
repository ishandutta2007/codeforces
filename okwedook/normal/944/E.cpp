#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }    
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

const int N = 1e5 + 100;

struct Fenv {
    int fenv[N];
    void add(int r, int x) {
        for (; r < N; r |= r + 1) fenv[r] += x;
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ans += fenv[r];
        return ans;
    }
};

struct LIS {
    int val[N];
    LIS() {
        for (int i = 0; i < N; ++i) val[i] = mod;
    }
    int add(int x) {
        int l = -1, r = N - 1;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (val[m] > x) r = m;
            else l = m;
        }
        val[r] = x;
        return r;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> m >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    Fenv fenv;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        fenv.add(l, 1);
        fenv.add(r + 1, -1);
    }
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = fenv.get(i);
    vector<int> inc(n), dec(n);
    LIS pref, suff;
    for (int i = 0; i < n; ++i) 
        inc[i] = pref.add(arr[i]);
    for (int i = n - 1; i >= 0; --i) 
        dec[i] = suff.add(arr[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) checkmax(ans, inc[i] + dec[i] + 1);
    cout << ans;
    return 0;
}