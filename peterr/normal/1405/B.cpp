#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
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
        {
            cin >> a[i];
        }
        int p1 = 0;
        int p2 = 0;
        while (p2 < n)
        {
            while (p1 < n && a[p1] <= 0)
                p1++;
            p2 = max(p2, p1);
            while (p2 < n && a[p2] >= 0)
                p2++;
            if (p2 < n)
            {
                int amt = min(a[p1], -a[p2]);
                a[p1] -= amt;
                a[p2] += amt;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
                ans += a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}