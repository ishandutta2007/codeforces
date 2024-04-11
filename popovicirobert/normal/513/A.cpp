#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 50;

int dp[MAXN + 1][MAXN + 1][2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n1, n2, k1, k2;
    ios::sync_with_stdio(false);
    cin >> n1 >> n2 >> k1 >> k2;
    for(i = 1; i <= n2; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }
    for(i = 1; i <= n1; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
    }
    for(int a = 1; a <= n1; a++) {
        for(int b = 1; b <= n2; b++) {
            for(i = 1; i <= k1 && i <= a; i++) {
                dp[a][b][0] |= (1 - dp[a - i][b][1]);
            }
            for(i = 1; i <= k2 && i <= b; i++) {
                dp[a][b][1] |= (1 - dp[a][b - i][0]);
            }
        }
    }
    if(dp[n1][n2][0])
        cout << "First";
    else
        cout << "Second";
    //cin.close();
    //cout.close();
    return 0;
}