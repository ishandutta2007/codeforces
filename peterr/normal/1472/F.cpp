#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E9 + 50;
const int MAXM = 2E5 + 50;
pair<int, int> a[MAXM];
bool dp[MAXM][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int r, c;
            cin >> r >> c;
            a[i] = {c, r};
        }
        a[m] = {0, 1};
        a[m + 1] = {0, 2};
        a[m + 2] = {n + 1, 1};
        a[m + 3] = {n + 1, 2};
        m += 4;
        n++;
        sort(a, a + m);
        vector<pair<int, int>> b;
        int ptr = 0;
        while (ptr < m)
        {
            int c = a[ptr].first;
            int mask = 0;
            while (ptr < m && a[ptr].first == c)
            {
                mask |= 1 << (a[ptr].second - 1);
                ptr++;
            }
            b.push_back({c, mask});
            //cout << "pushed " << b.back().first << " " << b.back().second << endl;
        }
        m = (int) b.size();
        for (int i = 0; i < m; i++)
            fill(dp[i], dp[i] + 4, false);
        dp[0][3] = true;
        for (int i = 1; i < m; i++)
        {
            if (b[i].second == 3)
            {
                dp[i][3] = dp[i - 1][3];
            }
            else if (b[i].second == 1)
            {
                dp[i][1] = dp[i][1] || dp[i - 1][3];
                if ((b[i].first - b[i - 1].first) & 1)
                    dp[i][3] = dp[i][3] || dp[i - 1][1];
                else
                    dp[i][3] = dp[i][3] || dp[i - 1][2];
            }
            else
            {
                dp[i][2] = dp[i][2] || dp[i - 1][3];
                if ((b[i].first - b[i - 1].first) & 1)
                    dp[i][3] = dp[i][3] || dp[i - 1][2];
                else
                    dp[i][3] = dp[i][3] || dp[i - 1][1];
            }
            /*
            for (int j = 0; j < 4; j++)
                cout << i << " " << bitset<2>(j) << " " << dp[i][j] << endl;
            */
        }
        cout << (dp[m - 1][3] ? "YES" : "NO") << "\n";
    }
    return 0;
}