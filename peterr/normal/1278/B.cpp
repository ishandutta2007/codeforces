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
        int diff = abs(a - b);
        int ans = 0;
        int sum = 0;
        while (sum < diff || (sum + diff) % 2 == 1)
        {
            ans++;
            sum += ans;
        }
        cout << ans << endl;
    }
    return 0;
}