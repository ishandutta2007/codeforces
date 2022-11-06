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
        int n, m;
        cin >> n >> m;
        bool sym = false;
        for (int i = 0; i < n; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b == c)
                sym = true;
        }
        if (m & 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << (sym ? "YES\n" : "NO\n");
        }
    }
    return 0;
}