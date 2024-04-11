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

    int n;
    cin >> n;
    vector<long> a(n);
    vector<long> aa(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long> d(n + 1, MAX_LONG);
    vector<long> dd(n + 1);
    d[n] = 0;
    vector<int> ps(n + 1);

    for (int x = 0; x < 63; x++) {
        fill(dd.begin(), dd.end(), MAX_LONG);

        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + ((a[i] >> x) & 1);
        }

        for (int i = 0; i <= n; i++) {
            if (d[i] == MAX_LONG) continue;
            {// 1
                int ii = n - (ps[n] - ps[i]);
                long v = d[i] + (i - ps[i]) + (ps[n] - ps[i]);
                dd[ii] = min(dd[ii], v);
            }
            {// 0
                int ii = n - (ps[i] + (n - i));
                long v = d[i] + ps[i] + (n - i - (ps[n] - ps[i]));
                dd[ii] = min(dd[ii], v);
            }
        }

        {
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (((a[i] >> x) & 1) == 0) {
                    aa[k++] = a[i];
                }
            }
            for (int i = 0; i < n; i++) {
                if (((a[i] >> x) & 1) == 1) {
                    aa[k++] = a[i];
                }
            }
            swap(a, aa);
        }

        swap(d, dd);
    }

    cout << d[n];

    return 0;
}