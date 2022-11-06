#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int ans = 0;
        int dig = 1;
        while (1)
        {
            int temp = dig;
            int cnt = 1;
            while (temp <= 10000)
            {
                ans += cnt;
                cnt++;
                if (temp == x)
                    break;
                temp = temp * 10 + dig;
            }
            if (temp == x)
                break;
            dig++;
        }
        cout << ans << "\n";
    }
    return 0;
}