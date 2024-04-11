#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        s = "##" + s + "##";

        int ans = 0;
        for (int i = 2; i + 2 < s.size(); i++)
        {
            if (s[i] == s[i - 1] || s[i] == s[i - 2])
            {
                ans++;
                for (char val = 'a'; val <= 'z'; val++)
                {
                    if (val != s[i - 1] && val != s[i - 2] && val != s[i + 1] && val != s[i + 2])
                    {
                        s[i] = val;
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}