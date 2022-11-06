#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.length() == 2 && s[0] < s[1] || s.length() > 2)
        {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " " << s.substr(1, s.length() - 1) << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}