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

const int MX = 50 * 10 * 1000 + 7;

bool f[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    f[0] = true;
    int n;
    cin >> n;
    int d;
    cin >> d;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = MX - 1; j >= x; j--) {
            f[j] |= f[j - x];
        }
    }

    vector<int> can;
    for (int i = 0; i < MX; i++) {
        if (f[i]) {
            can.push_back(i);
        }
    }

    int res = 0, resc = 0;
    while (true) {
        int lg = 0, rg = can.size();
        while (rg - lg > 1) {
            int mg = (lg + rg) >> 1;
            if (can[mg] <= res + d) {
                lg = mg;
            } else {
                rg = mg;
            }
        }

        if (can[lg] > res) {
            res = can[lg];
            resc++;
        } else {
            break;
        }
    }

    cout << res << " " << resc << "\n";

    return 0;
}