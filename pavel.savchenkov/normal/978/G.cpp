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

int n, m;
vi s;
vi d;
vi c;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    s.resize(m);
    d.resize(m);
    c.resize(m);
    forn(i, m) {
        cin >> s[i] >> d[i] >> c[i];
        --s[i];
        --d[i];
    }
    return 1;
}

bool solve() {
    vi ans(n);
    forn(i, n) {
        int who = -1;
        forn(j, m) {
            if  (d[j] == i) {
                who = j;
                break;
            }
        }
        if  (who != -1) {
            if  (c[who] != 0) {
                return 0;
            }
            ans[i] = m + 1;
            continue;
        }

        forn(j, m) {
            if  (s[j] <= i && i < d[j] && c[j] > 0) {
                if  (who == -1 || d[j] < d[who]) {
                    who = j;
                }
            }
        }

        if  (who != -1) {
            --c[who];
            ans[i] = who + 1;
        }
    }

    forn(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 1;
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
        if  (!solve()) {
            cout << -1 << endl;
        }
    }

    return 0;
}