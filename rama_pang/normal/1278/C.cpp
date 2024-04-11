#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    // T = 1;
    while (T--) solve();
    return 0;
}

int solve() {
    lint n;
    cin >> n;
    vector<pair<lint, lint>> L(n), R(n);
    for (int i = 0; i < n + n; i++) {
        int a;
        cin >> a;
        if (i < n) {
            if (a == 1) {
                L[i].first = 1;
            } else {
                L[i].second = 1;
            }
        } else {
            if (a == 1) {
                R[i - n].first = 1;
            } else {
                R[i - n].second = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        L[i].first += L[i - 1].first;
        L[i].second += L[i - 1].second;
    }

    map<lint, lint> where;
    pair<lint, lint> cur = {0, 0};
    where[0] = n;

    for (int i = n - 1; i >= 0; i--) {
        cur.first += R[i].first;
        cur.second += R[i].second;
        where[cur.first - cur.second] = i;
    }

    lint ans = 2 * n;
    ans = where[0] + n;
    for (int i = 0; i < n; i++) {
        if (where.count(- (L[i].first - L[i].second)) == 1) {
            ans = min(ans, where[-(L[i].first - L[i].second)] + n - i - 1);
        }
    }

    cout << ans << "\n";

}