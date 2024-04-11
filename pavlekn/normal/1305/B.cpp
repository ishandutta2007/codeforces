#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> used(n);
    vector<int> ans;
    while (true)
    {
        int fl = false;
        int l = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i] && s[i] == '(')
            {
                l = i;
                break;
            }
        }
        if (l == -1)
        {
            break;
        }
        int r = -1;
        for (int i = n - 1; i > l; --i)
        {
            if (!used[i] && s[i] == ')')
            {
                r = i;
                break;
            }
        }
        if (r == -1)
        {
            break;
        }
        used[l] = true;
        used[r] = true;
        ans.push_back(l + 1);
        ans.push_back(r + 1);
    }
    if (ans.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}