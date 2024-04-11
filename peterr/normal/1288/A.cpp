#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        long long best = 1E9 + 5;
        for (int i = 0; i < n; i++)
        {
            long long y = (d + i) / (i + 1);
            best = min(best, i + y);
            if (y == 1)
                break;
            i = (d + y) / (y - 1) - 2;
        }
        if (best <= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}