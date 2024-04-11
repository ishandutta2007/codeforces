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

hashmap<int, int> p, xorp, mysize;

void make_set(int x) {
    if (p.count(x)) return;
    p[x] = x;
    mysize[x] = 1;
}

int findset(int x) {
    if (p[x] == x) return x;
    int a = findset(p[x]);
    xorp[x] ^= xorp[p[x]];
    p[x] = a;
    return a;
}

int union_sets(int a, int b, int x) {
    int c = findset(a);
    int d = findset(b);
    x ^= xorp[a] ^ xorp[b];
    if (c != d) {
        if (mysize[c] > mysize[d]) swap(c, d);
        p[c] = d;
        xorp[c] = x;
        mysize[d] += mysize[c];
    }
}

int get(int a, int b) {
    int c = findset(a);
    int d = findset(b);
    if (c != d) return -1;
    return xorp[a] ^ xorp[b];
}

signed main() {
    FAST; FIXED; RANDOM;
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last, r ^= last, x ^= last;
            if (l > r) swap(l, r);
            ++r;
            make_set(l); make_set(r);
            union_sets(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last; r ^= last;
            if (l > r) swap(l, r);
            ++r;
            make_set(l); make_set(r);
            last = get(l, r);
            cout << last << '\n';
            if (last < 0) last = 1;
        }
    }
    return 0;
}