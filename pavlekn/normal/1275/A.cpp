#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        string s;
        cin >> s;
        int n = s.size();
        s.push_back('a');
        s.push_back('a');
        vector<int> used(n);
        for (int i = 0; i < n - 2; ++i)
        {
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
            {
                used[i + 2] = true;
            }
            else
            {
                if (s[i] == 'o' && !used[i] && s[i + 1] == 'n' && s[i + 2] == 'e')
                {
                    used[i + 1] = true;
                }
                if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
                {
                    used[i + 1] = true;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (used[i])
            {
                res.push_back(i + 1);
            }
        }
        cout << res.size() << endl;
        for (auto el : res)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}