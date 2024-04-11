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
        bool same = true;
        for (int i = 1; i < (int) s.length(); i++)
            if (s[i] != s[0])
                same = false;
        if (same)
            cout << s << endl;
        else
        {
            stringstream ss;
            for (int i = 0; i < (int) s.length(); i++)
                ss << "01";
            cout << ss.str() << endl;
        }
    }
    return 0;
}