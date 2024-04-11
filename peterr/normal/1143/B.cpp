#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < s.length(); i++)
    {
        ans *= stoi(s.substr(i, 1));
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            continue;
        int temp = 1;
        for (int j = 0; j < s.length(); j++)
        {
            if (j < i)
            {
                temp *= stoi(s.substr(j, 1));
            }
            else if (j == i)
            {
                if (i != 0 || s[i] != '1')
                    temp *= stoi(s.substr(j, 1)) - 1;
            }
            else
            {
                temp *= 9;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}