#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, len;
        cin >> n >> len;
        vector<int> a(n + 2);
        for (int i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        a[n + 1] = len;
        double t1 = 0;
        double t2 = 0;
        int x1 = 0;
        int x2 = n + 1;
        while (x2 > x1 + 1) {
            double s1 = x1 + 1;
            double s2 = n + 2 - x2;
            double tt1 = t1 + (a[x1 + 1] - a[x1]) / s1;
            double tt2 = t2 + (a[x2] - a[x2 - 1]) / s2;
            if (tt1 < tt2) {
                t1 = tt1;
                x1++;
            } else {
                t2 = tt2;
                x2--;
            }
        }
        double s1 = x1 + 1;
        double s2 = n + 2 - x2;
        double d = a[x2] - a[x1];
        // t1 + x / s1 = t2 + (d - x) / s2
        double x = (t2 - t1 + d / s2) / (1 / s1 + 1 / s2);
        cout << setprecision(20) << t1 + x / s1 << "\n";
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