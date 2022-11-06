#include <bits/stdc++.h>

using namespace std;

const int MAXK = 30;
const int MOD = 998244353;
const int MAXN = 5E5;
tuple<int, int, int> conditions[MAXN];
int dp[MAXN + 1];
int oneEnd[MAXN + 1];
int zeroEnd[MAXN + 1];

int solve(int n, int m, int bit)
{
    dp[0] = 1;
    int ones = 0;
    int cur = 0;
    fill(oneEnd, oneEnd + n + 1, 0);
    fill(zeroEnd, zeroEnd + n + 1, 0);
    int left = 0;
    int ptr = 0;
    int sum = 1;
    int trueEnd = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cur < m && get<0>(conditions[cur]) == i)
        {
            int end = get<1>(conditions[cur]);
            if (get<2>(conditions[cur]) & (1 << bit))
            {
                ones++;
                oneEnd[end]++;
            }
            else
            {
                trueEnd = max(trueEnd, get<0>(conditions[cur]));
                zeroEnd[end] = max(zeroEnd[end], get<0>(conditions[cur]));
            }
            cur++;
        }
        ones -= oneEnd[i - 1];
        left = max(left, zeroEnd[i - 1]);
        while (ptr < left)
        {
            sum = sum - dp[ptr] + MOD;
            if (sum >= MOD)
                sum -= MOD;
            ptr++;
        }
        if (ones)
            dp[i] = 0;
        else
        {
            dp[i] = sum;
            sum += dp[i];
            if (sum >= MOD)
                sum -= MOD;
        }
    }
    int ans = 0;
    for (int i = n; i >= trueEnd; i--)
    {
        ans += dp[i];
        if (ans >= MOD)
            ans -= MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        conditions[i] = make_tuple(l, r, x);
    }
    sort(conditions, conditions + m);
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = (int) (((long long) ans * solve(n, m, i)) % MOD);
    }
    cout << ans << "\n";
    return 0;
}