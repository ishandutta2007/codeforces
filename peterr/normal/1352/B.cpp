#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        bool poss = true;
        if (k % 2 == 0 && n % 2 != 0)
            poss = false;
        if (!poss)
        {
            cout << "NO\n";
            continue;
        }
        vector<int> ans;
        if (k % 2 == 0 || n % 2 != 0)
        {
            if (k > n)
            {
                cout << "NO\n";
                continue;
            }
            for (int i = 0; i < k - 1; i++)
            {
                ans.push_back(1);
                n--;
            }
            ans.push_back(n);
        }
        else
        {
            if (2 * k > n)
            {
                cout << "NO\n";
                continue;
            }
            for (int i = 0; i < k - 1; i++)
            {
                ans.push_back(2);
                n -= 2;
            }
            ans.push_back(n);
        }
        cout << "YES\n";
        for (int i = 0; i < k; i++)
            cout << ans[i] << " \n"[i == k - 1];
    }
    return 0;
}