#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int maxMoves(int n, int m) {
    if (n == 1 or m == 1)
        return 1;
    if (dp[n][m] != -1)
        return dp[n][m];
    return dp[n][m] = 1 + maxMoves(n-1, m-1);
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    int a = maxMoves(n, m);

    if (a % 2 == 0)
        cout << "Malvika";
    else
        cout << "Akshat";
    return 0;
}