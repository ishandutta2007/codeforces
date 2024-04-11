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

const int MX = 200 * 1000 + 7;
const int LG = 20;

int p[MX], l[MX];
int nxt[LG][MX];
int wnxt[LG][MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> l[i];
    }
    vector<int> st;
    nxt[0][n + 1] = n + 1;
    wnxt[0][n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && p[i] + l[i] >= p[st.back()] + l[st.back()]) {
            st.pop_back();
        }
        if (st.empty()) {
            nxt[0][i] = n + 1;
            wnxt[0][i] = 0;
        } else {
            if (p[i] + l[i] >= p[st.back()]) {
                nxt[0][i] = nxt[0][st.back()];
                wnxt[0][i] = wnxt[0][st.back()];
            } else {
                nxt[0][i] = st.back();
                wnxt[0][i] = p[st.back()] - p[i] - l[i];
            }
        }
        st.push_back(i);
    }

    for (int i = 1; i < LG; i++) {
        for (int j = 1; j <= n + 1; j++) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            wnxt[i][j] = wnxt[i - 1][j] + wnxt[i - 1][nxt[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (nxt[0][x] > y) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        for (int j = LG - 1; j >= 0; j--) {
            int nx = nxt[j][x];
            if (nxt[0][nx] <= y) {
                ans += wnxt[j][x];
                x = nx;
            }
        }
        ans += wnxt[0][x];
        cout << ans << "\n";
    }
    return 0;
}