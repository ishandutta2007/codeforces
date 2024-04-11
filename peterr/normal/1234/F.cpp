#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int MAXK = 20;
bool occ[1 << MAXK];
int dp[1 << MAXK];

int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    occ[0] = true;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = i; j < n; j++)
        {
            int key = s[j] - 'a';
            if (cur & (1 << key))
                break;
            cur ^= (1 << key);
            //cout << cur << endl;
            occ[cur] = true;
        }
    }
    for (int i = 1; i < (1 << MAXK); i++)
    {
        if (occ[i])
            dp[i] = __builtin_popcount(i);
        else
        {
            for (int j = 0; j < MAXK; j++)
            {
                if (i & (1 << j))
                {
                    dp[i] = max(dp[i], dp[i ^ (1 << j)]);
                }
            }
        }
        //cout << i << " " << dp[i] << endl;
    }
    int ans = 0;
    for (int i = 0; i < (1 << MAXK); i++)
    {
        if (occ[i])
        {
            ans = max(ans, __builtin_popcount(i) + dp[~i & ((1 << MAXK) - 1)]);
        }
    }
    cout << ans << endl;
    return 0;
}