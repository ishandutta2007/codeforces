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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int p = 0;
        long long ans = 0;
        while (p < n)
        {
            int mx = a[p];
            while (p + 1 < n && (long long) a[p] * a[p + 1] > 0)
            {
                p++;
                mx = max(mx, a[p]);
            }
            ans += mx;
            p++;
        }
        cout << ans << "\n";
    }
    return 0;
}