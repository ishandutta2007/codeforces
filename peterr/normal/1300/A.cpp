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
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                x++;
                ans++;
            }
            sum += x;
        }
        cout << ans + (sum == 0) << endl;
    }
    return 0;
}