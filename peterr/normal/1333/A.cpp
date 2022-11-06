#include <bits/stdc++.h>

using namespace std;

int main()
{
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
                if (i == n - 1 && j == m - 1)
                    cout << 'W';
                else
                    cout << 'B';
            }
            cout << endl;
        }
    }
    return 0;
}