#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k >= n)
        {
            cout << "1\n";
            continue;
        }
        int ans = -1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0 && n / i <= k)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1)
        {
            for (int i = 1; i * i <= n; i++)
            {
                if (n % i == 0 && i <= k)
                    ans = n / i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}