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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool valid = true;
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < k; i++)
        {
            int ch = (s[i] == '?' ? -1 : s[i] - '0');
            for (int j = i + k; j < n; j += k)
            {
                if (s[j] == '?')
                    continue;
                if (ch == -1)
                    ch = s[j] - '0';
                else if (ch != s[j] - '0')
                    valid = false;
            }
            if (ch == 0)
                zeros++;
            else if (ch == 1)
                ones++;
        }
        if (!valid)
        {
            cout << "NO\n";
            continue;
        }
        cout << (max(ones, zeros) <= k / 2 ? "YES\n" : "NO\n");
    }
    return 0;
}