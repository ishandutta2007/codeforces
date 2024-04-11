#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool raze = false;
        if (n & 1)
        {
            for (int i = 0; i < n; i += 2)
            {
                int key = s[i] - '0';
                if (key & 1)
                    raze = true;
            }
        }
        else
        {
            raze = true;
            for (int i = 1; i < n; i += 2)
            {
                int key = s[i] - '0';
                if (!(key & 1))
                    raze = false;
            }
        }
        if (raze)
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}