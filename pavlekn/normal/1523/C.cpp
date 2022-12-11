#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> used(n);
        string cur = "";
        vector<string> ans(n);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1)
            {
                if (cur == "")
                {
                    ans[i] = "1";
                }
                else
                {
                    ans[i] = cur + ".1";
                }
                cur = ans[i];
            }
            else
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (!used[j] && a[i] == a[j] + 1)
                    {
                        used[j] = true;
                        int r = 0;
                        for (int k = ans[j].size() - 1; k >= 0; --k)
                        {
                            if (ans[j][k] == '.')
                            {
                                r = k;
                                break;
                            }
                        }
                        for (int k = 0; k < r; ++k)
                        {
                            ans[i].push_back(ans[j][k]);
                        }
                        if (!ans[i].empty())
                        {
                            ans[i].push_back('.');
                        }
                        vector<char> tt;
                        int mm = a[i];
                        while (mm > 0)
                        {
                            tt.push_back('0' + mm % 10);
                            mm /= 10;
                        }
                        reverse(tt.begin(), tt.end());
                        for (auto el : tt)
                        {
                            ans[i].push_back(el);
                        }
                        cur = ans[i];
                        break;
                    }
                    used[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}