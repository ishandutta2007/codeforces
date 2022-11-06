#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
bool poss[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][MAXN + 1][10];
int bin[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int a[MAXN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = n; i >= 1; i--)
    {
        string s;
        cin >> s;
        a[i] = stoi(s, nullptr, 2);
        //cout << a[i] << endl;
    }
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < 10; j++)
            dp[0][i][j] = -1;
    poss[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int d = 0; d < 10; d++)
            {
                dp[i][j][d] = -1;
                if ((a[i] | bin[d]) != bin[d])
                    continue;
                int cost = __builtin_popcount(bin[d]) - __builtin_popcount(a[i] & bin[d]);
                if (cost > j)
                    continue;
                if (!poss[i - 1][j - cost])
                    continue;
                dp[i][j][d] = cost;
                poss[i][j] = true;
            }
        }
    }
    if (!poss[n][k])
        cout << -1 << "\n";
    else
    {
        stringstream ss;
        for (int i = n; i >= 1; i--)
        {
            int d = 9;
            while (1)
            {
                if (dp[i][k][d] != -1)
                    break;
                d--;
            }
            k -= dp[i][k][d];
            ss << d;
        }
        cout << ss.str() << "\n";
    }
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int d = 0; d < 10; d++)
                cout << i << " " << j << " " << d << " " << dp[i][j][d] << endl;
    */
    return 0;
}