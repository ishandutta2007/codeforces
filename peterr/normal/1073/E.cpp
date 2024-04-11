#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int dp[19][1 << 10][2][2];
int cnt[19][1 << 10][2][2];
int tenpow[19];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int solve(long long x, int k)
{
    if (x <= 0)
        return 0;
    int ans = 0;
    int n = (int) to_string(x).length();
    string s = to_string(x);
    for (int i = 1; i <= 9; i++)
    {
        if (i <= x)
            ans += i;
        cnt[1][1 << i][0][0] = 1;
        dp[1][1 << i][0][0] = i;
        cnt[1][1 << i][0][1] = i <= s[n - 1] - '0';
        dp[1][1 << i][0][1] = i * (i <= s[n - 1] - '0');

    }
    cnt[1][1][1][0] = cnt[1][1][1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int mask = 1; mask < (1 << 10); mask++)
        {
            dp[i][mask][0][0] = dp[i][mask][0][1] = dp[i][mask][1][0] = dp[i][mask][1][1] = 0;
            cnt[i][mask][0][0] = cnt[i][mask][0][1] = cnt[i][mask][1][0] = cnt[i][mask][1][1] = 0;
            if (__builtin_popcount(mask) > k)
                continue;
            if (mask & 1)
            {
                add(dp[i][mask][1][0], dp[i - 1][mask][1][0]);
                add(dp[i][mask][1][0], dp[i - 1][mask][0][0]);
                add(dp[i][mask][1][0], dp[i - 1][mask ^ 1][0][0]);
                add(cnt[i][mask][1][0], cnt[i - 1][mask][1][0]);
                add(cnt[i][mask][1][0], cnt[i - 1][mask][0][0]);
                add(cnt[i][mask][1][0], cnt[i - 1][mask ^ 1][0][0]);
                bool big = s[n - i] == '0';
                add(dp[i][mask][1][1], dp[i - 1][mask][1][big]);
                add(dp[i][mask][1][1], dp[i - 1][mask][0][big]);
                add(dp[i][mask][1][1], dp[i - 1][mask ^ 1][0][big]);
                add(cnt[i][mask][1][1], cnt[i - 1][mask][1][big]);
                add(cnt[i][mask][1][1], cnt[i - 1][mask][0][big]);
                add(cnt[i][mask][1][1], cnt[i - 1][mask ^ 1][0][big]);
                //dp[i][mask][1][1] = dp[i][mask][1][0];
                //cnt[i][mask][1][1] = cnt[i][mask][1][0];
            }
            for (int j = 1; j <= 9; j++)
            {
                if ((mask & (1 << j)) == 0)
                    continue;
                int localAns = 0;
                add(localAns, dp[i - 1][mask][0][0]);
                add(localAns, dp[i - 1][mask][1][0]);
                add(localAns, dp[i - 1][mask ^ (1 << j)][0][0]);
                add(localAns, dp[i - 1][mask ^ (1 << j)][1][0]);
                add(dp[i][mask][0][0], localAns);
                int localCnt = 0;
                add(localCnt, cnt[i - 1][mask][0][0]);
                add(localCnt, cnt[i - 1][mask][1][0]);
                add(localCnt, cnt[i - 1][mask ^ (1 << j)][0][0]);
                add(localCnt, cnt[i - 1][mask ^ (1 << j)][1][0]);
                add(cnt[i][mask][0][0], localCnt);

                int temp = (int) (((long long) j * tenpow[i - 1]) % MOD);
                temp = (int) (((long long) temp * localCnt) % MOD);
                add(dp[i][mask][0][0], temp);
                if (i < n || j < (s[0] - '0'))
                {
                    add(ans, localAns);
                    add(ans, temp);
                }

            }
            int dig = s[n - i] - '0';
            for (int j = 1; j <= dig; j++)
            {
                if ((mask & (1 << j)) == 0)
                    continue;
                int localAns = 0;
                int localCnt = 0;
                bool big = j == dig;
                add(localAns, dp[i - 1][mask][0][big]);
                add(localAns, dp[i - 1][mask][1][big]);
                add(localAns, dp[i - 1][mask ^ (1 << j)][0][big]);
                add(localAns, dp[i - 1][mask ^ (1 << j)][1][big]);
                add(dp[i][mask][0][1], localAns);
                add(localCnt, cnt[i - 1][mask][0][big]);
                add(localCnt, cnt[i - 1][mask][1][big]);
                add(localCnt, cnt[i - 1][mask ^ (1 << j)][0][big]);
                add(localCnt, cnt[i - 1][mask ^ (1 << j)][1][big]);
                add(cnt[i][mask][0][1], localCnt);

                int temp = (int) (((long long) j * tenpow[i - 1]) % MOD);
                temp = (int) (((long long) temp * localCnt) % MOD);
                add(dp[i][mask][0][1], temp);
                if (i == n && j == dig)
                {
                    add(ans, localAns);
                    add(ans, temp);
                }
            }
            //cout << i << " " << mask << " " << ans << endl;
        }
    }
    return ans;
}

int main()
{
    tenpow[0] = 1;
    for (int i = 1; i <= 18; i++)
        tenpow[i] = (int) (((long long) tenpow[i - 1] * 10) % MOD);
    long long l, r;
    int k;
    cin >> l >> r >> k;
    int ans = solve(r, k) - solve(l - 1, k) + MOD;
    if (ans >= MOD)
        ans -= MOD;
    cout << ans << endl;
    return 0;
}