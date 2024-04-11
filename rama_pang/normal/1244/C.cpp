#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint n, p, w, d;
    cin >> n >> p >> w >> d;
    /*  
        win * w, draw * d
        d wins = w draws
    */
    for (lint draw = 0; draw <= w; draw++) {
        lint l = p - draw * d;
        if (l % w != 0) {
            continue;
        }
        lint cnt = l / w;
        if (cnt + draw > n) {
            continue;
        }
        if (cnt < 0) {
            continue;
        }
        cout << cnt << " " << draw << " " << (n - cnt - draw) << "\n";
        return 0;

    }
    cout << -1 << "\n";
    return 0;
}