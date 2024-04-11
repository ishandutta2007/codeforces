#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
using lint = long long;
//at most one dead end tunnel
//all tunnel have right turns
//right-tunnel cannot star at lowest except row 1
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int R, C, K;

set<int> ROW[300005], COL[300005], ALLROW, ALLCOL;
int str, etr, stc, etc;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> K;
    str = 2, etr = R, stc = 1, etc = C;
    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        ROW[r].insert(c);
        COL[c].insert(r);
        ALLROW.insert(c);
        ALLCOL.insert(r);
    }
    int i = 1, j = 1, d = 0, ans = 1;
    while (ans < R * C - K && str <= etr + 1 && stc <= etc + 1) {
        if (d == 0) {
            auto k = ROW[i].lower_bound(j);
            if (k != ROW[i].end() && *k <= etc + 1) {
                // cout << "No\n";
                // return 0;
                if (*k - 1 < stc) break;
                ans += labs(j - (*k - 1));
                j = *k - 1;
                etc = *k - 2;
            } else {
                ans += etc - j;
                j = etc;
                etc--;
            }
            d++;
            d %= 4;
        } else if (d == 1) {
            auto k = COL[j].lower_bound(i);
            if (k != COL[j].end() && *k <= etr + 1) {
                // cout << "No\n";
                // return 0;
                if (*k - 1 < str) break;
                ans += labs(i - (*k - 1));
                i = *k - 1;
                etr = *k - 2;
            } else {
                ans += etr - i;
                i = etr;
                etr--;
            }
            d++;
            d %= 4;
        } else if (d == 2) {
            auto k = ROW[i].upper_bound(j);
            bool ok = k != ROW[i].begin();
            if (k != ROW[i].begin()) k = prev(k);
            
            if (ok && *k >= stc - 1) {
                // cout << "No\n";
                // return 0;
                if (*k - 1 > etc) break;
                ans += labs(j - (*k + 1));
                j = *k + 1;
                stc = *k + 2;
            } else {
                ans += j - stc;
                j = stc;
                stc++;
            }
            d++;
            d %= 4;
        } else if (d == 3) {
            auto k = COL[j].upper_bound(i);
            bool ok = (k != COL[j].begin());
            if (k != COL[j].begin()) k = prev(k);
            if (ok && *k >= str - 1) {
                // cout << "No\n";
                // return 0;
                if (*k - 1 > etr) break;
                ans += labs(i - (*k + 1));
                i = *k + 1;
                str = *k + 2;
            } else {
                ans += i - str;
                i = str;
                str++;
            }
            d++;
            d %= 4;
        }
        // cout << i << " " << j << "\n";
    }
    // cout << "Yes\n";
    if (ans == R * C - K) cout << "Yes\n";
    else cout << "No\n";
}