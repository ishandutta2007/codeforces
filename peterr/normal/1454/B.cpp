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
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (m.count(x))
                m[x] = -1;
            else
                m[x] = i + 1;
        }
        int ans = -1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second != -1)
            {
                ans = it->second;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}