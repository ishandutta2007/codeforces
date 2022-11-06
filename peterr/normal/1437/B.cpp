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
        string s;
        cin >> n >> s;
        for (int i = 1; i < n; i += 2)
        {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        int ans = 0;
        int ptr = 1;
        while (ptr < n)
        {
            if (s[ptr] != s[0])
            {
                ans++;
                while (ptr < n && s[ptr] != s[0])
                    ptr++;
            }
            else
                ptr++;
        }
        cout << ans << "\n";
    }
    return 0;
}