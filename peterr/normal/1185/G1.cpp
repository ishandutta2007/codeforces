#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 15;
const int MAXT = 225;
const int MAXG = 3;
int dp[MAXT + 1][MAXG + 1][1 << MAXN];
pair<int, int> songs[MAXN];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> songs[i].first >> songs[i].second;
    }
    fill(dp[0][1], dp[0][1] + (1 << n), 1);
    fill(dp[0][2], dp[0][2] + (1 << n), 1);
    fill(dp[0][3], dp[0][3] + (1 << n), 1);
    for (int i = 1; i <= t; i++)
    {
        for (int bit = 1; bit < (1 << n); bit++)
        {
            for (int song = 0; song < n; song++)
            {
                if (bit & (1 << song))
                {
                    int time = songs[song].first;
                    int g = songs[song].second;
                    if (time == i)
                    {
                        dp[i][g][bit] = (dp[i][g][bit] + 1) % MOD;
                    }
                    else if (time <= i)
                    {
                        for (int genre = 1; genre <= 3; genre++)
                        {
                            if (genre == g)
                                continue;
                            dp[i][g][bit] = (dp[i][g][bit] + dp[i - time][genre][bit & ~(1 << song)]) % MOD;
                        }
                    }
                }
            }
        }
    }
    int allBit = (1 << n) - 1;
    cout << ((dp[t][1][allBit] + dp[t][2][allBit]) % MOD + dp[t][3][allBit]) % MOD;


    return 0;
}