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
        {
            cin >> a[i];
        }
        long long ans = 0;
        int mx = a[0];
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= mx)
            {
                mx = a[i];
                prev = 0;
            }
            else
            {
                int lift = mx - a[i];
                if (lift > prev)
                {
                    ans += lift - prev;
                }
                prev = lift;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}