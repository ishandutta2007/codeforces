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
        string s;
        cin >> s;
        int n = (int) s.length();
        int ans = 0;
        bool changedOne = false;
        bool changedTwo = false;
        for (int i = 1; i < n; i++)
        {
            bool change = false;
            if (i - 1 >= 0 && !changedOne && s[i] == s[i - 1])
                change = true;
            else if (i - 2 >= 0 && !changedTwo && s[i] == s[i - 2])
                change = true;
            ans += change;
            changedTwo = changedOne;
            changedOne = change;
        }
        cout << ans << "\n";
    }
    return 0;
}