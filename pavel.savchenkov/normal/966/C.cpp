#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;


#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

#define TEST 0

int n;
vll b;

bool read() {
#if !TEST
    if  (!(cin >> n)) {
        return 0;
    }
    b.resize(n);
    forn(i, n) {
        cin >> b[i];
    }
#else
    n = 1 + rand() % 10;
    b.resize(n);
    forn(i, n) {
        b[i] = 1 + rand() % 100;
    }
#endif
    return 1;
}

bool bit(ll x, int i) {
    return (x >> i) & 1;
}

int hb(ll x) {
//    ford(i, 64) {
//        if  (bit(x, i)) {
//            return i;
//        }
//    }
//    assert(0);

    return 63 - __builtin_clzll(x);
}

bool solve() {
    sort(all(b));
    reverse(all(b));

    vll cur;
    for (int i = 0, j = 0; i < sz(b); i = j) {
        while (j < sz(b) && hb(b[i]) == hb(b[j])) {
            ++j;
        }

        vll vals;
        for (int k = i; k < j; ++k) {
            vals.pb(b[k]);
        }

        const int h = hb(b[i]);
//        eprintf("h = %d, len = %d\n", h, j - i);
//        eprintf("vals:\n");
//        for (auto x : vals) {
//            eprintf("%lld ", x);
//        }
//        eprintf("\n");

        vll ncur;
        int ptr = 0;
        forn(pvals, sz(vals)) {
            if  (ptr > sz(cur)) {
                return 0;
            }
            ncur.pb(vals[pvals]);
            ll pref = 0;
            while (ptr < sz(cur)) {
                ncur.pb(cur[ptr]);
                pref ^= cur[ptr];
                ++ptr;
                if  (bit(pref, h)) {
                    break;
                }
            }
            if  (!bit(pref, h)) {
                ptr = sz(cur) + 1;
            }
        }
        while (ptr < sz(cur)) {
            ncur.pb(cur[ptr++]);
        }

        cur.swap(ncur);
    }

    {
        vll a = {cur[0]};
        ll val = a[0];
        for (int i = 1; i < sz(cur); ++i) {
            val ^= cur[i];
            a.pb(val);
        }
        forn(i, sz(a) - 1) {
            assert(a[i] < a[i + 1]);
        }
    }

    cout << "Yes" << endl;
    forn(i, sz(cur)) {
        cout << cur[i] << " ";
    }
    cout << endl;
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

#if TEST
    while (1) {
        read();

        eprintf("b = \n");
        forn(i, n) {
            eprintf("%lld ", b[i]);
        }
        eprintf("\n");

        solve();
    }
#endif

    while (read()) {
        bool ok = solve();
        if  (!ok) {
            cout << "No" << endl;
        }

//        break;
    }

    return 0;
}