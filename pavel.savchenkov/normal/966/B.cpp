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

struct server {
    int c;
    int id;

    void read(int i) {
        id = i;
        cin >> c;
    }

    bool operator < (const server& s) const {
        return c < s.c;
    }
};

int n, x1, x2;
vector<server> s;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> x1 >> x2;
    s.resize(n);
    forn(i, n) {
        s[i].read(i);
    }
    return 1;
}

vvi solve2() {
    forn(i, sz(s)) {
        const int k1 = (x1 + s[i].c - 1) / s[i].c;
        if  (k1 >= i + 1) {
            continue;
        }
        const int j = i - k1;
        assert(j >= 0);
        const int k2 = (x2 + s[j].c - 1) / s[j].c;
        if  (k2 > j + 1) {
            continue;
        }

        vvi ans(2);
        for (int z = j + 1; z <= i; ++z) {
            ans[0].pb(s[z].id);
        }
        for (int z = 0; z <= j; ++z) {
            ans[1].pb(s[z].id);
        }

        return ans;
    }

    return {};
}

bool solve() {
    sort(all(s));
    reverse(all(s));

    vvi ans;
    forn(it, 2) {
        vvi cur = solve2();
        if  (!cur.empty()) {
            assert(sz(cur) == 2);
            if  (it == 1) {
                swap(cur[0], cur[1]);
            }
            ans = cur;
        }

        swap(x1, x2);
    }

    if  (ans.empty()) {
        return 0;
    }

    cout << "Yes" << endl;
    cout << sz(ans[0]) << " " << sz(ans[1]) << endl;
    forn(i, sz(ans)) {
        sort(all(ans[i]));
        forn(j, sz(ans[i])) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << endl;
    }

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

    while (read()) {
        bool ok = solve();
        if  (!ok) {
            cout << "No" << endl;
        }

        cout << endl;
    }

    return 0;
}