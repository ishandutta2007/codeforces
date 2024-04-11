#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int bit = 0;
        while (n >= (1 << (bit + 1)) - 1)
            bit++;
        int base = (1 << bit) - 1;
        int extra = n - base;
        vector<int> ans;
        for (int i = 0; i < bit; i++)
        {
            if (extra > 0 && (extra <= (1 << i)))
            {
                ans.push_back(extra);
                extra = 0;
            }
            ans.push_back(1 << i);
        }
        if (extra)
            ans.push_back(extra);
        cout << (int) ans.size() - 1 << "\n";
        for (int i = 1; i < (int) ans.size(); i++)
            cout << ans[i] - ans[i - 1] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}