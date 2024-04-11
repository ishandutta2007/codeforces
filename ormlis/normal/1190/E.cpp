#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef __int128 i128;

const int INFi = 1e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;
const ld pi = atan2(0, -1);

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pts(n);
    range(i, n) {
        cin >> pts[i].first >> pts[i].second;
    }
    ld mx = INFi;
    range(i, n) {
        if (pts[i].first == 0 && pts[i].second == 0) {
            cout << (ld) 0 << '\n';
            return;
        }
        mx = min(mx, (ld) sqrtl(
                1ll * pts[i].first * pts[i].first + 1ll * pts[i].second * pts[i].second));
    }
    sort(all(pts));
    pts.resize(unique(all(pts)) - pts.begin());
    n = pts.size();
    vector<ld> dist(n);
    range(i, n) dist[i] = (ld) sqrtl(
                1ll * pts[i].first * pts[i].first + 1ll * pts[i].second * pts[i].second);
    auto norm = [&] (ld x) {
        while(x < 0)x += 2 * pi;
        while(x >= 2 * pi) x -= 2 * pi;
        return x;
    };
    auto check = [&](ld R) {
        if (R == 0) return true;
        vector<pair<ld, ld>> segs;
        vector<ld> xx;
        range(i, n) {
            ld angle = atan2(pts[i].second, pts[i].first);
            ld ang2 = acos(R / dist[i]);
            ld l = angle - ang2;
            ld r = angle + ang2;
            l = norm(l);
            r = norm(r);
            xx.push_back(l);
            xx.push_back(r);
            if (r < l) r += 2 * pi;
            segs.emplace_back(l, r);
        }
        sort(all(xx));
        int sz = xx.size();
        range(i, sz) xx.push_back(xx[i] + 2 * pi);
        range(i, sz) xx.push_back(xx[i] + 4 * pi);
        vector<pair<int, int>> segs2;
        for(auto &[l, r] : segs) {
            int l1 = lower_bound(all(xx), l) - xx.begin();
            int r1 = lower_bound(all(xx), r) - xx.begin();
            segs2.emplace_back(l1, r1);
            segs2.emplace_back(l1 + sz, r1 + sz);
        }
        sort(all(segs2));
        int N = xx.size();
        vector<int> dp1(N + 1, N + 1);
        for(auto &[l, r] : segs2) {
            if (l != 0) dp1[l - 1] = r;
        }
        for(int i = N - 1; i >= 0; --i) dp1[i] = min(dp1[i], dp1[i + 1]);
        function<void(int, int)> go = [&] (int i, int x) {
            if (dp1[i] >= x) return;
            go(dp1[i], x);
            dp1[i] = dp1[dp1[i]];
        };
        vector<int> h(N + 2);
        h[N + 1] = -1;
        for(int i = N; i >= 0; --i) {
            h[i] = h[dp1[i]] + 1;
        }
        range(i, sz) {
            int x = i + sz;
            if (x > N) break;
            go(i, x);
            if (h[i] - h[dp1[i]] <= m) return true;
        }
        return false;
    };
    ld L = 0;
    range(_, 50) {
        ld mid = (L + mx) / 2;
        if (check(mid)) {
            L = mid;
        } else {
            mx = mid;
        }
    }
    cout << L << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}