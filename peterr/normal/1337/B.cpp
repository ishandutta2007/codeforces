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
        int x, n, m;
        cin >> x >> n >> m;
        bool ans = false;
        for (int i = 0; i <= n; i++)
        {
            if (x <= 10 * m)
                ans = true;
            x = x / 2 + 10;
        }
        if (ans)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}