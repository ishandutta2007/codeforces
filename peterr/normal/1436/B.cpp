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
        for (int i = 0; i < n; i++)
        {
            fill(ans[i], ans[i] + n, 0);
            for (int j = i - 1; j <= i + 1; j++)
            {
                if (j < 0 || j >= n)
                    continue;
                ans[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}