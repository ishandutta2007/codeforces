#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int fl = true;
        int ss = 0;
        int cnt = 0;
        int e = 0;
        for (auto el : s)
        {
            if (el != '0')
            {
                fl = false;
            }
            if (el == '0')
            {
                ++cnt;
            }
            if ((el - '0') % 2 == 0)
            {
                ++e;
            }
            ss += el - '0';
        }
        if (fl)
        {
            cout << "red" << endl;
            continue;
        }
        if (ss % 3 == 0 && e >= 2 && cnt > 0)
        {
            cout << "red" << endl;
        }
        else
        {
            cout << "cyan" << endl;
        }
    }
    return 0;
}