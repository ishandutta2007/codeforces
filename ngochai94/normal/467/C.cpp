#include <iostream>

using namespace std;

long long n, m, k, lis[5555], pre[5555], dp[5555][5555];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> lis[i];
        pre[i] = pre[i - 1] + lis[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * m <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + pre[i] - pre[i - m]);
        }
    }
    cout << dp[n][k];
}