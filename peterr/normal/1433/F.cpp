#include <bits/stdc++.h>

using namespace std;

const int MAXN = 70;
const int NEG = -1E8;
int a[MAXN + 1];
int dp[MAXN + 1][MAXN + 1][MAXN];
int best[MAXN][MAXN];
int dp2[MAXN][MAXN];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
        }
        for (int j = 0; j <= m; j++)
        {
            for (int z = 0; z <= MAXN; z++)
            {
                for (int x = 0; x < MAXN; x++)
                    dp[j][z][x] = NEG;
            }
        }
        dp[0][0][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            for (int cnt = 0; cnt <= m; cnt++)
            {
                for (int mod = 0; mod < k; mod++)
                {
                    dp[j][cnt][mod] = max(dp[j][cnt][mod], dp[j - 1][cnt][mod]);
                    if (cnt)
                    {
                        int newmod = (mod - a[j]) % k;
                        if (newmod < 0)
                            newmod += k;
                        if (dp[j - 1][cnt - 1][newmod] > NEG)
                            dp[j][cnt][mod] = max(dp[j][cnt][mod], a[j] + dp[j - 1][cnt - 1][newmod]);
                    }
                    //cout << j << " " << cnt << " " << mod << " " << dp[j][cnt][mod] << "\n";
                }
            }
        }
        for (int mod = 0; mod < k; mod++)
        {
            int mx = NEG;
            for (int j = 0; 2 * j <= m; j++)
            {
                mx = max(mx, dp[m][j][mod]);
            }
            best[i][mod] = mx;
        }
    }
    for (int i = 0; i < k; i++)
    {
        dp2[0][i] = best[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target < k; target++)
        {
            dp2[i][target] = NEG;
            for (int mod = 0; mod < k; mod++)
            {
                int newmod = (target - mod) % k;
                if (newmod < 0)
                    newmod += k;
                if (best[i][mod] > NEG && dp2[i - 1][newmod] > NEG)
                    dp2[i][target] = max(dp2[i][target], best[i][mod] + dp2[i - 1][newmod]);
            }
        }
    }
    cout << max(0, dp2[n - 1][0]) << "\n";
    return 0;
}