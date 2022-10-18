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
#include <functional>
#include <queue>

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

pii readp() {
    int a, b;
    cin >> a >> b;
    if  (a > b) {
        swap(a, b);
    }
    return mp(a, b);
}

vector<pii> a;
vector<pii> b;

bool read() {
    int n, m;
    if  (!(cin >> n >> m)) {
        return 0;
    }
    a.resize(n);
    forn(i, n) {
        a[i] = readp();
    }
    b.resize(m);
    forn(i, m) {
        b[i] = readp();
    }
    return 1;
}

int both(const pii& x, const pii& y) {
    vi ok;
    forn(r, 10) {
        int xx = (x.fst == r) + (x.snd == r);
        int yy = (y.fst == r) + (y.snd == r);
        if  (xx == 1 && yy == 1) {
            ok.pb(r);
        }
    } 
    if  (sz(ok) == 1) {
        return ok.front();
    }
    return -1;
}

int solve() {
    bool a_know = 1;
    forn(i, sz(a)) {
        set<int> oks;
        forn(j, sz(b)) {
            int cur = both(a[i], b[j]);
            if  (cur != -1) {
                oks.insert(cur);
            }
        }
        if  (sz(oks) > 1) {
            a_know = 0;
        }
    } 

    bool b_know = 1;
    forn(i, sz(b)) {
        set<int> oks;
        forn(j, sz(a)) {
            int cur = both(b[i], a[j]);
            if  (cur != -1) {
                oks.insert(cur);
            }
        }
        if  (sz(oks) > 1) {
            b_know = 0;
        }
    } 

    set<int> oks;
    forn(i, sz(a)) {
        forn(j, sz(b)) {
            int cur = both(a[i], b[j]);
            if  (cur != -1) {
                oks.insert(cur);
            }
        }
    }

    bool i_know = sz(oks) == 1;
    assert(!oks.empty());

    if  (i_know) {
        return *oks.begin();
    }
    if  (a_know && b_know) {
        return 0;
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << solve() << endl;
    }

    return 0;
}