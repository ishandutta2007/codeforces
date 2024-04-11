#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (s.count(x))
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}