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
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define sz(a) signed(a.size())
bool check(int x, pii a) {
    return a.f <= x && x <= a.s;
}
 
const int p = 64;
const int l = 6;
int sz;
 
struct bit {
    unsigned long long *a;
    bit() {
        a = new unsigned long long[sz];
        for (int i = 0; i < sz; ++i) a[i] = 0;
    }
    void set(unsigned long long i) {
        unsigned long long j = i >> l;
        a[j] |= 1ULL << (i - (j << l));
    }
};
 
int count(const bit &a, const bit &b) {
    int ans = 0;
    for (int i = 0; i < sz; ++i)
        ans += __builtin_popcountll(a.a[i] & b.a[i]);
    return ans;
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pair<int, pii>> vert;
    vector<pair<int, pii>> hor;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2)
            vert.pb({x1, {y1, y2}});
        else hor.pb({y1, {x1, x2}});
    }
    if (sz(hor) < sz(vert)) swap(hor, vert);
    sz = (sz(hor) + p - 1) / p;
    vector<bit> inter(sz(vert));
    for (int i = 0; i < sz(vert); ++i)
        for (int j = 0; j < sz(hor); ++j)
            if (check(hor[j].f, vert[i].s) && check(vert[i].f, hor[j].s))
                inter[i].set(j); 
    ll ans = 0;
    for (int i = 0; i < sz(vert); ++i)
        for (int j = i + 1; j < sz(vert); ++j) {
            int cnt = count(inter[i], inter[j]);
            ans += cnt * (cnt - 1) / 2;
        }
    cout << ans;
    return 0;
}