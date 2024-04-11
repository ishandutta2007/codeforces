#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int num[10];

const int MAXN = 2e3 + 77;

int dp[MAXN][MAXN];
int can[MAXN][MAXN];

int cnt[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    num[0] = 119;
    num[1] = 18;
    num[2] = 93;
    num[3] = 91;
    num[4] = 58;
    num[5] = 107;
    num[6] = 111;
    num[7] = 82;
    num[8] = 127;
    num[9] = 123;
    for (int i = 1; i < 128; ++i)
    {
        if (i % 2 == 1)
        {
            cnt[i] = cnt[i / 2] + 1;
        }
        else
        {
            cnt[i] = cnt[i / 2];
        }
    }
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int x = 0;
        for (int j = 0; j < 7; ++j)
        {
            x *= 2;
            x += (s[j] - '0');
        }
        a[n - i - 1] = x;
    }
    can[0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int t = 0; t < 10; ++t)
            {
                int d = num[t] ^ a[i];
                if (((num[t] & a[i]) == a[i]) && cnt[d] <= j && can[i][j - cnt[d]])
                {
                    can[i + 1][j] = true;
                    dp[i + 1][j] = t;
                }
            }
        }
    }
    int c = k;
    if (!can[n][c])
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = n; i > 0; --i)
    {
        cout << dp[i][c];
        c -= cnt[a[i - 1] ^ num[dp[i][c]]];
    }
    cout << endl;
    return 0;
}