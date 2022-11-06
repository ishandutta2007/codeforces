#include <bits/stdc++.h>

using namespace std;

bool good[26];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        fill(good, good + 26, false);
        for (int i = 0; i < (int) s.length();)
        {
            char c = s[i];
            int j = i;
            while (j < (int) s.length() && s[j] == c)
            {
                j++;
            }
            if ((j - i) % 2 == 1)
            {
                good[c - 'a'] = true;
            }
            i = j;
        }
        for (int i = 0; i < 26; i++)
        {
            if (good[i])
                cout << (char) ('a' + i);
        }
        cout << endl;
    }
    return 0;
}