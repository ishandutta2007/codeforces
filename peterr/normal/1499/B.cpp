#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool change = false;
        bool prev = false;
        bool ans = true;
        int n = (int) s.length();
        for (int i = 0; i < n; i++)
        {
            if (change && s[i] == '0' && prev)
                ans = false;
            if (prev)
            {
                prev = false;
                if (s[i] == '1')
                    change = true;
                continue;
            }
            if (!change && s[i] == '1')
            {
                prev = true;
                continue;
            }
            if (change && s[i] == '0')
            {
                prev = true;
                continue;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}