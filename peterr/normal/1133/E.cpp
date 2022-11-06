#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int students[MAXN + 1];
int dp[MAXN + 1][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> students[i];
    }
    sort(students + 1, students + n + 1);
    int ptr = 1;
    for (int s = 1; s <= n; s++)
    {
        while (students[s] - students[ptr] > 5)
            ptr++;
        for (int t = 1; t <= k; t++)
        {
            dp[s][t] = max(dp[s - 1][t], s - ptr + 1 + dp[ptr - 1][t - 1]);
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}