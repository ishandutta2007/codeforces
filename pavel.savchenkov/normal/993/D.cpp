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

struct task {
    ll a, b;

    bool operator < (const task& t) const {
        return a > t.a;
    }
};

int n;
vector<task> ts;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    ts.resize(n);
    forn(i, n) {
        cin >> ts[i].a;
        ts[i].a *= 1000;
    }
    forn(i, n) {
        cin >> ts[i].b;
    }
    return 1;
}

void remin(ll& x, ll y) {
    if  (x > y) {
        x = y;
    }
}

const int MAXN = 50 + 5;
const ll INF = 6 * ll(1e12);

ll dp[2][MAXN][MAXN];

bool can(ll T) {
    auto clear = [](int c) {
        forn(was0, sz(ts) + 1) {
            forn(was1, sz(ts) + 1) {
                dp[c][was0][was1] = INF;
            }
        }
    };

    int c = 0;
    clear(c);
    dp[c][0][0] = 0;
    forn(i, sz(ts)) {
        clear(c ^ 1);
        
        const bool eq_next = (i + 1 < sz(ts) && ts[i].a == ts[i + 1].a);
        const ll val = ts[i].a - T * ts[i].b;

        forn(was0, sz(ts) + 1) {
            forn(was1, sz(ts) + 1) {
                const ll& cur_dp = dp[c][was0][was1];
                if  (cur_dp >= INF) {
                    continue;
                }

                // as first
                {
                    ll ndp = cur_dp + val;
                    int nwas0 = was0;
                    int nwas1 = was1;
                    if  (eq_next) {
                        ++nwas1;
                    } else {
                        nwas0 += nwas1;
                        ++nwas0;
                        nwas1 = 0;
                    }
                    remin(dp[c ^ 1][nwas0][nwas1], ndp);
                }

                // as second
                if  (was0 > 0) {
                    ll ndp = cur_dp;
                    int nwas0 = was0 - 1;
                    int nwas1 = was1;
                    if  (!eq_next) {
                        nwas0 += nwas1;
                        nwas1 = 0;
                    }
                    remin(dp[c ^ 1][nwas0][nwas1], ndp);
                }
            }
        }

        c ^= 1;
    }

    ll ans = INF;
    forn(was0, sz(ts) + 1) {
        forn(was1, sz(ts) + 1) {
            remin(ans, dp[c][was0][was1]);
        }
    }

    if  (ans <= 0) {
        return 1;
    }
    return 0;
}

ll solve() {
    sort(all(ts));
    
    ll L = -1;
    ll R = INF;
    while (L != R - 1) {
        ll M = (L + R) / 2;
        if  (can(M)) {
            R = M;
        } else {
            L = M;
        }
    }

    return R;
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