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
#include <complex>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(94385)
#define ll int
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
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
const int N = 5e5 + 10;
const int B = 300;

void read(int &a) {
    static char c;
    c = getchar();
    if (c == '-') {
        a = 0;
        while (c = getchar(), c >= '0')
            a = (a << 3) + (a << 1) + (c - '0');
        a = -a;
    } else {
        a = c - '0';
        while (c = getchar(), c >= '0')
            a = (a << 3) + (a << 1) + (c - '0');
    }
}
 
void read(char &c) {
    c = getchar();
    getchar();
}
 
void read(string &s) {
    s = "";
    static char c;
    while (c = getchar(), c >= 'a')
        s += c;
}
 
void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
 
void print(char c) {
    putchar(c);
}
 
signed main() {
    FAST;
    vector<vector<ll>> a(B, vector<ll>(B));
    vector<int> curr(N);
    int q;
    read(q);
    for (int i = 0; i < q; ++i) {
        int mode, x, y;
        read(mode);
        read(x);
        read(y);
        if (mode == 1) {
            --x;
            curr[x] += y;
            for (int d = 1; d < B; ++d)
                a[d][x % d] += y;
        } else {
            y += x - 1;
            y %= x;
            if (x >= B) {
                ll ans = 0;
                for (; y < N; y += x) ans += curr[y];
                print(ans);
                putchar('\n');
            } else {
                print(a[x][y]);
                putchar('\n');
            }
        }
    }
    return 0;
}