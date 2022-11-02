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
#include <random>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(94385)
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
int red[300][66000], blue[300][66000];
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pair<char, pii>> a(n);
    int add = 0;
    pii left = {0, 0};
    for (int i = 0; i < n; ++i) {
        char c;
        int r, b;
        cin >> c >> r >> b;
        if (r >= n || b >= n) {
            left.f += max(0, r - n);
            left.s += max(0, b - n);
            checkmin(r, n);
            checkmin(b, n);
        }
        a[i] = {c, {r, b}};
    }
    add = max(left.f, left.s);
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 66000; ++j)
            red[i][j] = blue[i][j] = mod;
    red[min(n * n, add - left.f)][0] = blue[min(n * n, add - left.s)][0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        pii cnow = {0, 0};
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) 
                ++(a[i].f == 'R' ? cnow.f : cnow.s);
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) {
                --(a[i].f == 'R' ? cnow.f : cnow.s);
                int past = mask ^ (1 << i);
                pii cost = a[i].s;
                cost.f = max(0, cost.f - cnow.f);
                cost.s = max(0, cost.s - cnow.s);
                for (int pc = 0; pc <= n * n; ++pc) {
                    if (cost.f - pc < cost.s) {
                        int d = cost.s;
                        if (pc + d - cost.f <= n * n)
                            checkmin(red[pc + d - cost.f][mask], red[pc][past] + d + 1);
                    } else {
                        int d = cost.f - pc;
                        checkmin(blue[d - cost.s][mask], red[pc][past] + d + 1);
                    }
                    if (cost.s - pc < cost.f) {
                        int d = cost.f;
                        if (pc + d - cost.s <= n * n)
                            checkmin(blue[pc + d - cost.s][mask], blue[pc][past] + d + 1);
                    } else {
                        int d = cost.s - pc;
                        checkmin(red[d - cost.f][mask], blue[pc][past] + d + 1);
                    }
                }
                ++(a[i].f == 'R' ? cnow.f : cnow.s);
            }
    }
    int ans = mod;
    for (int i = 0; i < 300; ++i)
        checkmin(ans, min(red[i][(1 << n) - 1], blue[i][(1 << n) - 1]));
    cout << ans + add;
    return 0;
}