#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        bool ans = false;
        for (int i = 0; i < n + m; i++)
        {
            int sum = 0;
            for (int r = 0; r < n; r++)
            {
                int c = i - r;
                if (c < 0 || c >= m)
                    continue;
                sum ^= a[r][c];
            }
            if (sum != 0)
                ans = true;
        }
        if (ans)
            cout << "Ashish\n";
        else
            cout << "Jeel\n";
    }
    return 0;
}