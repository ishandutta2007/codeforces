#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e3 + 5;
const ld pi = acos(-1.0);

using point = pair<int, int>;

class ConvexHullTrick {
    vector<point> lines;

    bool f1(point l1, point l2, point l3) {
        return (l1.second - l2.second) * (ll)(l3.first - l1.first) >= (l1.second - l3.second) * (ll)(l2.first - l1.first);
    }
    bool f2(point l1, point l2, ld x) {
        return (l1.second - l2.second) <= (l2.first - l1.first) * x;
    }

public:

    void add(int m, int c) {
        point nw(m, c);
        while (lines.size() > 1 and f1(lines[lines.size() - 2], lines[lines.size() - 1], nw)) {
            lines.pop_back();
        }
        lines.push_back(nw);
    }

    ld get(ld x) {
        int lo = 0, hi = lines.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (f2(lines[mid - 1], lines[mid], x))
                lo = mid;
            else hi = mid - 1;
        }
        return lines[lo].first * x + lines[lo].second;
    }
};

struct seg {
    int l, r, y;
    seg(): l(), r(), y() {}
};

int n;
seg a[N];

ld angle(int x1, int y1, int x2, int y2) {
    if (x1 == x2)
        return pi / 2;
    ld temp = atan((ld)(y2 - y1) / (ld)(x2 - x1));
    if (temp < 0)
        temp += pi;
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(9);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r >> a[i].y;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(a[i].y, a[i].l);
        v.emplace_back(a[i].y, a[i].r);
    }

    ConvexHullTrick cht1, cht2;

    sort(all(v));
    for (auto &[m, c] : v) {
        cht1.add(m, c);
    }

    reverse(all(v));
    for (auto &[m, c] : v) {
        cht2.add(-m, -c);
    }

    vector<pair<ld, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i].y < a[j].y) {
                ld temp1 = angle(a[i].l, a[i].y, a[j].r, a[j].y), temp2 = angle(a[i].r, a[i].y, a[j].l, a[j].y);
                mp.emplace_back(temp1, 1);
                mp.emplace_back(temp2, -1);
            }
        }
    }

    int cur = 0;
    ld best = 1e18;

    sort(all(mp));
    for (auto &[theta, c] : mp) {
        if (!cur and theta) {
            best = min(best, cht1.get(1 / tan(pi - theta)) + cht2.get(1 / tan(pi - theta)));
        }

        cur += c;

        if (!cur and theta) {
            best = min(best, cht1.get(1 / tan(pi - theta)) + cht2.get(1 / tan(pi - theta)));
        }
    }

    if (best != 1e18)
        cout << best << "\n";
    else {
        int mx = -1e6, mn = 1e6;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i].r);
            mn = min(mn, a[i].l);
        }
        cout << mx - mn << "\n";
    }
    return 0;
}