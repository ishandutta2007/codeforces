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
#include <cmath>

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

using ld = long double;

int n;
vi a;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }
    return 1;
}

const int MAX = 1e4 + 10;
const int MAXN = 1e2 + 10;

bool dp[MAXN][MAXN][MAX];
bool diff[MAXN][MAXN][MAX];

int solve() {
    sort(all(a));

    memset (dp, 0, sizeof dp);
    memset (diff, 0, sizeof diff);
    dp[0][0][0] = 1;

    forn(i, sz(a)) {
        bool inter = (i > 0 && a[i] != a[i - 1]);
        forn(k, i + 1) {
            forn(m, MAX) {
                if (!dp[i][k][m]) {
                    continue;
                }

                assert(m + a[i] < MAX);

                dp[i + 1][k][m] = 1;
                diff[i + 1][k][m] |= diff[i][k][m];

                dp[i + 1][k + 1][m + a[i]] = 1;
                diff[i + 1][k + 1][m + a[i]] |= diff[i][k][m];
                if (inter && m > 0) {
                    diff[i + 1][k + 1][m + a[i]] = 1;
                }
            }
        }
    }

    int sum = 0;
    forn(i, sz(a)) {
        sum += a[i];
    }
    assert(sum < MAX);

    int g = 0;
    {   
        set<int> s(all(a));
        g = sz(s);
    }

    if (g <= 2) {
        return n;
    }

    int ans = 0;
    for (int i = 0, j = 0; i < sz(a); i = j) {
        assert(i <= j);
        while (j < sz(a) && a[i] == a[j]) {
            ++j;
        }

        for (int k = 1; k <= j - i; ++k) {
            int m = k * a[i];

            assert(dp[sz(a)][k][m]);
            if (!diff[sz(a)][k][m]) {
                ans = max(ans, k);
            } else {
                eprintf("fail a[i]=%d, k=%d\n", a[i], k);
            }
        }
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cout.precision(20);
    cout << fixed;

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    // freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        auto ans = solve();
        cout << ans << endl;
    }

    return 0;
}