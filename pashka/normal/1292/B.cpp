#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

    vector<pair<long, long>> p;
    p.emplace_back(x0, y0);
    while (true) {
        p.emplace_back(
                ax * p.back().first + bx,
                ay * p.back().second + by
        );
        if (p.back().first > xs + t ||
            p.back().second > ys + t) {
            break;
        }
    }

    int n = p.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long d = abs(xs - p[i].first) +
                    abs(ys - p[i].second) +
                    abs(p[j].first - p[i].first) +
                    abs(p[j].second - p[i].second);
            if (d <= t) {
                res = max(res, abs(i - j) + 1);
            }
        }
    }
    cout << res << "\n";


    return 0;
}