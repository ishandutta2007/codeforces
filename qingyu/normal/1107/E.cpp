//qwq
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 107;
const ll INF = 1e18;

string s;
int a[MX];
ll c[MX];
ll f[MX][MX];
ll g[MX][MX];

void cg() {
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            g[i][j] = -INF;
        }
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    cin >> s;
    s = '$' + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = a[i];
        for (int j = 1; j <= i; j++) {
            c[i] = max(c[i], c[j] + c[i - j]);
        }
    }

    for (int l = n; l >= 1; l--) {
        for (int d = 0; d < 2; d++) {
            cg();
            g[l - 1][0] = 0;
            for (int i = l - 1; i + 1 <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (s[i + 1] - '0' == d) {
                        g[i + 1][j + 1] = max(g[i + 1][j + 1], g[i][j]);
                    }
                    for (int k = i + 1; k <= n; k++) {
                        g[k][j] = max(g[k][j], g[i][j] + f[i + 1][k]);
                    }
                }
            }
            for (int r = l; r <= n; r++) {
                for (int i = 0; i <= n; i++) {
                    f[l][r] = max(f[l][r], g[r][i] + c[i]);
                }
            }
        }
    }

    cout << f[1][n] << "\n";
    return 0;
}