#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int prefix[MAXN + 1];
int sufMin[MAXN + 1];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            prefix[i] = prefix[i - 1];
        if (s[i] == '(')
            prefix[i]++;
        else
            prefix[i]--;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            sufMin[i] = prefix[i];
        else
            sufMin[i] = min(prefix[i], sufMin[i + 1]);
    }
    /*
    cout << "test" << endl;
    for (int i = 0; i < n; i++)
        cout << prefix[i] << " ";
    cout << endl;
    */
    if (abs(prefix[n - 1]) != 2)
    {
        cout << 0 << endl;
    }
    else
    {
        char key;
        int delta;
        if (prefix[n - 1] == 2)
        {
            key = '(';
            delta = -2;
        }
        else
        {
            key = ')';
            delta = 2;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == key && prefix[i] + delta >= 0 && sufMin[i] + delta >= 0)
            {
                ans++;
            }
            if (prefix[i] < 0)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}