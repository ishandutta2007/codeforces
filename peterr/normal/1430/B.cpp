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
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long ans = 0;
        if (k == 0)
            ans = a[n - 1] - a[0];
        else
        {
            for (int i = 0; i <= k; i++)
                ans += a[n - 1 - i];
        }
        cout << ans << "\n";
    }
    return 0;
}