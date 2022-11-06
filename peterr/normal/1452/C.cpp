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
        string s;
        cin >> s;
        int open1 = 0;
        int open2 = 0;
        int ans = 0;
        for (int i = 0; i < (int) s.length(); i++)
        {
            if (s[i] == '(')
            {
                open1++;
            }
            else if (s[i] == '[')
            {
                open2++;
            }
            else if (s[i] == ')' && open1)
            {
                open1--;
                ans++;
            }
            else if (s[i] == ']' && open2)
            {
                open2--;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}