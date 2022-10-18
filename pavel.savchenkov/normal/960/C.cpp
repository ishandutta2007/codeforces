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

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

int X, d;

bool read() {
    if  (!(cin >> X)) {
        return 0;
    }
    cin >> d;
    return 1;
}

void solve() {
    vi ks;
    for (int i = 1; i <= 30; ++i) {
        if  ((X >> i) & 1) {
            ks.pb(i);
        }
    }

    int got = 0;
    for (int i : ks) {
        got += (1 << i) - 1;
    }
    assert(got <= X);
    while (got < X) {
        ks.pb(1);
        ++got;
    }

    vll ans;
    ll val = 1;
    for (int k : ks) {
        forn(it, k) {
            ans.pb(val);
        }
        val += d + 1;
    }

    cout << sz(ans) << endl;
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

    return 0;
}