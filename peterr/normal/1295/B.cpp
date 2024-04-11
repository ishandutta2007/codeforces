#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        string s;
        cin >> n >> x >> s;
        int totalBal = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                totalBal++;
            else
                totalBal--;
        }
        if (totalBal == 0)
        {
            int bal = 0;
            bool infinite = x == 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    bal++;
                else
                    bal--;
                if (bal == x)
                    infinite = true;
            }
            if (infinite)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            int cur = 0;
            int ans = x == 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    cur++;
                else
                    cur--;
                if (cur == x)
                    ans++;
                else
                {
                    if (totalBal > 0 && cur < x && (x - cur) % totalBal == 0)
                        ans++;
                    else if (totalBal < 0 && cur > x && (cur - x) % totalBal == 0)
                        ans++;
                }
            }
            cout << ans << endl;
        }

    }
    return 0;
}