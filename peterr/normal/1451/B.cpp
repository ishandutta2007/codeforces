#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        string s;
        cin >> n >> q >> s;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            bool ans = false;
            for (int i = 0; i < l; i++)
            {
                if (s[i] == s[l])
                    ans = true;
            }
            for (int i = r + 1; i < n; i++)
            {
                if (s[i] == s[r])
                    ans = true;
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}