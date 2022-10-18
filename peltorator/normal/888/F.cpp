#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

const int N = 501, TWO = 2;
const ll MOD = 1e9 + 7;

int can[N][N];
ll dp[N][N][TWO];


int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> can[i][j];
    for (int i = 0; i < n; i++)
        dp[i][i][0] = 1;
    for (int d = 1; d < n; d++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = (i + d) % n;
            if (can[i][j])
                for (int k = i; k != j; k = (k + 1) % n)
                    dp[i][j][1] = (dp[i][j][1] + dp[i][k][0] * dp[(k + 1) % n][j][0]) % MOD;
            dp[i][j][0] = dp[i][j][1];
            for (int k = (i + 1) % n; k != j; k = (k + 1) % n)
                dp[i][j][0] = (dp[i][j][0] + dp[i][k][1] * dp[k][j][0]) % MOD;
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j][0] << " ";
        cout << endl;
    }*/
    cout << dp[0][n - 1][0];
    return 0;
}