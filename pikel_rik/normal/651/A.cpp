#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[201][201];

int maxTurns(int a1, int a2) {
    if (a1 <= 0 or a2 <= 0)
        return 0;
    if (dp[a1][a2] != -1)
        return dp[a1][a2];
    return dp[a1][a2] = 1 + max(maxTurns(a1 + 1, a2 - 2), maxTurns(a1 - 2, a2 + 1));
}

int main() {
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    int a1, a2;
    cin >> a1 >> a2;

    if (a1 <= 1 and a2 <= 1)
        cout << "0";
    else
        cout << maxTurns(a1, a2);
    return 0;
}