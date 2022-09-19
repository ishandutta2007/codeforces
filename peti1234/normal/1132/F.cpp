#include <bits/stdc++.h>

using namespace std;
const int c=502;
int n, dp[c][c];
string s;
int solve(int a, int b) {
    if (a>=b) return 0;
    if (!dp[a][b]) {
        int mini=1+solve(a+1, b);
        for (int i=a+1; i<b; i++) {
            if (s[a]==s[i]) {
                mini=min(mini, solve(a+1, i)+solve(i, b));
            }
        }
        dp[a][b]=mini;
    }
    return dp[a][b];
}
int main()
{
    cin >> n >> s;
    cout << solve(0, n) << "\n";
    return 0;
}