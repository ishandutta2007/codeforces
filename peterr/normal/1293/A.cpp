#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unordered_set<int> s;
        s.reserve(1000);
        int n, ss, k;
        cin >> n >> ss >> k;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int ans = 1E9;
        for (int i = ss; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                ans = min(ans, i - ss);
                break;
            }
        }
        for (int i = ss; i >= 1; i--)
        {
            if (s.find(i) == s.end())
            {
                ans = min(ans, ss - i);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}