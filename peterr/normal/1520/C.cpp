#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int ans[MAXN][MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        if (n == 2)
        {
            cout << "-1\n";
            continue;
        }
        int cur = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i][i] = cur++;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                ans[j][j - i] = cur++;
            }
            for (int j = i; j < n; j++)
            {
                ans[j - i][j] = cur++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}