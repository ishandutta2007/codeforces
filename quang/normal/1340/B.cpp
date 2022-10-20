#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, k;
int mask[20];
int a[N];
int dp[N][N];

int getMask(string u) {
    int res = 0;
    for (char v : u) {
        res = res * 2 + (v - '0');
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mask[0] = getMask("1110111");
    mask[1] = getMask("0010010");
    mask[2] = getMask("1011101");
    mask[3] = getMask("1011011");
    mask[4] = getMask("0111010");
    mask[5] = getMask("1101011");
    mask[6] = getMask("1101111");
    mask[7] = getMask("1010010");
    mask[8] = getMask("1111111");
    mask[9] = getMask("1111011");

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string u;
        cin >> u;
        a[i] = getMask(u);
    }

    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= k; j++) {
            for (int num = 0; num <= 9; num++) {
                if ((mask[num] & a[i]) == a[i]) {
                    int now = __builtin_popcount(mask[num]) - __builtin_popcount(a[i]);
                    if (j - now >= 0 && dp[i + 1][j - now]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
    }
    if (dp[1][k] == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            int res = -1;
            for (int num = 9; num >= 0; num--) {
                if ((mask[num] & a[i]) == a[i]) {
                    int now = __builtin_popcount(mask[num]) - __builtin_popcount(a[i]);
                    if (k - now >= 0 && dp[i + 1][k - now]) {
                        res = num;
                        break;
                    }
                }
            }
            cout << res;
            k -= (__builtin_popcount(mask[res]) - __builtin_popcount(a[i]));
        }
        cout << '\n';
    }
    return 0;
}