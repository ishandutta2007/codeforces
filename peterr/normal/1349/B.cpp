#include <bits/stdc++.h>

using namespace std;

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
        bool seen = false;
        bool close = false;
        if (n == 1)
            close = true;
        int prev = -5;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == k)
                seen = true;
            if (x >= k)
            {
                if (i - prev <= 2)
                    close = true;
                prev = i;
            }
        }
        if (seen && close)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}