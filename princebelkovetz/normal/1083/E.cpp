#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <cassert>
#include <map>
#include <queue>
#include <string>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
const int mod = 1e9 + 7;
struct Line {
    int k, b; 
    Line(int k, int b) : k(k), b(b) {}
    int get(int x) {
        return k * x + b;
    }
};
struct ConvexHullTrick {
    vector <Line> lines;
    vector <int> ids;
    ConvexHullTrick() : lines(), ids() {}
    void add(Line ln) {
        while (!lines.empty()) {
            if (ln.get(ids.back()) >= lines.back().get(ids.back()))
                ids.pop_back(), lines.pop_back();
            else break;
        }
        if (lines.empty()) {
            lines.push_back(ln), ids.push_back(-mod);
        }
        else {
            int l = ids.back(), r = mod + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (lines.back().get(m) <= ln.get(m))
                    r = m;
                else l = m;
            }
            if (l != mod) {
                lines.push_back(ln);
                ids.push_back(r);
            }
        }
    }
    int get(int x) {
        int l = 0, r = ids.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (ids[m] > x) r = m;
            else l = m;
        }
        return lines[l].get(x);
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <vector <int>> a(n, vector <int>(3));
    for (auto& x : a) {
        cin >> x[0] >> x[1] >> x[2];
    }
    sort(a.begin(), a.end());
    vector <int> dp(n, -mod);
    ConvexHullTrick hull = ConvexHullTrick();
    hull.add(Line(0, 0));
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i][0] * a[i][1] - a[i][2];
        dp[i] = max(dp[i], hull.get(-a[i][1]) - a[i][2] + a[i][0] * a[i][1]);
        hull.add(Line(a[i][0], dp[i]));
    }
    int ans = 0;
    for (auto& x : dp) ans = max(ans, x);
    cout << ans << '\n';
}