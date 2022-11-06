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
        long long ans = 0;
        for (int i = 2; i <= n - 1; i+= 2)
        {
            ans += (long long) i * (i / 2);
        }
        ans *= 4;
        cout << ans << endl;
    }
    return 0;
}