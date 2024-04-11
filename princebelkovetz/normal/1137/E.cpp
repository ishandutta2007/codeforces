#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int N = 2e5, mod = 1e13 + 7, p = 464;

struct line {
    int k, b;
    line(int k, int b) :
        k(k), b(b) {}
    ld get(int x) {
        return (ld)k * x + b;
    }
};

struct ConvexHull {
    vector <line> lines;
    vector <int> pts;
    ConvexHull() {}
    void add(line ln) {
        while (lines.size() > 1) {
            if (lines.back().get(pts.back()) > ln.get(pts.back()))
                lines.pop_back(), pts.pop_back();
            else break;
        }
        if (lines.empty()) {
            lines.push_back(ln);
        }
        else {
            int k1 = lines.back().k, b1 = lines.back().b;
            int k2 = ln.k, b2 = ln.b;
            int ok = (b2 - b1) / (k1 - k2) - 10;
            while (ln.get(ok) < lines.back().get(ok)) ok++;
            pts.push_back(ok - 1);
            lines.push_back(ln);
        }
    }
    line get(int x) {
        int l = -1, r = lines.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (x <= pts[m]) l = m;
            else r = m;
        }
        return lines[r];
    }
    void clear() {
        lines.clear();
        pts.clear();
    }
} CHT;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, q, buf = 0, curS = 0; cin >> n >> q;
    deque <pair <int, int>> deq = { { 0, 0 } };
    CHT.add(line(0, 0));
    while (q--) {
        int t; cin >> t;
        if (t == 3) {
            int b, s; cin >> b >> s;
            curS += s;
            buf += b;
        }
        else {
            if (t == 1) {
                int k; cin >> k;
                n += k;
                buf = curS = 0;
                deq.clear();
                deq.push_front({ 0, 0 });
                CHT.clear();
                CHT.add(line(0, 0));
            }
            else if (t == 2) {
                int k; cin >> k;
                deq.push_back({ -buf - curS * n, n });
                n += k;
                CHT.add(line(deq.back().second, deq.back().first));
            }
        }
        auto res = CHT.get(curS);
        cout << res.k + 1 << ' ' << (int)res.get(curS) + buf << '\n';
    }

    return 0;
}