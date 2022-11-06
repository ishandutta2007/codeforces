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
        int length = (int) s.length();
        vector<int> vals;
        int ptr = 0;
        while (ptr < length)
        {
            while (ptr < length && s[ptr] == '0')
                ptr++;
            if (ptr < length)
            {
                int cnt = 0;
                while (ptr < length && s[ptr] == '1')
                {
                    cnt++;
                    ptr++;
                }
                vals.push_back(cnt);
            }
        }
        sort(vals.rbegin(), vals.rend());
        int ans = 0;
        for (int i = 0; i < (int) vals.size(); i += 2)
        {
            ans += vals[i];
        }
        cout << ans << "\n";
    }
    return 0;
}