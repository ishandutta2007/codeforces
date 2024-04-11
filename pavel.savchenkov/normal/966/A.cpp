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

#define cerr if (0) cerr

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

int n, m;
int cl, ce, v;
vi ls;
vi es;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    cin >> cl >> ce >> v;
    ls.resize(cl);
    forn(i, cl) {
        cin >> ls[i];
    }
    es.resize(ce);
    forn(i, ce) {
        cin >> es[i];
    }
    return 1;
}

vi poses(const vi& a, int x) {
    const int pos = lower_bound(all(a), x) - a.begin();
    vi ans;
    for (int p = pos - 2; p <= pos + 2; ++p) {
        if  (0 <= p && p < sz(a)) {
            ans.pb(p);
        }
    }
    return ans;
}

const int INF = 1e9;

int ask(int i1, int j1, int i2, int j2) {
    int ans = INF;

    vi ps = poses(ls, j1);
    for (int p : ps) {
        const int j = ls[p];
        int cur = abs(j1 - j);
        cur += abs(i1 - i2);
        cur += abs(j - j2);
        ans = min(ans, cur);
    }    

    ps = poses(es, j1);
    for (int p : ps) {
        const int j = es[p];
        int cur = abs(j1 - j);
        cur += (abs(i1 - i2) + v - 1) / v;
        cur += abs(j - j2);
        ans = min(ans, cur);
    }

    if  (i1 == i2) {
        ans = min(ans, abs(j1 - j2));
    }

    return ans;
}

void solve() {
    sort(all(ls));
    sort(all(es));

    int q;
    cin >> q;
    forn(i, q) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << ask(i1, j1, i2, j2) << "\n";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

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