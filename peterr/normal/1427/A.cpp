#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> pos;
        vector<int> neg;
        int zeros = 0;
        int n;
        cin >> n;
        int bal = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (!x)
            {
                zeros++;
            }
            else if (x > 0)
            {
                pos.push_back(x);
            }
            else
            {
                neg.push_back(x);
            }
            bal += x;
        }
        if (zeros == n || bal == 0)
        {
            cout << "NO\n";
        }
        else
        {
            vector<int> ans;
            for (int x : pos)
                ans.push_back(x);
            for (int x : neg)
                ans.push_back(x);
            if (bal < 0)
                reverse(ans.begin(), ans.end());
            for (int i = 0; i < zeros; i++)
                ans.push_back(0);
            cout << "YES\n";
            for (int i = 0; i < (int) ans.size(); i++)
            {
                cout << ans[i] << " \n"[i == (int) ans.size() - 1];
            }
        }
    }
    return 0;
}