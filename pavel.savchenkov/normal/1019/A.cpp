
#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>
#include <memory>
#include <memory.h>
#include <cstdlib>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>
#include <vector>


using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<pii>;

#define MAKE_FINAL_NAME_HELPER(A, B) A ## B
#define MAKE_FINAL_NAME(NAME, NUM) MAKE_FINAL_NAME_HELPER(NAME ## _, NUM)
#define ARGUMENTS_SIZE_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT
#define ARGUMENTS_SIZE(...) ARGUMENTS_SIZE_HELPER(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SELECT_MACROS(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)

#define ford(...) SELECT_MACROS(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACROS(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...)
    #define cerr if (false) cerr
#endif

int n, m;
vi p;
vi c;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    p.resize(n);
    c.resize(n);
    forn(i, n) {
        cin >> p[i] >> c[i];
        --p[i];
    }
    return 1;
}

ll solve() {
    if (m == 1) {
        return 0;
    }

    const auto cmp = [&](int i, int j) {
        return mp(c[i], i) < mp(c[j], j);
    };

    vvi who(m);
    forn(i, n) {
        who[p[i]].pb(i);
    }
    vi pos(n, -1);
    forn(i, m) {
        sort(all(who[i]), cmp);
        forn(j, sz(who[i])) {
            pos[who[i][j]] = j;
        }
    }

    vi by_c(n);
    iota(all(by_c), 0);
    sort(all(by_c), cmp);

    ll ans = ll(1e18);
    for (int want = 1; want <= n; ++want) {
        vi ptr(m, 0);
        int got = sz(who[0]);
        ll cur = 0;
        forn(i, 1, m) {
            int pref = max(0, sz(who[i]) - (want - 1));
            got += pref;
            forn(j, pref) {
                cur += c[who[i][j]];
            }
            ptr[i] = pref;
        }
        for (int j : by_c) {
            if (got >= want) {
                break;
            }
            if (p[j] == 0 || pos[j] < ptr[p[j]]) {
                continue;
            }
            cur += c[j];
            ++ptr[p[j]];
            ++got;
        }
        assert(got >= want);
        ans = min(ans, cur);
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

#ifdef LOCAL
    #define FILE_NAME "a"
    assert(freopen(FILE_NAME ".in", "r", stdin));
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        ll ans = solve();
        cout << ans << endl;
    }

    return 0;
}