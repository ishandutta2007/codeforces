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
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i)
                ans += abs(a[i] - a[i - 1]);
        }
        long long good = 0;
        for (int i = 0; i < n; i++)
        {
            int mn = 1E9;
            int mx = -1E9;
            int cnt = 0;
            if (i)
            {
                cnt++;
                mn = min(mn, a[i - 1]);
                mx = max(mx, a[i - 1]);
            }
            if (i + 1 < n)
            {
                cnt++;
                mn = min(mn, a[i + 1]);
                mx = max(mx, a[i + 1]);
            }
            if (a[i] < mn)
            {
                good = max(good, (long long) (mn - a[i]) * cnt);
            }
            if (a[i] > mx)
            {
                good = max(good, (long long) (a[i] - mx) * cnt);
            }
        }
        cout << ans - good << "\n";
    }
    return 0;
}