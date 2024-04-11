#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int w = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'v' && s[i - 1] == 'v')
            w++;
    }
    int index = 0;
    int countt = 0;
    long long ans = 0;
    while (index < s.length())
    {
        if (s[index] == 'o')
        {
            ans += (long long) countt * (w - countt);
        }
        else
        {
            if (index > 0 && s[index - 1] == 'v')
            {
                countt++;
            }
        }
        index++;
    }
    cout << ans << endl;
    return 0;
}