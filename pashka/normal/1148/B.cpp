#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<long> a(n);
    vector<long> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long> aa(n);
    for (int i = 0; i < n; i++) {
        aa[i] = a[i] + ta;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    long l = 0;
    long r = 10000000000;
    while (r > l + 1) {
        long m = (l + r) / 2;
        vector<long> bb;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] + tb < m) {
                bb.push_back(b[i]);
            }
        }
        bool ok = false;
        if (k >= n) {
            ok = true;
        } else {
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j < (int)bb.size() && bb[j] < aa[i]) {
                    j++;
                }
                if (i + ((int)bb.size() - j) <= k) {
                    ok = true;
                }
            }
        }
        if (ok) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l == 9999999999L) {
        cout << -1;
    } else {
        cout << l;
    }

    return 0;
}