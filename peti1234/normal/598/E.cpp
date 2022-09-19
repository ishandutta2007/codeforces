#include <bits/stdc++.h>

using namespace std;
const int c=55;
int dp[c][c][c];
bool v[c][c][c];

int solve(int a, int b, int x) {
    if (x==0 || x==a*b) {
        return 0;
    }
    if (!v[a][b][x]) {
        int mini=1e6;
        for (int k=0; k<=x; k++) {
            for (int aa=1; aa<a; aa++) {
                mini=min(mini, b*b+solve(aa, b, k)+solve(a-aa, b, x-k));
            }
            for (int bb=1; bb<b; bb++) {
                mini=min(mini, a*a+solve(a, bb, k)+solve(a, b-bb, x-k));
            }
        }
        v[a][b][x]=1;
        dp[a][b][x]=mini;
    }
    return dp[a][b][x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b, x;
        cin >> a >> b >> x;
        cout << solve(a, b, x) << "\n";
    }
    return 0;
}