#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    while (!s.empty())
    {
        int pos = -1;
        char ch = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((i > 0 && s[i - 1] + 1 == s[i]) || (i < s.size() - 1 && s[i + 1] + 1 == s[i]))
            {
                if (ch < s[i])
                {
                    ch = s[i];
                    pos = i;
                }
            }
        }
        if (pos == -1)
        {
            break;
        }
        else
        {
            ++ans;
            string t;
            for (int i = 0; i < s.size(); ++i)
            {
                if (i != pos)
                {
                    t.push_back(s[i]);
                }
            }
            s = t;
        }
    }
    cout << ans << endl;
    return 0;
}