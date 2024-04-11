#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
bool ans[MAXN];

bool isValid(int ind, int n)
{
    return ind >= 0 && ind < n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int x;
        cin >> s >> x;
        int n = (int) s.length();
        fill(ans, ans + n, true);
        for (int i = 0; i < x; i++)
        {
            for (int j = i; j < n; j += x)
            {
                if (s[j] == '0')
                {
                    if (isValid(j - x, n))
                        ans[j - x] = false;
                    if (isValid(j + x, n))
                        ans[j + x] = false;
                }
            }
        }
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                continue;
            bool found = false;
            if (isValid(i + x, n) && ans[i + x])
                found = true;
            if (isValid(i - x, n) && ans[i - x])
                found = true;
            if (!found)
                valid = false;
        }
        if (valid)
        {
            for (int i = 0; i < n; i++)
                cout << ans[i];
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}