#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mx, mn;
        mx = -1;
        mn = 1E9 + 30;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != -1 && a[i - 1] != -1)
                ans = max(ans, abs(a[i] - a[i - 1]));
            else if (a[i] == -1 && a[i - 1] == -1)
                continue;
            if (a[i] == -1)
            {
                mx = max(mx, a[i - 1]);
                mn = min(mn, a[i - 1]);
            }
            else if (a[i - 1] == -1)
            {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
        }
        int k = (mx + mn) / 2;
        if (mx != -1)
        {
            ans = max(ans, max(abs(k - mx), abs(k - mn)));
        }
        cout << ans << " " << k << endl;
    }
    return 0;
}