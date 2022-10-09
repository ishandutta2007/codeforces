
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <string>
using namespace std;

typedef long long ll;

int N;
ll p[444], g[444], gg[444], m[444];

int main() {
#ifdef MYDEBUG
    freopen("in", "r", stdin);
#endif
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> p[i];
    const ll inf = 0x7fffffffffffffffLL;
    ll best = inf;
    for (int i = 2; i <= N; ++i) {
        ll s = p[i - 1] - 1;
        for (int k = 1; k <= N; ++k) {
            g[k] = s / p[k];
            s %= p[k];
        }
        for (int j = i; j < N; ++j) {
            s = 0;
            for (int k = 1; k < j; ++k) {
                s += g[k] * p[k];
                m[k] = g[k];
            }
            s += (g[j] + 1) * p[j];
            m[j] = g[j] + 1;
            fill(m + j + 1, m + N + 1, 0);
            if (s >= best) continue;
            ll s0 = s;
            for (int k = 1; k <= N; ++k) {
                gg[k] = s / p[k];
                s %= p[k];
            }
            ll a = 0, b = 0;
            for (int k = 1; k <= N; ++k)
                a += m[k], b += gg[k];
            if (a < b)
                best = s0;
        }
    }
    if (best == inf)
        cout << -1 << endl;
    else
        cout << best << endl;
    return 0;
}
//QAQ