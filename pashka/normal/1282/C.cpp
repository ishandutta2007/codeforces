#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, t, a, b;
    cin >> n >> t >> a >> b;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    sort(p.begin(), p.end());
    p.push_back({t + 1, 0});

    long s = 0;
    int aa = 0;
    int bb = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].second == 0) {
            aa++;
        } else {
            bb++;
        }
    }
    long res = 0;
    for (int i = 0; i <= n; i++) { // 

        long tt = p[i].first - 1;
        tt -= s;

        if (tt >= 0) {
            long r = i;
            long x = min(tt / a, (long)aa);
            r += x;
            tt -= x * a;

            x = min(tt / b, (long)bb);
            r += x;
            tt -= x * b;
            res = max(res, r);
        }

        s += p[i].second ? b : a;
        if (p[i].second == 0) {
            aa--;
        } else {
            bb--;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}