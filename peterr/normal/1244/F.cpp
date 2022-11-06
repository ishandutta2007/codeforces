#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
bool stable[MAXN];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool isPattern = n % 2 == 0 && s[0] != s[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            isPattern = false;
    }
    if (isPattern || s.find("W") == string::npos || s.find("B") == string::npos)
    {
        if (k % 2 == 0)
            cout << s << endl;
        else
            cout << s.substr(1) << s[0] << endl;
    }
    else
    {
        int ptr = 0;
        while (s[ptr] != s[(ptr + 1) % n])
            ptr = (ptr + 1) % n;
        while (s[ptr] == s[(ptr - 1 + n) % n])
            ptr = (ptr - 1 + n) % n;
        int start = ptr;
        stable[ptr] = true;
        ptr = (ptr + 1) % n;
        while (ptr != start)
        {
            while (ptr != start && s[ptr] == s[(ptr - 1 + n) % n])
            {
                stable[ptr] = true;
                ptr = (ptr + 1) % n;
            }
            if (ptr != start)
            {
                if (s[ptr] != s[(ptr + 1) % n])
                {
                    int j = ptr;
                    int cnt = 0;
                    while (s[j] != s[(j + 1) % n])
                    {
                        cnt++;
                        j = (j + 1) % n;
                    }
                    if (k % 2 == 1)
                    {
                        for (int i = ptr; i != j; i = (i + 1) % n)
                        {
                            if (s[i] == 'W')
                                s[i] = 'B';
                            else
                                s[i] = 'W';
                        }
                    }
                    int amt = min((cnt + 1) / 2, k);
                    for (int i = 0; i < amt; i++)
                    {
                        s[(ptr + i) % n] = s[(ptr - 1 + n) % n];
                    }
                    for (int i = 1; i <= amt; i++)
                    {
                        s[(j - i + n) % n] = s[j];
                    }
                    if (j == start)
                        break;
                    ptr = (j + 1) % n;
                }
                else
                {
                    ptr = (ptr + 1) % n;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}