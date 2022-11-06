#include <bits/stdc++.h>

using namespace std;

const int MAXX = 2E5;
const int MAXN = 3000;
int coords[2 * MAXN + 1];
int conv[MAXX];
pair<int, int> segs[MAXN];
vector<int> segs2[2 * MAXN + 1];
int dp[2 * MAXN + 1][2 * MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> segs[i].first >> segs[i].second;
            coords[2 * i + 1] = segs[i].first;
            coords[2 * i + 2] = segs[i].second;
        }
        sort(coords, coords + 2 * n + 1);
        int cur = 0;
        for (int i = 1; i < 2 * n + 1; i++)
        {
            if (coords[i] != coords[i - 1])
            {
                conv[coords[i]] = cur++;
            }
        }
        for (int i = 0; i < cur; i++)
        {
            segs2[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            int newl = conv[segs[i].first];
            int newr = conv[segs[i].second];
            segs2[newl].push_back(newr);
        }
        for (int len = 0; len < cur; len++)
        {
            for (int i = 0; i + len < cur; i++)
            {
                int j = i + len;
                if (len)
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = 0;
                for (int x : segs2[i])
                {
                    if (x >= j)
                        continue;
                    dp[i][j] = max(dp[i][j], dp[x + 1][j] + dp[i][x]);
                }
                for (int x : segs2[i])
                {
                    if (x == j)
                        dp[i][j]++;
                }
                //cout << i << " " << j << " " << dp[i][j] << "\n";
            }
        }
        cout << dp[0][cur - 1] << "\n";
    }
    return 0;
}