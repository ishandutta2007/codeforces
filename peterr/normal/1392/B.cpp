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
        long long k;
        cin >> n >> k;
        int mx = -1000000001;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        k--;
        for (int i = 0; i < n; i++)
        {
            a[i] = mx - a[i];
        }
        mx = -1000000001;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, a[i]);
        }
        if (k & 1)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = mx - a[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}