#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int colors[MAXN];
int colors2[MAXN];
int dp[MAXN + 1][MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < n)
    {
        colors[ptr2] = colors[ptr1];
        while (ptr1 + 1 < n && colors[ptr1] == colors[ptr1 + 1])
            ptr1++;
        ptr1++;
        ptr2++;
    }
    n = ptr2;
    for (int i = 0; i < n; i++)
        colors2[i] = colors[n - i - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (colors[i - 1] == colors2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    /*
    for (int i = 0; i < n; i++)
        cout << colors[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << colors2[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    */
    cout << (n - 1) - (dp[n][n] - 1) / 2 << endl;
    return 0;
}