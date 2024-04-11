#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

using point = pair<ll, ll>;

class ConvexHullTrick {
public:
    vector<point> lines;

    bool f1(point l1, point l2, point l3) {
        return (l1.second - l2.second) * (l3.first - l1.first) >= (l1.second - l3.second) * (l2.first - l1.first);
    }
    bool f2(point l1, point l2, ll x) {
        return (l1.second - l2.second) <= (l2.first - l1.first) * x;
    }

    void add(ll m, ll c) {
        point nw(m, c);
        while (lines.size() > 1 and f1(lines[lines.size() - 2], lines[lines.size() - 1], nw)) {
            lines.pop_back();
        }
        lines.push_back(nw);
    }

    ll get(ll x) {
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

int n, a[N];
ll pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //move from i to j, i < j, diff = (j - i) * a[i] - sum(i + 1, j) = (j - i) * a[i] - (pref[j] - pref[i]) = (j * a[i] - pref[j]) + (pref[i] - i * a[i])
    //move from j to i, i < j, sum(i, j - 1) - (j - i) * a[j] = pref[j - 1] - pref[i - 1] - (j - i) * a[j] = (pref[j - 1] - j * a[j]) + (i * a[j] - pref[i - 1])

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (ll)i * a[i];
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = a[i] + pref[i - 1];
    }

    ll ans = sum;
    ConvexHullTrick cht;

    cht.add(-n, -pref[n]);
    for (int i = n - 1; i >= 1; i--) {
        ll delta = pref[i] - (ll)i * a[i] + cht.get(-a[i]);
        ans = max(ans, sum + delta);
        cht.add(-i, -pref[i]);
    }

    cht.lines.clear();
    cht.add(1, 0);

    for (int i = 2; i <= n; i++) {
        ll delta = pref[i - 1] - (ll)i * a[i] + cht.get(a[i]);
        ans = max(ans, sum + delta);
        cht.add(i, -pref[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}