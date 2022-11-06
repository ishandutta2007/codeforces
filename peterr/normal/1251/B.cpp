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
        bool hasOddLen = false;
        bool onePar = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if ((int) s.length() % 2 == 1)
                hasOddLen = true;
            for (int j = 0; j < (int) s.length(); j++)
            {
                if (s[j] == '1')
                    onePar = !onePar;
            }
        }
        if (hasOddLen)
            cout << n << endl;
        else if (onePar)
            cout << n - 1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}