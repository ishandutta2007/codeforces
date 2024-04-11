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

int n, k;
vi r;
vvi g;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> k;
    r.resize(n);
    forn(i, n) {
        cin >> r[i];
    }
    g.clear();
    g.resize(n);
    forn(i, k) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return 1;
}

void solve() {
    vi rs = r;
    sort(all(rs));

    auto cnt_less = [&](int val) {
        int pos = lower_bound(all(rs), val) - rs.begin();
        return pos;
    };

    forn(i, n) {
        int ans = cnt_less(r[i]);
        for (int to : g[i]) {
            if  (r[to] < r[i]) {
                --ans;
            }
        }
        assert(ans >= 0);
        cout << ans << " ";
    }
    cout << endl;
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
        solve();
    }

    return 0;
}