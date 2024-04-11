#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cur = 0;
        bool ans = false;
        while (cur <= n)
        {
            if ((n - cur) % 2021 == 0)
            {
                ans = true;
                break;
            }
            cur += 2020;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}