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
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
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
 
template<class It>
void countadd(It l1, It r1, It l2, It r2, ll &cnt, ll &cntrev) {
    for (; l2 != r2; ++l2) {
        while (l1 != r1 && *l1 < *l2) {
            cntrev += r2 - l2;
            ++l1;
        }
        while (l1 != r1 && *l1 == *l2) {
            cntrev += r2 - l2 - 1;
            ++l1;
        }
        cnt += r1 - l1;
    }
}
 
void read(int &x) {
    static char c;
    while (c = getchar(), c >= '0')
        x = (x << 3) + (x << 1) + (c - '0');
}
 
void print(ll x) {
    if (x >= 10) {
        ll nx = x / 10;
        print(nx);
        putchar(x - nx * 10 + '0');
    } else {
        putchar(x + '0');
    }
}
 
template<class It, class Out>
void mymerge(It l1, It r1, It l2, It r2, Out pt) {
    while (true) {
        if (l1 == r1) {
            if (l2 == r2) break;
            *pt++ = *l2++;
        } else {
            *pt++ = *(l2 == r2 || *l1 < *l2 ? l1 : l2)++;
        }
    }
}

int a[(1 << 20) + 5], b[(1 << 20) + 5], curr[21];
ll cnt[2][21];
 
signed main() {
    FAST; FIXED; RANDOM;
    int n = 0;
    read(n);
    int sz = 1 << n;
    for (int i = 0; i < sz; ++i) read(a[i]);
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < (1 << n); i += (1 << l)) {
            auto left = a + i;
            auto mid = left + (1 << l - 1);
            auto right = left + (1 << l);
            countadd(left, mid, mid, right, cnt[0][l], cnt[1][l]);
            mymerge(left, mid, mid, right, b + i);
        }
        for (int i = 0; i < sz; ++i) a[i] = b[i];
    }
    int q = 0;
    read(q);
    while (q--) {
        int x = 0;
        read(x);
        ++x;
        ll ans = 0;
        for (int i = x; i <= n; ++i) ans += cnt[curr[i]][i];
        for (int i = 0; i < x; ++i) ans += cnt[curr[i] ^= 1][i];
        print(ans);
        putchar('\n');
    }
    return 0;
}