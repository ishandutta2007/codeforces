#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int ans[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i][i];
    }
    for (int i = 1; i < n; i++)
    {
        bool found = false;
        for (int j = i; j < n; j++)
        {
            int col = j - i;
            if (found || ans[j - 1][col] - i == 0)
            {
                found = true;
                ans[j][col] = ans[j][col + 1];
            }
            else
                ans[j][col] = ans[j - 1][col];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ans[i][j] << " \n"[j == i];
        }
    }
    return 0;
}