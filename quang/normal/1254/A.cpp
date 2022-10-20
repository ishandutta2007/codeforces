#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int r, c, k;
char a[N][N];
char res[N][N];

char get(int u) {
    if (u < 26) return 'a' + u;
    u -= 26;
    if (u < 26) return 'A' + u;
    u -= 26;
    return '0' + u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> r >> c >> k;
        for (int i = 1; i <= r; i++) cin >> (a[i] + 1);
        int tot = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) tot += a[i][j] == 'R';
        }
        int each = tot / k;
        int lim = tot % k;
        int type = 0;
        int cur = 0;
        for (int i = 1; i <= r; i++) {
            if (i & 1) {
                for (int j = 1; j <= c; j++) {
                    cur += a[i][j] == 'R';
                    if (cur > each + (type < lim)) {
                        cur = 1;
                        type++;
                    }
                    res[i][j] = get(type);
                }
            } else {
                for (int j = c; j > 0; j--) {
                    cur += a[i][j] == 'R';
                    if (cur > each + (type < lim)) {
                        cur = 1;
                        type++;
                    }
                    res[i][j] = get(type);
                }
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) cout << res[i][j];
                cout << '\n';
        }
    }
    return 0;
}