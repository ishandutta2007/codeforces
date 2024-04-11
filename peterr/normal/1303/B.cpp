#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, g, b;
        cin >> n >> g >> b;
        long long ans = n;
        int half = (n + 1) / 2;
        int full = half / g;
        if (half % g == 0)
        {
            full--;
            ans = (long long) full * (g + b) + g;
        }
        else
            ans = (long long) full * (g + b) + half % g;
        ans = max(ans, (long long) n);
        cout << ans << endl;
    }
    return 0;
}