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

int n;
vi a;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    a.resize(2 * n);
    forn(i, 2 * n) {
        cin >> a[i];
        --a[i];
    }
    return 1;
}

void solve() {
    vi pos(n);
    forn(i, sz(a)) {
        pos[a[i]] ^= i;
    }

    vi used(n);
    int ans = 0;
    forn(i, sz(a)) {
        if  (used[a[i]]) {
            continue;
        }
        int other = pos[a[i]] ^ i;
        assert(i < other);

        int cur = 0;
        for (int k = i + 1; k < other; ++k) {
            if  (!used[a[k]]) {
                ++cur;
            }
        }
        ans += cur;

        used[a[i]] = 1;
    }

    cout << ans << endl;
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