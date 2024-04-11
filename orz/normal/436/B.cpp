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

const int MX = 2007;
char a[MX][MX];
int ans[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'U') {
                if (i % 2 == 1) {
                    ans[j]++;
                }
            } else if (a[i][j] == 'L') {
                int x = j - (i - 1);
                if (x >= 1) {
                    ans[x]++;
                }
            } else if (a[i][j] == 'R') {
                int x = j + (i - 1);
                if (x <= m) {
                    ans[x]++;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}