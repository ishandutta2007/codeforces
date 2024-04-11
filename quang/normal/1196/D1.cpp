#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q, k;
char s[N];
int a[N];
int dp[3][3][N];

int get(int l, int r, int color, int pos) {
    return dp[color][pos][r] - dp[color][pos][l];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cin >> (s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'R') a[i] = 0;
            else if (s[i] == 'G') a[i] = 1;
            else a[i] = 2;
        }
        for (int i = 1; i <= n; i++) {
            for (int color = 0; color < 3; color++) {
                for (int pos = 0; pos < 3; pos++) {
                    dp[color][pos][i] = dp[color][pos][i - 1];
                    if (i % 3 == pos) {
                        dp[color][pos][i] += (a[i] == color);
                    }
                }
            }
        }
        int res = 0;
        for (int i = k; i <= n; i++) {
            for (int pos = 0; pos < 3; pos++) {
                int cnt = 0;
                for (int color = 0; color < 3; color++) {
                    cnt += get(i - k, i, color, (pos + color) % 3);
                }
                res = max(res, cnt);
            }
        }
        cout << k - res << endl;
    }
    return 0;
}