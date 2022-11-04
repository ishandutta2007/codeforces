#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 1e-9;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back

bool mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}

bool maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

void run() {
    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector<int> a(cl);
    rep(i, 0, cl) {
        cin >> a[i];
    }
    vector<int> b(ce);
    rep(i, 0, ce) {
        cin >> b[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << "\n";
        } else {
            int pos = (int) (lower_bound(all(a), y1) - a.begin());
            vector<pair<int, int>> q;
            if (pos < sz(a)) {
                q.pb({a[pos], 1});
            }
            if (pos - 1 >= 0) {
                q.pb({a[pos - 1], 1});
            }
            pos = (int) (lower_bound(all(b), y1) - b.begin());
            if (pos < sz(b)) {
                q.pb({b[pos], v});
            }
            if (pos - 1 >= 0) {
                q.pb({b[pos - 1], v});
            }
            int ans = INF;
            for (auto &it : q) {
                int res = abs(y1 - it.first) + abs(y2 - it.first);
                int h = abs(x1 - x2);
                res += (h + it.second - 1) / it.second;
                mini(ans, res);
            }
            cout << ans << "\n";
        }
    }
}