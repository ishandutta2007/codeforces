#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        long long two = 2;
        int ans = 0;
        while (x >= two * (two - 1) / 2)
        {
            ans++;
            x -= two * (two - 1) / 2;
            two *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}