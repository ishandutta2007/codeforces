#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
bool dp[MAXN][1 << MAXN];
int mask[MAXN][26];
string a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
        {
            fill(mask[i], mask[i] + 26, 0);
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int key = a[k][i] - 'a';
                    if (key != j)
                        mask[i][j] |= (1 << k);
                }
            }
        }
        fill(dp[0], dp[0] + (1 << n), false);
        for (int i = 0; i < 26; i++)
        {
            dp[0][mask[0][i]] = true;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                dp[i][j] = false;
                for (int ch = 0; ch < 26; ch++)
                {
                    int hit = mask[i][ch];
                    if ((hit & j) != hit)
                        continue;
                    int resMask = j ^ hit;
                    if (dp[i - 1][resMask])
                        dp[i][j] = true;
                }
            }
        }
        bool poss = false;
        int startMask = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            if (dp[m - 1][i])
            {
                poss = true;
                startMask = i;
            }
        }
        if (!poss)
            cout << "-1\n";
        else
        {
            vector<char> ans;
            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = 0; j < 26; j++)
                {
                    if ((mask[i][j] & startMask) == mask[i][j] && (i == 0 || dp[i - 1][startMask ^ mask[i][j]]))
                    {
                        startMask ^= mask[i][j];
                        ans.push_back((char) ('a' + j));
                        break;
                    }
                }
            }
            while (!ans.empty())
            {
                cout << ans.back();
                ans.pop_back();
            }
            cout << "\n";
        }
    }
    return 0;
}