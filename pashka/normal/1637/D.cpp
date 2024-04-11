#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        const int MAX = 10001;
        vector<long> d(MAX, LLONG_MAX);
        d[0] = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            vector<long> dd(MAX, LLONG_MAX);
            for (int j = 0; j < MAX; j++) {
                if (d[j] == LLONG_MAX) continue;
                int k = s - j;
                dd[j + a[i]] = min(dd[j + a[i]], d[j] + a[i] * j + b[i] * k);
                dd[j + b[i]] = min(dd[j + b[i]], d[j] + b[i] * j + a[i] * k);
            }
            s += a[i] + b[i];
            d = dd;
        }
        long m = LLONG_MAX;
        for (int i = 0; i < MAX; i++) m = min(m, d[i]);
        m *= 2;
        for (int i = 0; i < n; i ++) {
            m += a[i] * a[i] * (n - 1);
            m += b[i] * b[i] * (n - 1);
        }
        cout << m << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}