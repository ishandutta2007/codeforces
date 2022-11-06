#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
int a[MAXN + 1];
int dp[MAXN + 1];
int last[MAXN + 1];
int first[MAXN + 1];
int freq[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(last, last + n + 1, n + 1);
    fill(first, first + n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[a[i]] = i;
        first[a[i]] = min(first[a[i]], i);
        freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (last[a[i]] == i)
        {
            dp[i] = max(dp[i], freq[a[i]] + dp[first[a[i]] - 1]);
        }
    }
    int ans = n - dp[n];
    fill(freq, freq + n + 1, 0);
    int mx = 0;
    for (int i = n; i >= 1; i--)
    {
        freq[a[i]]++;
        mx = max(mx, freq[a[i]]);
        ans = min(ans, n - dp[i - 1] - mx);
    }
    cout << ans << "\n";
    return 0;
}