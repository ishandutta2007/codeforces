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

int n, k1, k2;
vi a;
vi b;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> k1 >> k2;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }
    b.resize(n);
    forn(i, n) {
        cin >> b[i];
    }
    return 1;
}

void solve() {
    multiset<int> s;
    forn(i, n) {
        s.insert(abs(a[i] - b[i]));
    }
    forn(iter, k1 + k2) {
        auto it = s.rbegin();
        int val = *it;
        s.erase(s.find(val));
        --val;
        s.insert(abs(val));
    }
    ll ans = 0;
    for (const auto& val : s) {
        ans += val * 1ll * val;
    }
    cout << ans << endl;
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