#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        int ten = 1;
        while (n)
        {
            int dig = n % 10;
            if (dig > 0)
            {
                ans.push_back(dig * ten);
            }
            ten *= 10;
            n /= 10;
        }
        cout << (int) ans.size() << endl;
        for (int i = 0; i < (int) ans.size(); i++)
            cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}