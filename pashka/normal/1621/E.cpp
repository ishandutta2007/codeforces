#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<long>> b(m);
        vector<long> s(m);
        vector<int> k(m);
        for (int i = 0; i < m; i++) {
            cin >> k[i];
            b[i].resize(k[i]);
            s[i] = 0;
            for (int j = 0; j < k[i]; j++) {
                cin >> b[i][j];
                s[i] += b[i][j];
            }
        }
        sort(a.begin(), a.end());
        a.erase(a.begin(), a.begin() + (n - m));
        n = m;
        vector<int> o(n);
        for (int i = 0; i < n; i++) o[i] = i;
        sort(o.begin(), o.end(),
             [&](const auto &a, const auto &b) -> bool {
                 return s[a] * k[b] < s[b] * k[a];
             });

        vector<int> ro(n);
        for (int i = 0; i < n; i++) ro[o[i]] = i;

        vector<int> c0(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            if (s[o[i]] <= a[i] * k[o[i]]) {
                c0[i] = 1 + c0[i + 1];
            } else {
                c0[i] = 0;
            }
        }
        vector<int> cl(n + 1);
        for (int i = n - 1; i >= 1; i--) {
            if (s[o[i]] <= a[i - 1] * k[o[i]]) {
                cl[i] = 1 + cl[i + 1];
            } else {
                cl[i] = 0;
            }
        }
        vector<int> cr(n + 1);
        for (int i = n - 2; i >= 0; i--) {
            if (s[o[i]] <= a[i + 1] * k[o[i]]) {
                cr[i] = 1 + cr[i + 1];
            } else {
                cr[i] = 0;
            }
        }
        for (int ii = 0; ii < m; ii++) {
            for (long x : b[ii]) {
                int kk = k[ii] - 1;
                long ss = s[ii] - x;
                int i = ro[ii];
                int l = -1;
                int r = m;
                while (r > l + 1) {
                    int mm = (l + r) / 2;
                    if (s[o[mm]] * kk < ss * k[o[mm]]) {
                        l = mm;
                    } else {
                        r = mm;
                    }
                }
                int j = l + 1;
                if (j > i) j--;
                bool ok = ss <= a[j] * kk;
                if (j <= i) {
                    ok = ok &&
                            c0[0] >= j &&
                            cr[j] >= (i - j) &&
                            c0[i + 1] >= n - i - 1;
                } else {
                    ok = ok &&
                         c0[0] >= i &&
                         cl[i + 1] >= (j - i) &&
                         c0[j + 1] >= n - j - 1;
                }
                cout << ok;
            }
        }
        cout << "\n";
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