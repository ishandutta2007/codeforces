#include <bits/stdc++.h>

using namespace std;

bool check(string s)
{
    int n = (int) s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
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
        cin >> s;
        if (!check("a" + s))
            cout << "YES\na" << s << "\n";
        else if (!check(s + "a"))
            cout << "YES\n" << s << "a\n";
        else
            cout << "NO\n";
    }
    return 0;
}