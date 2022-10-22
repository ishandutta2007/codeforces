#include <bits/stdc++.h>
using namespace std;
int A[3][3] = {{1, 7, 9}, {3, 2, 5}, {4, 8, 6}};
int ans[505][505];
int main()
{
    int n, cnt = 0;
    cin >> n;
    if (n <= 2)
        cout << -1;
    else
    {
        for (int k = 3; k < n; k += 2)
        {
            for (int i = 0; i < k; ++i)
                ans[i][k] = ++cnt;
            for (int i = k; i >= 0; --i)
                ans[k][i] = ++cnt;
            if (k == n - 1)
                break;
            for (int i = 0; i <= k; ++i)
                ans[k + 1][i] = ++cnt;
            for (int i = k + 1; i >= 0; --i)
                ans[i][k + 1] = ++cnt;
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ans[i][j] = A[i][j] + cnt;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}