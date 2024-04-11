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
        int n;
        cin >> n;
        int ans = 0;
        int two = 4;
        while (1)
        {
            if (n % (two - 1) == 0)
            {
                ans = n / (two - 1);
                break;
            }
            two = 2 * two;
        }
        cout << ans << "\n";
    }
    return 0;
}