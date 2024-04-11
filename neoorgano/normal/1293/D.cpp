#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int xk, yk, ax, ay, bx, by;

pair<int, int> nxt(int x, int y) {
    return {x * ax + bx, y * ay + by};
}

pair<int, int> prv(int x, int y) {
    if (x == xk) {
        return {-1, -1};
    }
    return {(x - bx) / ax, (y - by) / ay};
}

main() {
    int x0, y0;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    xk = x0;
    yk = y0;
    int xs, ys, t;
    cin >> xs >> ys >> t;
    int ans = 0;
    while (1) {
        if (x0 > 2e16 || y0 > 2e16) {
            break;
        }
        int x = x0, y = y0;
        int t1 = abs(xs - x) + abs(ys - y);
        int cnt1 = 0;
        while (t1 <= t) {
            cnt1++;
            auto nx = nxt(x, y);
            t1 += nx.first - x;
            t1 += nx.second - y;
            x = nx.first;
            y = nx.second;
        }
        x = x0; y = y0;
        t1 = abs(xs - x) + abs(ys - y);
        int cnt2 = 0;
        while (t1 <= t && x + 1) {
            cnt2++;
            auto pr = prv(x, y);
            t1 += x - pr.first;
            t1 += y - pr.second;
            x = pr.first;
            y = pr.second;
        }
        ans = max(ans, max(cnt1, cnt2));
        auto nx = nxt(x0, y0);
        x0 = nx.first;
        y0 = nx.second;
    }
    cout << ans;
    return 0;
}