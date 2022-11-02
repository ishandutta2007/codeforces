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
#define mod 998244353
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int N = 1e5 + 10;
const int MAXN = 1e9 + 10;

struct Fenv {
    gp_hash_table<int, int> fenv[N];
    void add(int r, int x) {
        for (; r < N; r |= r + 1)
            for (int i = x; i < MAXN; i |= i + 1)
                ++fenv[r][i];
    }
    int get(int r, int x) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
                if (fenv[r].find(i) != fenv[r].end()) ans += fenv[r][i];
        return ans;
    }
    int get(int r, int y, int x) {
        return get(r, x) - get(r, y - 1);
    }
    int get(int l, int r, int y, int x) {
        return get(r, y, x) - get(l - 1, y, x);
    }
} fenv;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int mx = 0;
    for (auto i : arr) checkmax(mx, i);
    for (int i = 0; i < n; ++i) fenv.add(i, arr[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != mx) continue;
        int l = i, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (fenv.get(i, m, mx, mx) == m - i + 1) l = m;
            else r = m;
        }
        checkmax(ans, r - i);
        i = l;
    }
    cout << ans;
    return 0;
}