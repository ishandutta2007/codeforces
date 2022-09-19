#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> l(n), r(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i] >> c[i];
        }
        int mnl = c[0];
        int mnr = c[0];
        int mnc = c[0];
        int ll = l[0];
        int rr = r[0];
        cout << c[0] << "\n";
        for (int i = 1; i < n; i++) {
            if (l[i] < ll) {
                ll = l[i];
                mnc = mnl = INT_MAX;
            }
            if (r[i] > rr) {
                rr = r[i];
                mnc = mnr = INT_MAX;
            }
            if (l[i] == ll) {
                mnl = min(mnl, c[i]);
            }
            if (r[i] == rr) {
                mnr = min(mnr, c[i]);
            }
            if (l[i] == ll && r[i] == rr) {
                mnc = min(mnc, c[i]);
            }
            cout << min(mnc, mnl + mnr) << "\n";
        }


    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}