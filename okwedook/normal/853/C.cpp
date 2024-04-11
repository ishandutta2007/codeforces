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
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
struct chash {
    const int RANDOM = gen();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};
 
const int N = 2e5 + 100;
 
struct Fenv2D {
    static const int n = 1 << 18;
    vector<int> t[2 * n + 1];
    void add(int r, int p) {
        t[r + n].pb(p);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            t[i].resize(sz(t[i + i]) + sz(t[i + i + 1]));
            merge(all(t[i + i]), all(t[i + i + 1]), t[i].begin());
        }
    }
    int cnt(int v, int r) {
        return upper_bound(all(t[v]), r) - t[v].begin();
    }
    int get(int r, int r2) {
        int l = 0;
        l += n;
        r += n + 1;
        int ans = 0;
        while (l < r) {
            if (l & 1) ans += cnt(l++, r2);
            if (r & 1) ans += cnt(--r, r2);
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
} t;
 
template<class T>
struct Fenv {
    vector<T> sum;
    Fenv(int n) {
        sum = vector<int>(n);
    }
    void add(int i, int x) {
        sum[i] += x;
    }
    void build() {
        for (int i = 1; i < sz(sum); ++i)
            sum[i] += sum[i - 1];
    }
    int get(int l, int r) {
        checkmin(r, sz(sum) - 1);
        return l <= 0 ? sum[r] : sum[r] - sum[l - 1];
    }
};
 
signed main() {
    FAST; FIXED;
    int n, q;
    cin >> n >> q;
    Fenv<int> sumx(n), sumy(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        swap(i, p);
        t.add(i, p);
        sumx.add(i, 1);
        sumy.add(p, 1);
        swap(i, p);
    }
    t.build();
    sumx.build();
    sumy.build();
    vector<vector<int>> poss = {
        {0,0,1,1},
        {0,0,1,2},
        {0,0,2,1},
        {0,0,2,2},
        {0,1,1,0},
        {0,1,1,1},
        {0,1,1,2},
        {0,1,2,0},
        {0,1,2,1},
        {0,1,2,2},
        {0,2,1,0},
        {0,2,1,1},
        {0,2,2,0},
        {0,2,2,1},
        {1,0,1,1},
        {1,0,1,2},
        {1,0,2,1},
        {1,0,2,2},
        {1,1,1,2},
        {1,1,2,0},
        {1,1,2,1},
        {1,1,2,2},
        {1,2,2,0},
        {1,2,2,1}
    };
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        --y1, --x1, --y2, --x2;
        vector<vector<ll>> sum(3, vector<ll>(3));
        sum[0][0] = t.get(x1 - 1, y1 - 1);
        sum[0][1] = t.get(x1 - 1, y2);
        sum[0][2] = sumx.get(0, x1 - 1);
        sum[1][0] = t.get(x2, y1 - 1);
        sum[1][1] = t.get(x2, y2);
        sum[1][2] = sumx.get(0, x2);
        sum[2][0] = sumy.get(0, y1 - 1);
        sum[2][1] = sumy.get(0, y2);
        sum[2][2] = n;
        for (int i = 2; i >= 0; --i)
            for (int j = 2; j >= 0; --j) {
                if (i > 0) sum[i][j] -= sum[i - 1][j];
                if (j > 0) sum[i][j] -= sum[i][j - 1];
                if (i > 0 && j > 0) sum[i][j] += sum[i - 1][j - 1];
            }
        ll ans = sum[1][1] * (sum[1][1] - 1) / 2;
        for (auto &v : poss)
            ans += sum[v[0]][v[1]] * sum[v[2]][v[3]];
        cout << ans << '\n';    
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}