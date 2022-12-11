#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, 1e9);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int c = 0;
        int fl = 1;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == '(')
            {
                ++c;
            }
            else
            {
                --c;
            }
            if (c < 0)
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            a[i] = c;
        }
        c = 0;
        fl = 1;
        for (int j = s.size() - 1; j >= 0; --j)
        {
            if (s[j] == ')')
            {
                ++c;
            }
            else
            {
                --c;
            }
            if (c < 0)
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            a[i] = -c;
        }
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    int j = a.size() - 1;
    while (j > i && a[i] <= 0 && a[j] >= 0)
    {
        if (abs(a[j]) > abs(a[i]))
        {
            --j;
        }
        else if (abs(a[j]) < abs(a[i]))
        {
            ++i;
        }
        else
        {
            ++ans;
            ++i;
            --j;
        }
    }
    cout << ans << endl;
    return 0;
}