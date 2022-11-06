#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool same = true;
        int n;
        cin >> n;
        int mx;
        cin >> mx;
        a[0] = mx;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
            if (x > mx)
            {
                same = false;
                mx = x;
            }
            else if (x < mx)
            {
                same = false;
            }
        }
        if (same)
            cout << "-1\n";
        else
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < mx)
                    continue;
                if (a[i] > a[min(i + 1, n - 1)] || a[i] > a[max(0, i - 1)])
                {
                    ans = i + 1;
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}