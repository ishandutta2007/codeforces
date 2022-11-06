#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int h[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        int ans = -1;
        while (k)
        {
            int j = 1;
            while (j < n && h[j] >= h[j + 1])
            {
                j++;
            }
            if (j < n)
            {
                ans = j;
                h[j]++;
            }
            else
            {
                ans = -1;
                break;
            }
            k--;
        }
        cout << ans << "\n";
    }
    return 0;
}