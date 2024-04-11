#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int a[26];

int main()
{
    string s;
    cin >> s;
    if (s.size() < 26)
    {
        cout << -1;
        return 0;
    }
    int num = 0;
    for (int i = 0; i < 26; i++)
    {
        if (s[i] == '?')
            continue;
        a[s[i] - 'A']++;
        if (a[s[i] - 'A'] == 2)
        {
            num++;
         //   cout << s[i] << " +" << endl;
        }
    }
    for (int i = 25; i < s.size(); i++)
    {
      /*  if (i == s.size() - 1)
        {
            cout << num << " ";
            for (int i = 0; i < 26; i++)
                if (a[i] > 1)
                {
                    char c = ('A' + i);
                    cout << c << " ";
                }
        }*/
        if (num == 0)
        {
            int j = 0;
            for (int k = i - 25; k <= i; k++)
                if (s[k] == '?')
                {
                    while (a[j] > 0)
                        j++;
                    s[k] = (j + 'A');
                    j++;
                }
            for (int k = 0; k < s.size(); k++)
                if (s[k] == '?')
                    s[k] = 'A';
            cout << s;
            return 0;
        }
        if (s[i - 25] != '?')
        {
            a[s[i - 25] - 'A']--;
            if (a[s[i - 25] - 'A'] == 1)
            {
                num--;
             //   cout << s[i] << " -" << endl;
            }
        }
        if (i + 1 != s.size() && s[i + 1] != '?')
        {
            a[s[i + 1] - 'A']++;
            if (a[s[i + 1] - 'A'] == 2)
            {
                num++;
             //   cout << s[i] << " +" << endl;
            }
        }
    }
    cout << -1;
    return 0;
}