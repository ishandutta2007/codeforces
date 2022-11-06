#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int ans = (int) a.length() + (int) b.length();
        for (int len = 1; len <= (int) min(a.length(), b.length()); len++)
        {
            for (int i = 0; i + len <= (int) a.length(); i++)
            {
                for (int j = 0; j + len <= (int) b.length(); j++)
                {
                    if (a.substr(i, len) == b.substr(j, len))
                        ans = min(ans, (int) a.length() + (int) b.length() - 2 * len);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}