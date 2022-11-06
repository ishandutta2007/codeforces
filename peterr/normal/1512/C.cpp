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
        int a, b;
        string s;
        cin >> a >> b >> s;
        for (char ch : s)
        {
            if (ch == '0')
                a--;
            else if (ch == '1')
                b--;
        }
        int n = (int) s.length();
        bool valid = true;
        for (int i = 0; i < n / 2; i++)
        {
            int j = n - i - 1;
            if (s[j] != '?' && s[i] != '?')
            {
                if (s[j] != s[i])
                    valid = false;
                continue;
            }
            if (s[i] == '?' && s[j] == '?')
            {
                continue;
            }
            else if (s[i] == '?')
            {
                s[i] = s[j];
                if (s[i] == '0')
                    a--;
                else
                    b--;
            }
            else
            {
                s[j] = s[i];
                if (s[i] == '0')
                    a--;
                else
                    b--;
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            int j = n - i - 1;
            if (s[i] == '?')
            {
                if (a > b)
                {
                    a -= 2;
                    s[i] = s[j] = '0';
                }
                else
                {
                    b -= 2;
                    s[i] = s[j] = '1';
                }
            }
        }
        if ((n & 1) && s[n / 2] == '?')
        {
            if (a > b)
            {
                a--;
                s[n / 2] = '0';
            }
            else
            {
                b--;
                s[n / 2] = '1';
            }
        }
        if (a < 0 || b < 0)
            valid = false;
        if (!valid)
            cout << "-1\n";
        else
            cout << s << "\n";
    }
    return 0;
}