#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7;

struct Line {
    int k, b;
    Line() {}
    Line(int k, int b) : k(k), b(b) {}
    int get(int x) const {
        return k * x + b;
    }
};

struct ConvexHull {
    vector <Line> lns;
    vector <int> pts;
    ConvexHull() {}
    void add(const Line& ln) {
        while (!lns.empty()) {
            if (lns.back().get(pts.back()) < ln.get(pts.back()))
                lns.pop_back(), pts.pop_back();
            else break;
        }
        if (lns.empty()) {
            lns.push_back(ln);
            pts.push_back(-mod);
        }
        else {
            int l = pts.back(), r = mod;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (ln.get(m) >= lns.back().get(m)) r = m;
                else l = m;
            }
            lns.push_back(ln);
            pts.push_back(r);
        }
    }
    int get(int x) {
        if (lns.empty()) return -mod * mod;
        int l = 0, r = pts.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (pts[m] > x) r = m;
            else l = m;
        }
        return lns[l].get(x);
    }
    void add2(const Line& ln) {
        while (!lns.empty()) {
            if (lns.back().get(pts.back()) < ln.get(pts.back()))
                lns.pop_back(), pts.pop_back();
            else break;
        }
        if (lns.empty()) {
            lns.push_back(ln);
            pts.push_back(mod);
        }
        else {
            int l = -mod, r = pts.back();
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (ln.get(m) >= lns.back().get(m)) l = m;
                else r = m;
            }
            lns.push_back(ln);
            pts.push_back(l);
        }
    }
    int get2(int x) {
        if (lns.empty()) return -mod * mod;
        int l = 0, r = pts.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (pts[m] >= x) l = m;
            else r = m;
        }
        return lns[l].get(x);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n, S = 0; cin >> n;
    vector <int> a(n), pref(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
        S += a[i] * i;
    }
    S += pref.back();

    int ans = S;
    ConvexHull cht;
    cht.add(Line(-1, 0));
    for (int i = 0; i < n; ++i) {
        ans = max(ans, S + pref[i + 1] - a[i] * i + cht.get(a[i]));
        cht.add(Line(i, -pref[i + 1]));
    }
    cht.pts.clear();
    cht.lns.clear();
    for (int i = n - 1; i >= 0; --i) {
        ans = max(ans, S + pref[i + 1] - a[i] * i + cht.get2(a[i]));
        cht.add2(Line(i, -pref[i + 1]));
    }


    cout << ans << '\n';


    return 0;
}