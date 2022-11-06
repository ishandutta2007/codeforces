#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            sum++;
        else
            sum--;
    }
    if (sum != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int bal = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
        {
            int right = i + 1;
            while (bal < 0)
            {
                if (s[right] == '(')
                    bal++;
                else
                    bal--;
                right++;
            }
            ans += right - i;
            i = right - 1;
        }
    }
    cout << ans << endl;
    return 0;
}