#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int len = s.size();
        for (int i = 0; i < x; ++i)
        {
            if (s.size() < x)
            {
                for (int j = 0; j < s[i] - '1'; ++j)
                {
                    for (int k = i + 1; k < len; ++k)
                    {
                        s.push_back(s[k]);
                    }
                }
            }
            len += (s[i] - '1') * (len - i - 1);
            len %= mod;
            len += mod;
            len %= mod;
        }
        cout << len << endl;
    }
    return 0;
}