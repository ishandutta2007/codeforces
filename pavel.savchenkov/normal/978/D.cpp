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
vi b;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    b.resize(n);
    forn(i, n) {
        cin >> b[i];
    }
    return 1;
}

const int INF = 1e9;

void remin(int& x, int y) {
    if  (x > y) {
        x = y;
    }
}

int solve() {
    if  (sz(b) <= 2) {
        return 0;
    }

    vvi dp(3, vi(3, INF));
    forn(c0, 3) {
        forn(c1, 3) {
            dp[c0][c1] = (c0 != 1) + (c1 != 1);
        }
    }
    for (int i = 2; i < sz(b); ++i) {
        vvi ndp(3, vi(3, INF));
        forn(c0, 3) {
            forn(c1, 3) {
                forn(c, 3) {
                    const int was = b[i - 1] + (c1 - 1) - (b[i - 2] + (c0 - 1));
                    const int now = b[i] + (c - 1) - (b[i - 1] + (c1 - 1));
                    if  (was != now) {
                        continue;
                    }
                    remin(ndp[c1][c], dp[c0][c1] + (c != 1));
                }
            }
        }
        dp.swap(ndp);
    }

    int ans = INF;
    forn(c0, 3) {
        forn(c1, 3) {
            remin(ans, dp[c0][c1]);
        }
    }
    if  (ans > n) {
        ans = -1;
    }
    return ans;
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
        int ans = solve();
        cout << ans << "\n";
    }

    return 0;
}