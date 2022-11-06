#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 1000;
        for (int i = 0; i < 60; i++)
        {
            if (b + i == 1)
                continue;
            int x = a;
            int cnt = i;
            while (x)
            {
                x /= b + i;
                cnt++;
            }
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}