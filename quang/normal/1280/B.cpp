#include <bits/stdc++.h>

using namespace std;

const int N = 66;

int n, m;
char s[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        int allA = 1, allP = 1;
        int maxCorner = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                allA &= (s[i][j] == 'A');
                allP &= (s[i][j] == 'P');
                if (s[i][j] == 'A') {
                    int cnt = 0;
                    if (i == 1 || i == n) cnt++;
                    if (j == 1 || j == m) cnt++;
                    maxCorner = max(maxCorner, cnt);
                }
            }
        }

        for (int col = 1; col <= m; col++) {
            int found = 0;
            for (int i = 1; i <= n; i++) {
                found |= (s[i][col] == 'P');
            }
            if (!found) {
                int cnt = 2;
                if (col == 1 || col == m) cnt++;
                maxCorner = max(maxCorner, cnt);
            }
        }

        for (int row = 1; row <= n; row++) {
            int found = 0;
            for (int j = 1;  j <= m; j++) {
                found |= (s[row][j] == 'P');
            }
            if (!found) {
                int cnt = 2;
                if (row == 1 || row == n) cnt++;
                maxCorner = max(maxCorner, cnt);
            }
        }

        if (allP) {
            cout << "MORTAL" << '\n';
            continue;
        }
        if (allA) {
            cout << 0 << '\n';
            continue;
        }
        cout << 4 - maxCorner << '\n';
    }
    return 0;
}