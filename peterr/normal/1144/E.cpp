#include <bits/stdc++.h>

using namespace std;

int k;
string s, t;

void fixTie(int i)
{
    if (i < k)
    {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if (a + b == 25)
        {
            fixTie(i + 1);
            int c = s[i + 1] - 'a';
            int d = t[i + 1] - 'a';
            if (c + d >= 26)
            {
                if (a != 25)
                    a++;
                else
                    b++;
                c -= 26 - d;
                d = 0;
            }
            else
            {
                if (a != 0)
                    a--;
                else
                    b--;
                c += 26 - (25 - d);
                d = 25;
            }
            s[i] = 'a' + a;
            t[i] = 'a' + b;
            s[i + 1] = 'a' + c;
            t[i + 1] = 'a' + d;
        }
    }
}

int main()
{
    cin >> k >> s >> t;
    for (int i = 0; i < k; i++)
    {
        if (abs(s[i] - t[i]) % 2 == 0)
        {
            s[i] = (char) ((s[i] + t[i]) / 2);
            t[i] = (char) ((s[i] + t[i]) / 2);
        }
        else
        {
            fixTie(i + 1);
            int med;
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            int c = s[i + 1] - 'a';
            int d = t[i + 1] - 'a';
            if (c + d >= 26)
            {
                med = (a + b) / 2 + 1;
                c -= 26 - d;
                d = 0;
            }
            else
            {
                med = (a + b) / 2;
                c += 26 - (25 - d);
                d = 25;
            }
            s[i] = med + 'a';
            t[i] = med + 'a';
            s[i + 1] = c + 'a';
            t[i + 1] = d + 'a';
        }
    }
    cout << s << endl;
    return 0;
}