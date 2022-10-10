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

int t[MX];
int h[MX], m[MX];
bool was[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> h[i] >> m[i];
    }
    int ans = 0;
    for (int s = 0; s < 2; s++) {
        int cs = s;
        memset(was, 0, sizeof(was));
        int cans = 0;
        int ch = x;
        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!was[j] && h[j] <= ch && t[j] == cs && (v == -1 || m[j] > m[v])) {
                    v = j;
                }
            }
            if (v == -1) {
                break;
            }
            was[v] = true;
            cans++;
            ch += m[v];
            cs ^= 1;
        }
        ans = max(ans, cans);
    }
    cout << ans << "\n";

    return 0;
}