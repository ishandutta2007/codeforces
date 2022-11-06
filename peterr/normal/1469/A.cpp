#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int) s.length();
        if (n & 1)
            cout << "NO\n";
        else
        {
            if (s[0] != ')' && s[n - 1] != '(')
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}