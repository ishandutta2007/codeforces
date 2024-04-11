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
 
typedef vector<int> number;
typedef long long ll;

const int N = 51, M = 31;
 
int dp[M][M][N];

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
                dp[i][j][k] = 1e9;
            dp[i][j][0] = 0;
        }
    dp[1][1][1] = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                if (i * j == k)
                    dp[i][j][k] = 0;
                if (dp[i][j][k] < 1e8)
                    continue;
                for (int l = 1; l < j; l++)
                    for (int m = 0; m <= k; m++)
                        dp[i][j][k] = min(dp[i][j][k], dp[i][l][m] + dp[i][j - l][k - m] + i * i);
                for (int l = 1; l < i; l++)
                    for (int m = 0; m < k; m++)
                        dp[i][j][k] = min(dp[i][j][k], dp[l][j][m] + dp[i - l][j][k - m] + j * j);
            }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cout << dp[x][y][z] << "\n";
    }
    cout << endl;
    return 0;
}