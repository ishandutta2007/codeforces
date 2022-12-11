#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        string s, t, p;
        cin >> s >> t >> p;
        map<char, int> need;
        map<char, int> can;
        for (auto el : p)
        {
            ++can[el];
        }
        int j = 0;
        int fl = true;
        for (int i = 0; i < s.size(); ++i)
        {
            while (j < t.size() && t[j] != s[i])
            {
                need[t[j]]++;
                ++j;
            }
            if (j >= t.size())
            {
                fl = false;
                cout << "No" << endl;
                break;
            }
            ++j;
            if (i + 1 == s.size())
            {
                while (j < t.size())
                {
                    ++need[t[j]];
                    ++j;
                }
            }
        }
        if (!fl)
        {
            continue;
        }
        for (auto el : t)
        {
            if (need[el] > can[el])
            {
                cout << "No" << endl;
                fl = false;
                break;
            }
        }
        if (!fl)
        {
            continue;
        }
        cout << "Yes" << endl;
    }
}