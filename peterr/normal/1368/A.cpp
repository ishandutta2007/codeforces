#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        while (1)
        {
            if (a < b)
                swap(a, b);
            if (a > n)
                break;
            ans++;
            b += a;
        }
        cout << ans << "\n";
    }
    return 0;
}