#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

long xx, yy;

bool go(long m, vector<pair<int, int>> &a) {
    int n = a.size();
    long x1 = LLONG_MIN;
    long x2 = LLONG_MAX;
    long y1 = LLONG_MIN;
    long y2 = LLONG_MAX;
    long xy1 = LLONG_MIN;
    long xy2 = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        x1 = max(x1, a[i].first - m);
        x2 = min(x2, a[i].first + m);
        y1 = max(y1, a[i].second - m);
        y2 = min(y2, a[i].second + m);
        xy1 = max(xy1, a[i].first - a[i].second - m);
        xy2 = min(xy2, a[i].first - a[i].second + m);
    }
    bool ok = true;
    if (x2 < x1) ok = false;
    if (y2 < y1) ok = false;
    if (xy2 < xy1) ok = false;
    if (ok) {
        long ll = max(xy1, x1 - y2);
        long rr = min(xy2, x2 - y1);
        if (ll > rr) {
            ok = false;
        } else {
            if (ll == x1 - y2) {
                xx = x1;
                yy = y2;
            } else {
                if (x2 - y2 >= ll) {
                    yy = y2;
                    xx = ll + yy;
                } else {
                    xx = x2;
                    yy = xx - ll;
                }
            }
            assert(xx >= x1 && xx <= x2 && yy >= y1 && yy <= y2 &&
                   xx - yy >= xy1 && xx - yy <= xy2);
        };
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cc = 0;
        for (char c : s) {
            if (c == 'B') cc++;
        }
        a[i] = {cc, s.size() - cc};
    }
    long l = -1;
    long r = 1e10;
    while (r > l + 1) {
        long m = (l + r) / 2;
        bool ok = go(m, a);
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    go(r, a);
    string res = "";
    for (int i = 0; i < xx; i++) {
        res += "B";
    }
    for (int i = 0; i < yy; i++) {
        res += "N";
    }
    cout << r << "\n";
    cout << res << "\n";

    return 0;
}