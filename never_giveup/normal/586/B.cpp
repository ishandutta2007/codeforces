#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a[2][50], b[50];
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n - 1; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 1e9;
    for (int l = 0; l < n; l++)
        for (int r = 0; r < n; r++)
            if (l != r){
                int now = 0;
                for (int i = n - 2; i >= l; i--)
                    now += a[1][i];
                now += b[l];
                for (int i = 0; i < l; i++)
                    now += a[0][i];
                for (int i = 0; i < r; i++)
                    now += a[0][i];
                now += b[r];
                for (int i = r; i < n - 1; i++)
                    now += a[1][i];
                ans = min(ans, now);
            }
    cout << ans;
}