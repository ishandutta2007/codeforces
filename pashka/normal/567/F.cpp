#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka
int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    n *= 2;
    vector<vector<int>> cmp(n, vector<int>(n, 7));
    for (int i = 0; i < k; i++) {
        int x;
        string s;
        int y;
        cin >> x >> s >> y;
        x--;
        y--;
        int s1 = 0, s2 = 0;
        for (char c : s) {
            if (c == '=') {
                s1 |= 1;
                s2 |= 1;
            }
            if (c == '<') {
                s1 |= 2;
                s2 |= 4;
            }
            if (c == '>') {
                s1 |= 4;
                s2 |= 2;
            }
        }
        cmp[x][y] &= s1;
        cmp[y][x] &= s2;
    }

    vector<vector<long>> d(n, vector<long>(n));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r += 2) {
            vector<vector<int>> pp = {{l,     l + 1, l + 2, r},
                                      {l,     r, l + 1, r - 1},
                                      {r - 1, r, l, r - 2}};
            for (auto p : pp) {
                int x = p[0];
                int y = p[1];
                bool ok = (cmp[x][y] & 1);
                for (int i = 0; i < l; i++) {
                    ok = ok && (cmp[i][x] & 2);
                    ok = ok && (cmp[i][y] & 2);
                }
                for (int i = r + 1; i < n; i++) {
                    ok = ok && (cmp[i][x] & 2);
                    ok = ok && (cmp[i][y] & 2);
                }
                if (ok) {
                    if (r == l + 1) {
                        d[l][r] = 1;
                    } else {
                        d[l][r] += d[p[2]][p[3]];
                    }
                }
            }
        }
    }
    cout << d[0][n - 1];

    return 0;
}