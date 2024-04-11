#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 25;

const int SQRT = 203;

int a[MAXN];

vector<vector<int>> mod(MAXN, vector<int>(SQRT));

vector<vector<int>> sum(SQRT);

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 1; j < SQRT; ++j)
        {
            mod[i][j] = i % j;
        }
    }
    for (int i = 1; i < SQRT; ++i)
    {
        sum[i].resize(i);
    }
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int pos, val;
            cin >> pos >> val;
            a[pos] += val;
            for (int j = 1; j < SQRT; ++j)
            {
                sum[j][mod[pos][j]] += val;
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (x < SQRT)
            {
                cout << sum[x][y] << "\n";
            }
            else
            {
                int ans = 0;
                for (int pos = y; pos < MAXN; pos += x)
                {
                    ans += a[pos];
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}