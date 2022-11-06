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
        int n, u, v;
        cin >> n >> u >> v;
        int first;
        cin >> first;
        bool same = true;
        int prev = first;
        bool valid = true;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            if (abs(x - prev) >= 2)
            {
                valid = false;
            }
            if (x != first)
                same = false;
            prev = x;
        }
        if (!valid)
            cout << "0\n";
        else if (!same)
            cout << min(u, v) << "\n";
        else
            cout << v + min(u, v) << "\n";
    }
    return 0;
}