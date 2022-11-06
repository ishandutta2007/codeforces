#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mx = 0;
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                mx = a[i];
            else
            {
                diff = max(diff, mx - a[i]);
                mx = max(mx, a[i]);
            }
        }
        if (diff == 0)
            cout << 0 << "\n";
        else
        {
            cout << 32 - __builtin_clz(diff) << "\n";
        }
    }
    return 0;
}