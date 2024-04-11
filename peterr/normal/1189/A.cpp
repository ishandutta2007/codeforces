#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeros++;
        else
            ones++;
    }
    if (zeros != ones)
    {
        cout << 1 << endl;
        cout << s;
    }
    else
    {
        cout << 2 << endl;
        cout << s[0] << " ";
        cout << s.substr(1, s.length() - 1);
    }
    return 0;
}