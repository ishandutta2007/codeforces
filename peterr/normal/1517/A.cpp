#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n % 2050 != 0)
            cout << "-1\n";
        else
        {
            int ans = 0;
            n /= 2050;
            while (n)
            {
                ans += n % 10;
                n /= 10;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}