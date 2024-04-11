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
        int ptr = 0;
        int ans = 0;
        int n = (int) s.length();
        while (ptr < n && s[ptr] == '0')
            ptr++;
        while (ptr < n)
        {
            while (ptr < n && s[ptr] == '1')
                ptr++;
            int start = ptr;
            while (ptr < n && s[ptr] == '0')
            {
                ptr++;
            }
            if (ptr < n)
            {
                ans += ptr - start;
            }
        }
        cout << ans << endl;
    }
    return 0;
}