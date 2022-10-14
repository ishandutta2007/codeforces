#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ulint = unsigned long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ulint x0, y0, ax, ay, bx, by, t;
    lint xs, ys;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vector<pair<lint, lint>> gen;
    gen.emplace_back(x0, y0);
    for (int i = 1; i < 100; i++) {
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
        if (x0 > 1e17 || y0 > 1e17) {
            break;
        }
        gen.emplace_back(x0, y0);
    }
    int ans = 0;
    for (int i = 0; i < gen.size(); i++) {
        for (int j = i; j < gen.size(); j++) {
            ulint cnt = 0;
            cnt += abs(xs - (lint) gen[i].first) + abs(ys - (lint) gen[i].second);
            for (int k = i + 1; k <= j; k++) {
                cnt += (lint)gen[k].first - (lint)gen[k - 1].first + (lint)gen[k].second - (lint)gen[k - 1].second;
            }
            if (cnt <= t) {
                ans = max(ans, j - i + 1);
            }
            cnt = 0;
            cnt += abs(xs - (lint) gen[j].first) + abs(ys - (lint) gen[j].second);
            for (int k = j - 1; k >= i; k--) {
                cnt += (lint)gen[k + 1].first - (lint)gen[k].first + (lint)gen[k + 1].second - (lint)gen[k].second;
            }
            if (cnt <= t) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << "\n";

}