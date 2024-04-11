#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5, INF = 4e18;
int r[MAXN], g[MAXN], b[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        for (int i = 0; i < nr; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < ng; ++i) {
            cin >> g[i];
        }
        for (int i = 0; i < nb; ++i) {
            cin >> b[i];
        }
        sort(r, r + nr);
        sort(g, g + ng);
        sort(b, b + nb);
        int ans = INF;
        for (int k = 0; k < nr; ++k) {
            int elem = r[k];
            int i = upper_bound(g, g + ng, elem) - g;
            i--;
            int j = lower_bound(b, b + nb, elem) - b;
            if (i >= 0 && j < nb) {
                int res = (elem - g[i]) * (elem - g[i]);
                res += (elem - b[j]) * (elem - b[j]);
                res += (g[i] - b[j]) * (g[i] - b[j]);
                ans = min(ans, res);
            }
            i = upper_bound(b, b + nb, elem) - b;
            i--;
            j = lower_bound(g, g + ng, elem) - g;
            if (i >= 0 && j < ng) {
                int res = (elem - b[i]) * (elem - b[i]);
                res += (elem - g[j]) * (elem - g[j]);
                res += (g[j] - b[i]) * (g[j] - b[i]);
                ans = min(ans, res);
            }
        }
        for (int k = 0; k < nb; ++k) {
            int elem = b[k];
            int i = upper_bound(g, g + ng, elem) - g;
            i--;
            int j = lower_bound(r, r + nr, elem) - r;
            if (i >= 0 && j < nr) {
                int res = (elem - g[i]) * (elem - g[i]);
                res += (elem - r[j]) * (elem - r[j]);
                res += (g[i] - r[j]) * (g[i] - r[j]);
                ans = min(ans, res);
            }
            i = upper_bound(r, r + nr, elem) - r;
            i--;
            j = lower_bound(g, g + ng, elem) - g;
            if (i >= 0 && j < ng) {
                int res = (elem - r[i]) * (elem - r[i]);
                res += (elem - g[j]) * (elem - g[j]);
                res += (g[j] - r[i]) * (g[j] - r[i]);
                ans = min(ans, res);
            }
        }
        for (int k = 0; k < ng; ++k) {
            int elem = g[k];
            int i = upper_bound(r, r + nr, elem) - r;
            i--;
            int j = lower_bound(b, b + nb, elem) - b;
            if (i >= 0 && j < nb) {
                int res = (elem - r[i]) * (elem - r[i]);
                res += (elem - b[j]) * (elem - b[j]);
                res += (r[i] - b[j]) * (r[i] - b[j]);
                ans = min(ans, res);
            }
            i = upper_bound(b, b + nb, elem) - b;
            i--;
            j = lower_bound(r, r + nr, elem) - r;
            if (i >= 0 && j < nr) {
                int res = (elem - b[i]) * (elem - b[i]);
                res += (elem - r[j]) * (elem - r[j]);
                res += (r[j] - b[i]) * (r[j] - b[i]);
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}