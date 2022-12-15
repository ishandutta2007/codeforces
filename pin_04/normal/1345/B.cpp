#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum(int n)
{
    return n * (n + 1) / 2;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        while (n > 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (n < 3 * sum(i) - i)
                {
                    n -= 3 * sum(i - 1) - (i - 1);
                    break;
                }
            }
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}